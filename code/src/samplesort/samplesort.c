#include "samplesort.h"
#include "select_splitters.h"
#include "place_elements_in_corresponding_bucket.h"

void sampleSort(Array data, SampleSortConfiguration configuration) {
    unsigned int averageBucketSize = arrayLength(data) / configuration.oversamplingFactor;
    if (averageBucketSize < configuration.threshold)
        return configuration.smallSort(data, configuration.compare, configuration.swap);

    Array splitter = selectSplitters(data, configuration);

    placeElementsInCorrespondingBucketAndSortBuckets(data, splitter, configuration);
}
