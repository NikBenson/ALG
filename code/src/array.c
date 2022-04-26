#include <printf.h>
#include "array.h"

unsigned long arrayLength(Array array) {
    long length = 1 + (array.end - array.start);

    if(length < 0) {
        return 0;
    }

    return length;
}

void printArray(const Array array) {
    traverseArray(array, printNumbers);
    printf("\b\b\n");
}

void traverseArray(const Array array, void (*fn)(const int *value)) {
    for (int *element = array.start; element <= array.end; ++element)
        fn(element);
}

void printNumbers(const int *current) {
    printf("%d, ", *current);
}
