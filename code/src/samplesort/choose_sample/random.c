#include <stdlib.h>
#include "random.h"

Array chooseSampleRandom(Array data, unsigned int sampleLength, Swapper swap) {
    for (int i = 0; i < arrayLength(data); ++i) {
        int *targetPosition = data.start + i;
        int *initialPosition = data.start + i + (random() % (sampleLength - i));
        swap(targetPosition, initialPosition);
    }
    return (Array) {data.start, data.start + sampleLength - 1};
}
