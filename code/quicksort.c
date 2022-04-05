#include "quicksort.h"

#define Swap(X,Y)  do{ __typeof__ (X) _T = X; X = Y; Y = _T; }while(0)

int *divide(void *left, void *right, comparator compare) {
    void *i = left;
    void *j = right - 1;
    void* pivot = right;

    while (i < j) {
        while (i < right && compare(i, pivot) < 0)
            i++;

        while (j > left && compare(j, pivot) >= 0)
            j--;

        if (i < j)
            Swap(i, j);
    }

    if (compare(i, pivot)> 0)
        Swap(i, right);

    return i;
}

void quicksort(void *left, void *right, comparator compare) {
    if (left < right) {
        int *pivot = divide(left, right, compare);
        quicksort(left, pivot - 1, compare);
        quicksort(pivot + 1, right, compare);
    }
}
