#include <stdlib.h>
#include "random.h"
#include "../../swap.h"

Array chooseSampleRandom(Array data, unsigned int sampleLength) {
    for (int i = 0; i < arrayLength(data); ++i) {
        void *targetPosition = data.start + i;
        void *initialPosition = data.start + i + (random() % (sampleLength - i));
        Swap(targetPosition, initialPosition);
    }
    return (Array) {data.start, data.start + sampleLength - 1};
}
