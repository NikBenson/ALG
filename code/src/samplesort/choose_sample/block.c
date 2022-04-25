#include "block.h"

Array chooseSampleByBlock(Array data, unsigned int sampleLength, Swapper swap) {
    return (Array) {data.start, data.start + sampleLength - 1};
}
