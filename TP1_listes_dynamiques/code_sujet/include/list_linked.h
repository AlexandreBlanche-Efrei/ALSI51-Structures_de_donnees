#ifndef LIST_LINKED_H
#define LIST_LINKED_H

typedef int T;

typedef struct s_cell {
    struct s_cell *next;
    T value;
} t_cell;

typedef struct {
    t_cell *head;
    int size;
} t_list;

// Returns an empty list
t_list create_empty_list();

// Returns the element at given index
T get(t_list *list, int index);

// Sets the element at given index to value val
void set(t_list *list, int index, T val);

// Adds an element to list at index 0
void push_front(t_list *list, T val);

// Adds an element to list at the last index
void push_back(t_list *list, T val);

// Inserts an element with value val at given index
void insert(t_list *list, int index, T val);

// Deletes the element at given index
void delete_at(t_list *list, int index);

// Prints the elements of the list in order
void print_list(t_list *list);

// Frees the memory reserved to store the elements
void destroy_list(t_list *list);

#endif