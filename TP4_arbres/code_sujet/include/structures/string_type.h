#ifndef STRING_TYPE_H
#define STRING_TYPE_H

#include <stdbool.h>

#define MAX_STRING_LENGTH 20
#define MIN_STRING_LENGTH 5

typedef char* string;

int string_comp(const string s1, const string s2);

bool string_eq(const string s1, const string s2);

unsigned int string_length(const string s);

#endif