cmake_minimum_required(VERSION 4.0)
project(TP3 C)

set(CMAKE_C_STANDARD 23)

add_compile_options(-O3)
include_directories(include/)

add_executable(TP3
        src/main.c
        src/auxiliary/tests.c
        src/auxiliary/t_time.c
        src/structures/array.c
        src/structures/algorithm.c
        src/algorithms/selection_sort.c
        src/algorithms/insertion_sort.c
        src/algorithms/bubble_sort.c
        src/algorithms/quick_sort.c
        src/algorithms/merge_sort.c
)
