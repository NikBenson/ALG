#include <stdlib.h>
#include "semi_random.h"
#include "../../swap.h"

Array chooseSampleSemiRandom(Array data, unsigned int sampleLength) {
    unsigned int maxSteps = arrayLength(data) / sampleLength;
    unsigned int steps = (random() % maxSteps) + 1;

    for (int i = 0; i < arrayLength(data); ++i) {
        void *targetPosition = data.start + i;
        void *initialPosition = data.start + i * steps;
        Swap(targetPosition, initialPosition);
    }
    return (Array) {data.start, data.start + sampleLength - 1};
}
