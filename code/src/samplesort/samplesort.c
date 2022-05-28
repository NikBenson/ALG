#include "samplesort.h"
#include "select_splitters.h"
#include "place_elements_in_corresponding_bucket.h"

void sampleSort(Array data, SampleSortConfiguration configuration) {
    unsigned int averageBucketSize = arrayLength(data) / (configuration.splittersCount + 1);
    // Rekursionsanker
    if (averageBucketSize < configuration.threshold)
        return configuration.smallSort(data, configuration.compare, configuration.swap);

    // Phase 1
    Array splitter = selectSplitters(data, configuration);

    // Phasen 1 & 2
    placeElementsInCorrespondingBucketAndSortBuckets(data, splitter, configuration);
}
