#include "samplesort.h"
#include "quicksort.h"
#include "compare_int_pointers.h"
#include "select_splitters.h"
#include "find_bucket_index_for_value_by_binary_search.h"

void sampleSort(int *toSort, unsigned int toSortLength, unsigned int oversamplingFactor, unsigned int splittersCount, unsigned int threshold) {
    unsigned int averageBucketSize = toSortLength / oversamplingFactor;
    if (averageBucketSize < threshold)
        return quicksort(toSort, toSort + toSortLength - 1, (comparator) compareIntPointers);

    unsigned int sampleLength = (splittersCount - 1 * oversamplingFactor);

    int **splitters = selectSplitters(toSort, toSortLength, oversamplingFactor, splittersCount);

    for (int i = 0; i < toSortLength; ++i) {
        unsigned int bucketIndex = findBucketIndexForValueByBinarySearch(splitters, splitters + splittersCount - 1,
                                                                         toSort[i]);
        // TODO(NikBenson): put value in bucket
        // TODO(NikBenson): recursive sort buckets
    }
}
