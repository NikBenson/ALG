#include <stdlib.h>
#include "semi_random.h"

Array chooseSampleSemiRandom(Array data, unsigned int sampleLength, Swapper swap) {
    unsigned int maxSteps = arrayLength(data) / sampleLength;
    unsigned int steps = (random() % maxSteps) + 1;

    for (int i = 0; i < sampleLength; ++i) {
        int *targetPosition = data.start + i;
        int *initialPosition = data.start + i * steps;
        swap(targetPosition, initialPosition);
    }
    return (Array) {data.start, data.start + sampleLength - 1};
}
