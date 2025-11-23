#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "array.h"
#include "auxiliary/t_time.h"

typedef struct {
    char *name;
    void (*function)(T*, unsigned int);
    t_time *samples;
} algorithm;

void export_csv(const char *file_name, algorithm *algos[], unsigned int nb_algos, unsigned int nb_samples, unsigned int step);

#endif
