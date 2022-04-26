#include "even.h"

Array chooseSampleEven(Array data, unsigned int sampleLength, Swapper swap) {
    unsigned int steps = arrayLength(data) / sampleLength;
    for (int i = 0; i < sampleLength; ++i) {
        int *targetPosition = data.start + i;
        int *initialPosition = data.start + i * steps;
        swap(targetPosition, initialPosition);
    }
    return (Array) {data.start, data.start + sampleLength - 1};
}
