#ifndef LIST_DOUBLE_LINKED
#define LIST_DOUBLE_LINKED

typedef int T;

typedef struct s_cell {
    struct s_cell *next;
    struct s_cell *prev;
    T value;
} t_cell;

typedef struct s_list {
    t_cell *head;
    t_cell *tail;
    int size;
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

void print_list_backward(t_list *list);

void destroy_list(t_list *list);

#endif