#include "select_splitters.h"
#include "quicksort.h"
#include "compare_int_pointers.h"

int **selectSplitters(int *toSort, unsigned int toSortLength, unsigned int oversamplingFactor, unsigned int splittersCount) {
    unsigned int sampleLength = oversamplingFactor * (splittersCount - 1);
    int *sample[sampleLength];

    if (sampleLength < toSortLength) {
        for (int i = 0; i < sampleLength; ++i) {
            sample[i] = toSort + toSortLength - sampleLength + i;
        }
    } else {
        // TODO(NikBenson): handle case
    }

    quicksort(sample, sample + sampleLength - 1, (comparator) &compareIntPointers);
}

