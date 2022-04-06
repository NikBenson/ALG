cmake_minimum_required(VERSION 3.21)
project(code C)

set(CMAKE_C_STANDARD 99)

add_executable(code main.c quicksort.c quicksort.h samplesort.c samplesort.h compare_int_pointers.c compare_int_pointers.h select_splitters.c select_splitters.h find_bucket_index_for_value_by_binary_search.cpp find_bucket_index_for_value_by_binary_search.h)
