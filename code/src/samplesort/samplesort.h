#ifndef CODE_SAMPLESORT_H
#define CODE_SAMPLESORT_H

#include "../array.h"
#include "../comparator.h"
#include "../sort.h"
#include "choose_sample/choose_sample.h"

typedef struct SampleSortConfiguration {
    unsigned int oversamplingFactor;
    unsigned int splittersCount;
    unsigned int threshold;
    Sort smallSort;
    Comparator compare;
    ChooseSample sampler;
} SampleSortConfiguration;

void sampleSort(Array data, SampleSortConfiguration configuration);

#endif //CODE_SAMPLESORT_H
