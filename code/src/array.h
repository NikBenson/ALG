#ifndef CODE_ARRAY_H
#define CODE_ARRAY_H

typedef struct Array {
    void *start;
    void *end;
} Array;

unsigned int arrayLength(Array array);

#endif //CODE_ARRAY_H
