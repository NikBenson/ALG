#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "samplesort/samplesort.h"
#include "compare_int_pointers.h"
#include "quicksort/quicksort.h"
#include "samplesort/choose_sample/even.h"

#define ARR_LENGTH 8500

void traverseArray(const Array array, void(*fn)(void *value)) {
    for (void *element = array.start; element <= array.end; ++element)
        fn(element);
}

Array readNumbersFromStdIn(unsigned int maxLength) {
    int *allocatedMemory = malloc(sizeof(int) * maxLength);
    Array numbers = {allocatedMemory, allocatedMemory + maxLength - 1};

    for (int i = 0; i < ARR_LENGTH; ++i) {
        if (scanf("%d ", numbers.start + i) == EOF)
            break;
    }

    return numbers;
}

bool isSorted = true;
int *last = NULL;

void checkIfSorted(int *current) {
    printf("%d, ", *current);

    if (last != NULL) {
        if (*last < *current)
            isSorted = false;
    }
    last = current;
}

int main() {
    Array numbers = readNumbersFromStdIn(ARR_LENGTH);

    sampleSort(numbers,
               (SampleSortConfiguration) {1,
                                          5,
                                          5,
                                          quicksort,
                                          (Comparator) compareIntPointers,
                                          chooseSampleEven});

    traverseArray(numbers, (void (*)(void *)) &checkIfSorted);
    printf("\b\b\n%s\n", isSorted ? "SUCCESS" : "FAILED");

    return 0;
}
