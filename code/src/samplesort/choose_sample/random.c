#include <stdlib.h>
#include "random.h"

Array chooseSampleRandom(Array data, unsigned int sampleLength, Swapper swap) {
    for (int i = 0; i < arrayLength(data); ++i) {
        void *targetPosition = data.start + i;
        void *initialPosition = data.start + i + (random() % (sampleLength - i));
        swap(targetPosition, initialPosition);
    }
    return (Array) {data.start, data.start + sampleLength - 1};
}
