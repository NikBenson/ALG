cmake_minimum_required(VERSION 3.21)
project(code C)

set(CMAKE_C_STANDARD 99)

add_executable(code src/main.c src/quicksort/quicksort.c src/quicksort/quicksort.h src/samplesort/samplesort.c src/samplesort/samplesort.h src/compare_int_pointers.c src/compare_int_pointers.h src/samplesort/select_splitters.c src/samplesort/select_splitters.h src/samplesort/choose_sample/choose_sample.h src/array.h src/quicksort/divide_data_from_pivot.c src/quicksort/divide_data_from_pivot.h src/comparator.h src/swap.h src/samplesort/choose_sample/block.c src/samplesort/choose_sample/block.h)
