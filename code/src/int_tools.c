#include "int_tools.h"

int compareIntPointers(const void *a, const void *b) {
    if (*(int*)a == *(int*)b)
        return 0;
    else if (*(int*)a > *(int*)b)
        return 1;
    else
        return -1;
}

void swapInts(void* a, void* b) {
    int temp = *(int*) a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;
}
