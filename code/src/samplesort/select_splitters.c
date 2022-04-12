#include "select_splitters.h"
#include "../quicksort/quicksort.h"
#include "../compare_int_pointers.h"
#include "../swap.h"

Array selectSplitters(Array data, unsigned int splittersCount, unsigned int oversamplingFactor, ChooseSample chooseSample) {
    Array sample = chooseSample(data, oversamplingFactor * (splittersCount - 1));
    quicksort(sample, (Comparator) compareIntPointers);

    unsigned int sampleLength = arrayLength(sample);
    unsigned int steps = sampleLength / splittersCount;

    for (int i = 0; i < splittersCount; ++i) {
        void *targetPosition = sample.start + i;
        void *fromPosition = sample.start + (i * steps);
        Swap(targetPosition, fromPosition);
    }
    return (Array) {sample.start, sample.start + splittersCount - 1};
}

