#include <stdbool.h>
#include "place_elements_in_corresponding_bucket.h"
#include "../swap.h"

Array
placeElementsInCorrespondingBucketAndSortBuckets(Array data, Array splitters, SampleSortConfiguration configuration) {
    void *middleSplitter = splitters.start + ((splitters.end - splitters.start) / 2);

    bool hasLeft = middleSplitter > splitters.start;
    bool hasRight = middleSplitter < splitters.end;

    Array leftSplitters = {data.start, data.start + (middleSplitter - splitters.start)};
    Array rightSplitters = {data.end - (splitters.end - middleSplitter), data.end};

    for (int i = 0; i < arrayLength(splitters); ++i) {
        void* splitter = splitters.start + i;
        if (splitter < middleSplitter) {
            void *a = data.start + i;
            void *b = splitter + i;
            Swap(a, b);
        } else if (splitter > middleSplitter) {

        }
    }
}
