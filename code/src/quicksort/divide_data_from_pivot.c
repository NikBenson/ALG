#include "divide_data_from_pivot.h"
#include "../swap.h"

int *divide_data_from_pivot(Array data, void *pivot, Comparator compare) {
    void *i = data.start;
    void *j = data.end - 1;

    Swap(pivot, data.end);
    pivot = data.end;

    while (i < j) {
        while (i < data.end && compare(i, pivot) < 0)
            i++;

        while (j > data.start && compare(j, pivot) >= 0)
            j--;

        if (i < j)
            Swap(i, j);
    }

    if (compare(i, pivot) > 0)
        Swap(i, data.end);

    return i;
}
