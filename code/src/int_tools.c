#include "int_tools.h"

unsigned long comparisons = 0;

int compareIntPointers(const int *a, const int *b) {
    comparisons++;
    if (*a == *b)
        return 0;
    else if (*a > *b)
        return 1;
    else
        return -1;
}

void swapInts(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
