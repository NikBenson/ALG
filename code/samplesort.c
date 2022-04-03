#include "samplesort.h"
#include "quicksort.h"

#define THRESHOLD 3

void sampleSort(int *toSort,
                unsigned int toSortLength,
                unsigned int oversamplingFactor,
                unsigned int splittersCount) {
    if (toSortLength/oversamplingFactor < THRESHOLD)
        return quicksort(toSort, toSort + toSortLength - 1);


    /* Step 1 */
    select {\displaystyle S=[S_{1},\dots ,S_{(p-1)k}]} randomly from // select samples
    sort S // sort sample
            {\displaystyle [s_{0},s_{1},\dots ,s_{p-1},s_{p}]\leftarrow [-\infty ,S_{k},S_{2k},\dots ,S_{(p-1)k},\infty ]} // select splitters
    /* Step 2 */
    for each {\displaystyle a\in A}
    find j such that {\displaystyle s_{j-1}<a\leq s_{j))
            place a in bucket b_{j}
            /* Step 3 and concatenation */
            return {\displaystyle {\texttt {concatenate))({\texttt {sampleSort))(b_{1}),\dots ,{\texttt {sampleSort))(b_{k}))}
}
