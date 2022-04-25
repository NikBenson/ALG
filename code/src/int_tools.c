#include "int_tools.h"

int compareIntPointers(const int *a, const int *b) {
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
