#ifndef CODE_CONFIGURATION_H
#define CODE_CONFIGURATION_H

#include "../sort.h"
#include "../swap.h"
#include "choose_sample/choose_sample.h"

typedef struct SampleSortConfiguration {
    unsigned int oversamplingFactor;
    unsigned int splittersCount;
    unsigned int threshold;
    Sort smallSort;
    Comparator compare;
    Swapper swap;
    ChooseSample sampler;
} SampleSortConfiguration;

#endif //CODE_CONFIGURATION_H
