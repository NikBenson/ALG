#ifndef CODE_PARTITION_H
#define CODE_PARTITION_H

#include "../array.h"
#include "../comparator.h"
#include "../swap.h"

int *partition(Array data, void* pivot, Comparator compare, Swapper swap);
#endif //CODE_PARTITION_H
