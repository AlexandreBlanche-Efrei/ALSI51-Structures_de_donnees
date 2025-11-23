#include <stdio.h>
#include <stdlib.h>

#include "array/list_array.h"

#define INIT_CAPACITY 10


t_list create_empty_list() {
    t_list l;
    l.data = (T*) malloc(INIT_CAPACITY * sizeof(T));
    l.size = 0;
    l.capacity = INIT_CAPACITY;
    return l;
}

void realloc_list(t_list* list) {
    unsigned int new_capacity = 2 * list->capacity;
    T *new_data = (T*) malloc(new_capacity * sizeof(T));
    for (unsigned int i = 0; i < list->size; i++) {
        new_data[i] = list->data[i];
    }
    free(list->data);
    list->data = new_data;
    list->capacity = new_capacity;
}

// Shifts the elements of indices index_start .. size-1 one position to the right
// It is assumed that capacity >= size + 1
void shift_right(t_list* list, int index_start) {
    for (unsigned int i = list->size; i > index_start; i--) {
        list->data[i] = list->data[i - 1];
    }
}

// Shifts the elements of indices index_start .. size-1 one position to the left
void shift_left(t_list* list, int index_start) {
    if (index_start > 0) {
        for (unsigned int i = index_start - 1; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
}

void push_front(t_list *list, T val) {
    
    insert(list, 0, val);
}

void push_back(t_list *list, T val) {

    if (list->size >= list->capacity) {
        realloc_list(list);
    }

    list->data[list->size] = val;
    list->size++;
}

T get(t_list *list, int index) {
    return list->data[index];
}

void set(t_list *list, int index, T val) {
    list->data[index] = val;
}

void insert(t_list *list, int index, T val) {
    if (list->size >= list->capacity) {
        realloc_list(list);
    }

    if (index == list->size) {
        push_back(list, val);
    }
    else {
        shift_right(list, index);
        list->data[index] = val;
        list->size++;
    }
}

void delete_at(t_list *list, int index) {
    shift_left(list, index + 1);
    list->size--;
}

void print_list(t_list *list) {
    printf("[ ");
    for (int i = 0; i < list->size - 1; i++) {
        printf("%d, ", list->data[i]);
    }
    if (list->size) {
        printf("%d ", list->data[list->size - 1]);
    }
    printf("]\n");
}

void destroy_list(t_list *list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}