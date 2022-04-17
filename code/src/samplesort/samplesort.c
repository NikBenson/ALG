#include "samplesort.h"
#include "../quicksort/quicksort.h"
#include "../compare_int_pointers.h"
#include "select_splitters.h"
#include "choose_sample/block.h"
#include "place_elements_in_appropriate_bucket.h"

void sampleSort(Array data, unsigned int oversamplingFactor, unsigned int bucketsCount, unsigned int threshold) {
    unsigned int averageBucketSize = arrayLength(data) / oversamplingFactor;
    if (averageBucketSize < threshold)
        return quicksort(data, (Comparator) compareIntPointers);

    Array splitter = selectSplitters(data, bucketsCount - 1, oversamplingFactor, chooseSampleByBlock);

    Array splitterPositions = placeElementsInAppropriateBucket(data, splitter);

    sampleSort((Array) {data.start, *(void **) splitterPositions.start}, oversamplingFactor, bucketsCount, threshold);
}
