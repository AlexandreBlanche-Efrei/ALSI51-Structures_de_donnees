#ifndef TESTS_H
#define TESTS_H

#include "structures/algorithm.h"

#define NB_SAMPLES 10
#define ARRAY_SIZE 100
// Warning: complexity in O(NB_SAMPLES * ARRAY_SIZE^2)

#define NB_ALGO 0

void measure_algorithms();
void test_algorithms();

#endif