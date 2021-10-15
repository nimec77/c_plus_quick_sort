//
// Created by comrade77 on 15.10.2021.
//

#ifndef C_PLUS_QUICK_SORT_QUICK_SORT_H
#define C_PLUS_QUICK_SORT_QUICK_SORT_H

#include <algorithm>
#include <future>
#include <list>

namespace quick {
    template<typename T>
    std::list<T> SequentialQuickSort(std::list<T> input) {
        if (input.empty()) {
            return input;
        }
        std::list<T> result;
        result.splice(result.begin(), input, input.begin());
        const auto pivot = *result.begin();

        auto divide_point = std::partition(input.begin(), input.end(), [&](const auto t) { return t < pivot; });
        std::list<int> lower_part;
        lower_part.splice(lower_part.end(), input, input.begin(), divide_point);
        auto new_lower(SequentialQuickSort(std::move(lower_part)));
        auto new_higher(SequentialQuickSort(std::move(input)));
        result.splice(result.end(), new_higher);
        result.splice(result.begin(), new_lower);

        return result;
    }

    template<typename T>
    std::list<T> ParallelQuickSort(std::list<T> input) {
        if (input.empty()) {
            return input;
        }
        std::list<T> result;
        result.splice(result.begin(), input, input.begin());
        const auto pivot = *result.begin();

        auto divide_point = std::partition(input.begin(), input.end(), [&](const auto t) { return t < pivot; });
        std::list<T> lower_part;
        lower_part.splice(lower_part.end(), input, input.begin(), divide_point);
        std::future<std::list<T>> new_lower(
                std::async(&ParallelQuickSort<T>, std::move(lower_part)));
        auto new_higher(ParallelQuickSort(std::move(input)));
        result.splice(result.end(), new_higher);
        result.splice(result.begin(), new_lower.get());

        return result;
    }

}// namespace quick

#endif//C_PLUS_QUICK_SORT_QUICK_SORT_H
