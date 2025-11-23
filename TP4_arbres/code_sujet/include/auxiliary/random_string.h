#ifndef RANDOM_STRING_H
#define RANDOM_STRING_H

#include "structures/string_type.h"

#define CHAR_SET_SIZE 36

string random_string();

int index_of_char(const char c);
int char_of_index(const int index);
unsigned int get_next_rand(const unsigned int rand);
unsigned int get_init_rand();
string get_next_random_string(unsigned int *rand);

#endif