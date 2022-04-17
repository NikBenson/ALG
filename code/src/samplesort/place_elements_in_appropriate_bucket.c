#include "place_elements_in_appropriate_bucket.h"

Array placeElementsInAppropriateBucket(Array data, Array splitters) {
    void *splitter = (splitters.start + (splitters.end - splitters.start) / 2);
    void **s = &splitter;

    if (arrayLength(splitters) <= 1) {
        return (Array) {s, s};
    }
}
