#ifndef CODE_SELECT_SPLITTERS_H
#define CODE_SELECT_SPLITTERS_H

#include "../array.h"
#include "choose_sample/choose_sample.h"

Array selectSplitters(Array data, unsigned int splittersCount, unsigned int oversamplingFactor, ChooseSample chooseSample);

#endif //CODE_SELECT_SPLITTERS_H
