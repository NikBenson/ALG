#include "select_splitters.h"

Array selectSplitters(Array data, SampleSortConfiguration configuration) {
    unsigned int sampleSize = configuration.oversamplingFactor * (configuration.splittersCount-1)+1;
    Array sample = configuration.sampler(data, sampleSize, configuration.swap);
    configuration.smallSort(sample, configuration.compare, configuration.swap);

    unsigned int sampleLength = arrayLength(sample);
    unsigned int steps = (sampleLength-1) / (configuration.splittersCount-1);

    // Elemente mit groesster distanz aus Sample als Splitter an den Anfang setzen
    for (int i = 0; i < configuration.splittersCount; ++i) {
        int *targetPosition = sample.start + i;
        int *fromPosition = sample.start + (i * steps);
        configuration.swap(targetPosition, fromPosition);
    }
    return (Array) {sample.start, sample.start + configuration.splittersCount - 1};
}
