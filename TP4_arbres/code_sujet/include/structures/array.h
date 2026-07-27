#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H

#include "structures/string_type.h"

typedef string T;

typedef struct s_list {
    T *data;
    unsigned int size;
    unsigned int capacity;
} string_array;

string_array create_empty_array();

T get(const string_array *t, const unsigned int index);

void set(string_array *t, const unsigned int index, const T val);

void push_front(string_array *t, const T val);

void push_back(string_array *t, const T val);

void insert(string_array *t, const unsigned int index, const T val);

void delete_at(string_array *t, const unsigned int index);

void print_array(const string_array *t);

void destroy_array(string_array *t);

bool search_in_array(const string_array *t, const string s);

void list_all_entries_array(const string_array *t);

#endif