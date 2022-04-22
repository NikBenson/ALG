#include <stdbool.h>
#include "place_elements_in_corresponding_bucket.h"
#include "../swap.h"
#include "../quicksort/divide_data_from_pivot.h"

Array
placeElementsInCorrespondingBucketAndSortBuckets(Array data, Array splitters, SampleSortConfiguration configuration) {
    void *middleSplitter = splitters.start + ((splitters.end - splitters.start) / 2);

    bool hasLeft = middleSplitter >= splitters.start;
    bool hasRight = middleSplitter <= splitters.end;

    Array leftSplitters = {data.start, data.start + (middleSplitter - splitters.start)};
    Array rightSplitters = {data.end - (splitters.end - middleSplitter), data.end};

    for (int i = 0; i < arrayLength(splitters); ++i) {
        void *splitter = splitters.start + i;
        void *targetPosition = splitter;
        if (splitter < middleSplitter) {
            targetPosition = data.start + i;
        } else if (splitter > middleSplitter) {
            targetPosition = data.end - (splitters.end - middleSplitter) + i;
        }
        Swap(splitter, targetPosition);
    }

    middleSplitter = divideDataFromPivot((Array) {leftSplitters.end + 1, rightSplitters.start - 1}, middleSplitter,
                                         configuration.compare);

    if (hasLeft)
        placeElementsInCorrespondingBucketAndSortBuckets((Array) {data.start, middleSplitter - 1}, leftSplitters,
                                                         configuration);
    if (hasRight)
        placeElementsInCorrespondingBucketAndSortBuckets((Array) {middleSplitter + 1, data.end}, rightSplitters,
                                                         configuration);

    // TODO(nbenson): sort
}
