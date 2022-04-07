#include "find_bucket_index_for_value_by_binary_search.h"

unsigned int findBucketIndexForValueByBinarySearch(int **firstSplitter, int **lastSplitter, int value) {
    if (firstSplitter == lastSplitter)
        return 0;

    unsigned int splittersLength = lastSplitter - firstSplitter;
    int **middleSplitter = firstSplitter + splittersLength / 2;

    if (**middleSplitter == value)
        return splittersLength / 2;
    else if (**middleSplitter > value)
        return splittersLength / 2 + findBucketIndexForValueByBinarySearch(middleSplitter, lastSplitter, value);
    else
        return findBucketIndexForValueByBinarySearch(firstSplitter, middleSplitter, value);
}

