#ifndef CODE_QUICKSORT_H
#define CODE_QUICKSORT_H

#include<stdbool.h>

typedef int (*comparator)(void*, void*);

void quicksort(void* left, void* right, comparator compare);

#endif //CODE_QUICKSORT_H
