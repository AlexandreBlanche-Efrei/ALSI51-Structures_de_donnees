#include <stdio.h>
#include <stdlib.h>

#include "structures/array.h"

#define INIT_CAPACITY 10

string_array create_empty_array() {
    string_array t;
    t.data = (T *) malloc(INIT_CAPACITY * sizeof(T));
    t.size = 0;
    t.capacity = INIT_CAPACITY;
    return t;
}

void realloc_array(string_array *t) {
    const unsigned int new_capacity = 2 * t->capacity;
    T *new_data = (T*) malloc(new_capacity * sizeof(T));
    for (unsigned int i = 0; i < t->size; i++)
        new_data[i] = t->data[i];
    free(t->data);
    t->data = new_data;
    t->capacity = new_capacity;
}

// Shifts the elements of indices index_start .. size-1 one position to the right
// It is assumed that capacity >= size + 1
void shift_right(string_array *t, const unsigned int index_start) {
    for (unsigned int i = t->size; i > index_start; i--)
        t->data[i] = t->data[i - 1];
}

// Shifts the elements of indices index_start .. size-1 one position to the left
void shift_left(string_array *t, const unsigned int index_start) {
    if (index_start > 0) {
        for (unsigned int i = index_start - 1; i < t->size - 1; i++)
            t->data[i] = t->data[i + 1];
    }
}

void push_front(string_array *t, const T val) {
    
    insert(t, 0, val);
}

void push_back(string_array *t, const T val) {

    if (t->size >= t->capacity)
        realloc_array(t);

    t->data[t->size] = val;
    t->size++;
}

T get(const string_array *t, const unsigned int index) {
    return t->data[index];
}

void set(string_array *t, const unsigned int index, const T val) {
    t->data[index] = val;
}

void insert(string_array *t, const unsigned int index, const T val) {
    if (t->size >= t->capacity)
        realloc_array(t);

    if (index == t->size) {
        push_back(t, val);
    }
    else {
        shift_right(t, index);
        t->data[index] = val;
        t->size++;
    }
}

void delete_at(string_array *t, const unsigned int index) {
    shift_left(t, index + 1);
    t->size--;
}

void print_array(const string_array *t) {
    printf("[ ");
    for (unsigned int i = 0; i < t->size - 1; i++) {
        printf("%s, ", t->data[i]);
    }
    if (t->size)
        printf("%s ", t->data[t->size - 1]);
    printf("]\n");
}

void destroy_array(string_array *t) {
    for (unsigned int i = 0; i < t->size; i++)
        free(t->data[i]);
    free(t->data);
    t->data = NULL;
    t->size = 0;
    t->capacity = 0;
}

bool search_in_array(const string_array *t, const string s) {
    for (unsigned int i = 0; i < t->size; i++) {
        if (string_eq(s, t->data[i]))
            return true;
    }
    return false;
}

void list_all_entries_array(const string_array *t) {
    for (unsigned int i = 0; i < t->size; i++)
        printf("%s\n", t->data[i]);
}