#ifndef LIST_DE_LINKED_H
#define LIST_DE_LINKED_H

#include "expressions/token.h"

typedef t_token T;

typedef struct s_cell {
    struct s_cell *next;
    T value;
} t_cell;

typedef struct {
    t_cell *head;
    t_cell *tail;
    int size;
} t_list;

/////

t_list create_empty_list();

// O(1)
int length(t_list *list);

T get(t_list *list, int index);

void set(t_list *list, int index, T val);

// O(1)
void push_front(t_list *list, T val);

// O(1)
void push_back(t_list *list, T val);

void insert(t_list *list, int index, T val);

// O(1) for index == 0 or index == n-1
// O(n) worst-case
void delete_at(t_list *list, int index);

void print_list(t_list *list);

void destroy_list(t_list *list);

#endif