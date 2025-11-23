#include "structures/array.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fill_random(T t[], unsigned int size) {
    const unsigned int r0 = 343513213;
    const unsigned int A = 3376447;
    const unsigned int B = 333599;
    const unsigned int M = 1117;

    unsigned int rand = r0;
    for (unsigned int i = 0; i < size; i++) {
        t[i] = rand;
        rand = (rand * A + B) % M;
    }
}

void print_array(T t[], unsigned int size) {
    printf("[ ");
    if (size) {
        for (unsigned int i = 0; i < size - 1; i++) {
            printf("%u, ", t[i]);
        }
        printf("%u ", t[size - 1]);
    }
    printf("]\n");
}

bool is_sorted(T t[], unsigned int size) {
    for (unsigned int i = 0; i < size - 1; i++) {
        if (t[i] > t[i + 1])
            return false;
    }
    return true;
}

void raise_error(char *s) {
    printf("Error: %s\n", s);
    exit(EXIT_FAILURE);
}

void copy(T src[], T dst[], unsigned int index_start, unsigned int index_end) {
    memcpy(dst, src + index_start, (index_end - index_start + 1) * sizeof(T));
}

void swap(T t[], unsigned int i, unsigned int j) {
    printf("Swap is not implemented yet\n");
    /* TODO */
}