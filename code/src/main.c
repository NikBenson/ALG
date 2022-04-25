#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "samplesort/samplesort.h"
#include "int_tools.h"
#include "quicksort/divide_data_from_pivot.h"
#include "quicksort/quicksort.h"

#define ARR_LENGTH 20

void traverseArray(const Array array, void (*fn)(const void *value)) {
    for (void *element = array.start; element <= array.end; ++element)
        fn(element);
}

Array readNumbersFromStdIn(unsigned int maxSize) {
    int *first = calloc(maxSize, sizeof(int));
    for (int *number = first; number < first + maxSize; ++number) {
        int result = scanf("%d ", number);
        if (result == EOF)
            return (Array) {first, number - 1};
    }
    return (Array) {first, first + maxSize - 1};
}

bool isSorted = true;
const int *lastNumber = NULL;

void printNumbers(const void *current) {
    printf("%d, ", *(int *) current);
}

void checkIfSorted(const void *current) {
    printNumbers(current);

    if (lastNumber != NULL) {
        if (*lastNumber > *(int *) current)
            isSorted = false;
    }
    lastNumber = current;
}

int main() {
    Array numbers = readNumbersFromStdIn(ARR_LENGTH);
    numbers.end = numbers.start + 2;
    ((int*)numbers.start)[0] = 1;
    ((int*)numbers.start)[1] = 17;
    ((int*)numbers.start)[2] = 4;
    ((int*)numbers.start)[3] = 12;
    ((int*)numbers.start)[4] = 3;

    traverseArray(numbers, printNumbers);
    printf("\b\b\n");

    /*sampleSort(numbers,
               (SampleSortConfiguration) {1,
                                          5,
                                          5,
                                          quicksort,
                                          (Comparator) compareIntPointers,
                                          chooseSampleEven});*/


    //divideDataFromPivot(numbers, numbers.end, compareIntPointers, swapInts);

    quicksort(numbers, compareIntPointers, swapInts);

    traverseArray(numbers, checkIfSorted);
    printf("\b\b\n%s\n", isSorted ? "SUCCESS" : "FAILED");

    return 0;
}
