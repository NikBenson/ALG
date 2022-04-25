#include "quicksort.h"
#include "divide_data_from_pivot.h"

void quicksort(Array data, Comparator compare, Swapper swap) {
    if (data.start < data.end) {
        int *pivot = divideDataFromPivot(data, data.end, compare, swap);
        quicksort((Array) {data.start, pivot - 1}, compare, swap);
        quicksort((Array) {pivot + 1, data.end}, compare, swap);
    }
}
