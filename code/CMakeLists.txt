cmake_minimum_required(VERSION 3.21)
project(code C)

set(CMAKE_C_STANDARD 99)

add_executable(code src/main.c src/quicksort/quicksort.c src/quicksort/quicksort.h src/samplesort/samplesort.c src/samplesort/samplesort.h src/int_tools.c src/int_tools.h src/samplesort/select_splitters.c src/samplesort/select_splitters.h src/samplesort/choose_sample/choose_sample.h src/array.h src/quicksort/partition.c src/quicksort/partition.h src/comparator.h src/swap.h src/samplesort/choose_sample/block.c src/samplesort/choose_sample/block.h src/samplesort/place_elements_in_corresponding_bucket.c src/samplesort/place_elements_in_corresponding_bucket.h src/samplesort/choose_sample/even.c src/samplesort/choose_sample/even.h src/samplesort/choose_sample/semi_random.c src/samplesort/choose_sample/semi_random.h src/samplesort/choose_sample/random.c src/samplesort/choose_sample/random.h src/sort.h src/array.c src/samplesort/configuration.h)
