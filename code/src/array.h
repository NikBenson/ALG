#ifndef CODE_ARRAY_H
#define CODE_ARRAY_H

typedef struct Array {
    int *start;
    int *end;
} Array;

unsigned long arrayLength(Array array);

void traverseArray(Array array, void (*fn)(const int *value));

void printArray(Array array);

void printNumbers(const int *current);

#endif //CODE_ARRAY_H
