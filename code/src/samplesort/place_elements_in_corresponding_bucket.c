#include <stdbool.h>
#include "place_elements_in_corresponding_bucket.h"
#include "../quicksort/divide_data_from_pivot.h"
#include "configuration.h"

void
placeElementsInCorrespondingBucketAndSortBuckets(Array data, Array splitters, SampleSortConfiguration configuration) {
    int *middleSplitter = splitters.start + ((splitters.end - splitters.start) / 2);

    bool hasLeftSplitters = middleSplitter != splitters.start;
    Array leftSplitters = {data.start, data.start + (middleSplitter - splitters.start)};
    for (int *splitter = splitters.start, *target = data.start; splitter < middleSplitter; ++splitter, ++target) {
        configuration.swap(splitter, target);
    }
    bool hasRightSplitters = middleSplitter != splitters.end;
    Array rightSplitters = {data.end - (splitters.end - middleSplitter), data.end};
    for (int *splitter = splitters.end, *target = data.end; splitter > middleSplitter; --splitter, --target) {
        configuration.swap(splitter, target);
    }

    middleSplitter = divideDataFromPivot((Array) {leftSplitters.end + 1, rightSplitters.start - 1}, middleSplitter, configuration.compare, configuration.swap);

    Array leftData = {data.start, middleSplitter - 1};
    if (hasLeftSplitters)
        placeElementsInCorrespondingBucketAndSortBuckets(leftData, leftSplitters, configuration);
    else
        sampleSort(leftData, configuration);

    Array rightData = {middleSplitter + 1, data.end};
    if (hasRightSplitters)
        placeElementsInCorrespondingBucketAndSortBuckets(rightData, rightSplitters, configuration);
    else
        sampleSort(rightData, configuration);

}
