#include "algorithms/quick_sort.h"

//#include <stdio.h>

// Splits the section [i .. j] of the array into two subarrays tinf and tsup, w.r.t. the pivot = t[i]
// Returns the index index_pivot of the pivot after the split
// After the split, tinf = t[i .. index_pivot - 1], tsup = t[index_pivot + 1 .. j]
unsigned int split(T t[], unsigned int i, unsigned int j) {
    if (j <= i) {
        return 0;
    }
    /* TODO */
    return 0;
}

void quick_sort_aux(T t[], unsigned int i, unsigned int j) {

    if (j == i + 1) {
        /* TODO */
        return;
    }
    if (j < i + 1)
        return;
    /* TODO */
}

void quick_sort(T t[], unsigned int size) {
    /* TODO */
}