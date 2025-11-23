#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

typedef unsigned int T;

void fill_random(T t[], unsigned int size);

void print_array(T t[], unsigned int size);

bool is_sorted(T t[], unsigned int size);

void raise_error(char *s);

void swap(T t[], unsigned int i, unsigned int j);

void copy(T src[], T dst[], unsigned int index_start, unsigned int index_end);

#endif