#include <stdio.h>
#include <stdbool.h>
#include "samplesort.h"
#include "quicksort.h"

#define ARR_LENGTH 20//8500

int main() {
    int arr[ARR_LENGTH] = {};

    for (int i = 0; i < ARR_LENGTH; ++i) {
        if (scanf("%d ", arr + i) == EOF)
            break;
    }

    sampleSort(arr, ARR_LENGTH, 1, 5);

    bool success = true;
    for (int i = 0; i < ARR_LENGTH; ++i) {
        int value = arr[i];
        char *splitter = i == ARR_LENGTH - 1 ? "\n" : ", ";
        printf("%d%s", value, splitter);

        if (i > 0 && arr[i - 1] > value)
            success = false;
    }
    printf("Success: %d\n", success);

    return 0;
}
