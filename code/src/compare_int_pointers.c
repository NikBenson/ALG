#include "compare_int_pointers.h"

int compareIntPointers(const int *a, const int *b) {
    if (*a == *b)
        return 0;
    else if (*a > *b)
        return -1;
    else
        return 1;
}

