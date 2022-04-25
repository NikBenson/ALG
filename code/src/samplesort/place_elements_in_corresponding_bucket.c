#include <stdbool.h>
#include "place_elements_in_corresponding_bucket.h"
#include "../quicksort/divide_data_from_pivot.h"
#include "configuration.h"

void placeElementsInCorrespondingBucketAndSortBuckets(Array data, Array splitters, SampleSortConfiguration configuration) {
    void *middleSplitter = splitters.start + ((splitters.end - splitters.start) / 2);

    bool hasLeft = middleSplitter >= splitters.start;
    bool hasRight = middleSplitter <= splitters.end;

    Array leftSplitters = {data.start, data.start + (middleSplitter - splitters.start)};
    Array rightSplitters = {data.end - (splitters.end - middleSplitter), data.end};

    for (int i = 0; i < arrayLength(splitters); ++i) {
        void *splitter = splitters.start + i;
        void *targetPosition = splitter;
        if (configuration.compare(splitter, middleSplitter) < 1) {
            targetPosition = data.start + i;
        } else if (splitter > middleSplitter) {
            targetPosition = data.end - (splitters.end - middleSplitter) + i;
        }
        configuration.swap(splitter, targetPosition);
    }

    middleSplitter = divideDataFromPivot((Array) {leftSplitters.end + 1, rightSplitters.start - 1}, middleSplitter,
                                         configuration.compare, configuration.swap);

    Array leftData = {data.start, middleSplitter - 1};
    if (hasLeft)
        placeElementsInCorrespondingBucketAndSortBuckets(leftData, leftSplitters, configuration);
    else
        sampleSort(leftData, configuration);

    Array rightData = {middleSplitter + 1, data.end};
    if (hasRight)
        placeElementsInCorrespondingBucketAndSortBuckets(rightData, rightSplitters, configuration);
    else
        sampleSort(rightData, configuration);

}
