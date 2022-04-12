#include "quicksort.h"
#include "divide_data_from_pivot.h"

void quicksort(Array data, Comparator compare) {
    if (data.start < data.end) {
        int *pivot = divide_data_from_pivot(data, data.end, compare);
        quicksort((Array) {data.start, pivot - 1}, compare);
        quicksort((Array) {pivot + 1, data.end}, compare);
    }
}
