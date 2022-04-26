#include "select_splitters.h"

Array selectSplitters(Array data, SampleSortConfiguration configuration) {
    Array sample = configuration.sampler(data, configuration.oversamplingFactor * configuration.splittersCount, configuration.swap);
    configuration.smallSort(sample, configuration.compare, configuration.swap);

    unsigned int sampleLength = arrayLength(sample);
    unsigned int steps = sampleLength / configuration.splittersCount;

    for (int i = 0; i < configuration.splittersCount; ++i) {
        int *targetPosition = sample.start + i;
        int *fromPosition = sample.start + (i * steps);
        configuration.swap(targetPosition, fromPosition);
    }
    return (Array) {sample.start, sample.start + configuration.splittersCount - 1};
}

