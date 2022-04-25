#include "array.h"

unsigned long arrayLength(Array array) {
    long length = 1 + (array.end - array.start);

    if(length < 0) {
        return 0;
    }

    return length;
}
