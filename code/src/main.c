#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "samplesort/samplesort.h"
#include "int_tools.h"
#include "quicksort/quicksort.h"
#include "samplesort/select_splitters.h"
#include "samplesort/choose_sample/even.h"

#define ARR_LENGTH 1000000

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
void checkIfSorted(const int *current) {
    printNumbers(current);

    if (lastNumber != NULL) {
        if (*lastNumber > *current)
            isSorted = false;
    }
    lastNumber = current;
}

int main() {
    srandomdev();

    Array numbers = readNumbersFromStdIn(ARR_LENGTH);

    printArray(numbers);

    SampleSortConfiguration configuration = {
            128,
            15,
            256,
            quicksort,
            compareIntPointers,
            swapInts,
            chooseSampleEven,
            };

    sampleSort(numbers, configuration);

    traverseArray(numbers, checkIfSorted);

    printf("\b\b\n%s\n", isSorted ? "SUCCESS" : "FAILED");
    printf("C=%lu, n=%lu", comparisons, arrayLength(numbers));

    return 0;
}
