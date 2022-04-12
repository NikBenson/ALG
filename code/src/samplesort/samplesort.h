#ifndef CODE_SAMPLESORT_H
#define CODE_SAMPLESORT_H

#include "../array.h"
#include "../comparator.h"

void samplesort(Array
                data,
                Comparator compare,
                unsigned int oversamplingFactor,
                unsigned int splittersCount,
                unsigned int threshold
);

#endif //CODE_SAMPLESORT_H
