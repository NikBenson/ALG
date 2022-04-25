#ifndef CODE_ARRAY_H
#define CODE_ARRAY_H

typedef struct Array {
    int *start;
    int *end;
} Array;

unsigned long arrayLength(Array array);

#endif //CODE_ARRAY_H
