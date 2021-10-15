#include <iostream>
#include <list>
#include <quick_sort.h>
#include <random>

const auto RandomNumberBetween = [](int low, int high) {
    auto random_func = [_distribution = std::uniform_int_distribution<int>(low, high),
                        _random_engine = std::mt19937{std::random_device{}()}]() mutable {
        return _distribution(_random_engine);
    };
    return random_func;
};

int main() {
    std::cout << "Start Sequential Quick Sort" << std::endl;
    std::list<int> numbers;
    std::generate_n(std::back_inserter(numbers), 1000, RandomNumberBetween(1, 1000));
    auto number_end = std::next(numbers.begin(), 10);
    std::list<int> numbers_print{numbers.begin(), number_end};

    for (int number : numbers_print) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;

    const auto sorted = quick::ParallelQuickSort(numbers);
    auto sorted_end = std::next(sorted.begin(), 10);
    std::list<int> sorted_print{sorted.begin(), sorted_end};
    for (int number : sorted_print) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;

    return 0;
}
