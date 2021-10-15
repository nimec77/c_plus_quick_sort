cmake_minimum_required(VERSION 3.20)
project(c_plus_quick_sort)

set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_CXX_FLAGS -pthread)

include_directories(src)

set(SRC_LIST
        main.cpp
        )

add_executable(${PROJECT_NAME} ${SRC_LIST})
