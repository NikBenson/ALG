#include "samplesort.h"
#include "quicksort.h"

#define THRESHOLD 3

int compareIntPointers(int* a, int* b) {
    if(*a == *b)
        return 0;
    else if(*a > *b)
        return -1;
    else
        return 1;
}

int **selectSplitters(int *toSort, unsigned int toSortLength, unsigned int oversamplingFactor, unsigned int splittersCount) {
    unsigned int sampleLength = oversamplingFactor * (splittersCount - 1);
    int *sample[sampleLength];

    if (sampleLength < toSortLength) {
        for (int i = 0; i < sampleLength; ++i) {
            sample[i] = toSort + toSortLength - sampleLength + i;
        }
    } else {

    }

    quicksort(sample, sample + sampleLength - 1, (comparator) &compareIntPointers);
}

/**
 *
 * @param firstSplitter is the first element of the array of references to the splitter values
 * @param lastSplitter is the last element of the array of references to the splitter values
 * @param value is the value to associate to a bucket
 * @return index of the bucket matching [value]
 */
unsigned int binarySearchForSplitter(int **firstSplitter, int **lastSplitter, int value) {
    if (firstSplitter == lastSplitter)
        return 0;

    unsigned int splittersLength = lastSplitter - firstSplitter;
    int **middleSplitter = firstSplitter + splittersLength / 2;

    if (**middleSplitter == value)
        return splittersLength / 2;
    else if (**middleSplitter > value)
        return splittersLength / 2 + binarySearchForSplitter(middleSplitter, lastSplitter, value);
    else
        return binarySearchForSplitter(firstSplitter, middleSplitter, value);
}

void sampleSort(int *toSort, unsigned int toSortLength, unsigned int oversamplingFactor, unsigned int splittersCount) {
    if (toSortLength / oversamplingFactor < THRESHOLD)
        return quicksort(toSort, toSort + toSortLength - 1);

    unsigned int sampleLength = (splittersCount - 1 * oversamplingFactor);

    int **splitters = selectSplitters(toSort, toSortLength, oversamplingFactor, splittersCount);

    for (int i = 0; i < toSortLength; ++i) {
        unsigned int bucketIndex = binarySearchForSplitter(splitters, splitters + splittersCount - 1, toSort[i]);

    }
}
