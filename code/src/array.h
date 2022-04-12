#ifndef CODE_ARRAY_H
#define CODE_ARRAY_H

typedef struct Array {
    void* start;
    void* end;
} Array;

unsigned int arrayLength(Array array) {
    return array.end - array.start;
}

#endif //CODE_ARRAY_H
