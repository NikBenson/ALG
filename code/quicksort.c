#include "quicksort.h"

void swap(int *firstOperand, int *secondOperand) {
    int temp = *firstOperand;

    *firstOperand = *secondOperand;
    *secondOperand = temp;
}

int *divide(int *left, int *right) {
    int *i = left;
    int *j = right - 1;
    int pivot = *right;

    while (i < j) {
        while (i < right && *i < pivot)
            i++;

        while (j > left && *j >= pivot)
            j--;

        if (i < j)
            swap(i, j);
    }

    if (*i > pivot)
        swap(i, right);

    return i;
}

void quicksort(int *left, int *right) {
    if (left < right) {
        int *pivot = divide(left, right);
        quicksort(left, pivot - 1);
        quicksort(pivot + 1, right);
    }
}
