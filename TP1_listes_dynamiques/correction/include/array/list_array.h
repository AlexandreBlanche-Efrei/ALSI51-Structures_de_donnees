#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H

typedef int T;
typedef struct s_list {
    T *data;
    int size;
    int capacity;
} t_list;

/////

t_list create_empty_list();

T get(t_list *list, int index);

void set(t_list *list, int index, T val);

void push_front(t_list *list, T val);

void push_back(t_list *list, T val);

void insert(t_list *list, int index, T val);

void delete_at(t_list *list, int index);

void print_list(t_list *list);

void destroy_list(t_list *list);

#endif