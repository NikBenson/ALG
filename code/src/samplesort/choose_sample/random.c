#include <stdlib.h>
#include "random.h"

Array chooseSampleRandom(Array data, unsigned int sampleLength, Swapper swap) {
    for (int i = 0; i < sampleLength; ++i) {
        int *targetPosition = data.start + i;

        unsigned long r = random() % (arrayLength(data) - i);

        int *initialPosition = data.start + i + r;
        swap(targetPosition, initialPosition);
    }
    return (Array) {data.start, data.start + sampleLength - 1};
}
