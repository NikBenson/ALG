#include "partition.h"

int *partition(Array data, void *pivot, Comparator compare, Swapper swap) {
    int *i = data.start;
    int *j = data.end - 1;

    swap(pivot, data.end);
    pivot = data.end;

    while (i < j) {
        while (i < data.end && compare(i, pivot) < 0)
            i++;

        while (j > data.start && compare(j, pivot) >= 0)
            j--;

        if (i < j)
            swap(i, j);
    }

    if (compare(i, pivot) > 0)
        swap(i, data.end);

    return i;
}
