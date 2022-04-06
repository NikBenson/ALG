#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "samplesort.h"

#define ARR_LENGTH 8500

void traverseArray(void *from, void *to, void(*fn)(void *value)) {
    for (; from < to; ++from)
        fn(from);
}

int *readNumbersFromStdIn(unsigned int maxLength) {
    int *numbers = malloc(sizeof(int) * maxLength);

    for (int i = 0; i < ARR_LENGTH; ++i) {
        if (scanf("%d ", numbers + i) == EOF)
            break;
    }

    return 0;
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
    int *numbers = readNumbersFromStdIn(ARR_LENGTH);

    sampleSort(numbers, ARR_LENGTH, 1, 5, 5);

    traverseArray(numbers, numbers + ARR_LENGTH - 1, (void (*)(void *)) &checkIfSorted);
    printf("\b\b\n%s\n", isSorted ? "SUCCESS" : "FAILED");

    return 0;
}
