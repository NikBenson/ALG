#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "samplesort/samplesort.h"
#include "int_tools.h"
#include "quicksort/quicksort.h"
#include "samplesort/choose_sample/even.h"

#define ARR_LENGTH 5

void traverseArray(const Array array, void (*fn)(const int *value)) {
    for (int *element = array.start; element <= array.end; ++element)
        fn(element);
}

Array readNumbersFromStdIn(unsigned int maxSize) {
    int *first = calloc(maxSize, sizeof(int));
    for (int i = 0; i < maxSize; ++i) {
        int result = scanf(" %d ", first + i);
        if (result == EOF)
            return (Array) {first, first + i - 1};
    }
    return (Array) {first, first + maxSize - 1};
}

bool isSorted = true;
const int *lastNumber = NULL;

void printNumbers(const int *current) {
    printf("%d, ", *current);
}

void checkIfSorted(const int *current) {
    printNumbers(current);

    if (lastNumber != NULL) {
        if (*lastNumber > *current)
            isSorted = false;
    }
    lastNumber = current;
}

int main() {
    Array numbers = readNumbersFromStdIn(ARR_LENGTH);

    traverseArray(numbers, printNumbers);
    printf("\b\b\n");

    sampleSort(numbers,
               (SampleSortConfiguration) {1,
                                          2,
                                          1,
                                          quicksort,
                                          compareIntPointers,
                                          swapInts,
                                          chooseSampleEven});

    traverseArray(numbers, checkIfSorted);
    printf("\b\b\n%s\n", isSorted ? "SUCCESS" : "FAILED");

    return 0;
}
