#include "block.h"

Array chooseSampleByBlock(Array data, unsigned int sampleLength) {
    return (Array) {data.start, data.start + sampleLength - 1};
}
