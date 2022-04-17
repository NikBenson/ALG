#include "even.h"
#include "../../swap.h"

Array chooseSampleEven(Array data, unsigned int sampleLength) {
    unsigned int steps = arrayLength(data) / sampleLength;
    for (int i = 0; i < arrayLength(data); ++i) {
        void *targetPosition = data.start + i;
        void *initialPosition = data.start + i * steps;
        Swap(targetPosition, initialPosition);
    }
    return (Array) {data.start, data.start + sampleLength - 1};
}
