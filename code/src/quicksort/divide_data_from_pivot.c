#include "divide_data_from_pivot.h"

void *divideDataFromPivot(Array data, void *pivot, Comparator compare, Swapper swap) {
    void *i = data.start;
    void *j = data.end - 1;

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
