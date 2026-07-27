#include <stdio.h>
#include <stdlib.h>

#include "linked_list/list_linked.h"


t_list create_empty_list() {
    t_list l;
    l.head = NULL;
    l.size = 0;
    return l;
}

t_cell *create_cell(T val) {
    t_cell *newcell = (t_cell*) malloc(sizeof(t_cell));
    newcell->value = val;
    newcell->next = NULL;
    return newcell;
}

void push_front(t_list *list, T val) {
    
    t_cell *newcell = create_cell(val);
    newcell->next = list->head;
    list->head = newcell;
    list->size++;
}

t_cell* get_cell(t_list *list, int index) {
    t_cell *cell = list->head;
    if (cell == NULL || index < 0 || index > list->size)
        return NULL;

    int i = 0;
    while (!(i == index || cell == NULL)) {
        cell = cell->next;
        i++;
    }
    return cell;
}

t_cell* get_last(t_list *list) {
    return get_cell(list, list->size - 1);
}

void push_back(t_list *list, T val) {

    if (list->size == 0) {
        push_front(list, val);
        return;
    }
    t_cell *newcell = create_cell(val);
    t_cell *lastcell = get_last(list);
    lastcell->next = newcell;
    list->size++;
}

T get(t_list *list, int index) {
    t_cell *cell = get_cell(list, index);
    return cell->value;
}

void set(t_list *list, int index, T val) {
    t_cell *cell = get_cell(list, index);
    cell->value = val;
}

void insert(t_list *list, int index, T val) {
    if (index == 0) {
        push_front(list, val);
        return;
    }

    t_cell *prev = get_cell(list, index - 1);
    t_cell *newcell = create_cell(val);
    newcell->next = prev->next;
    prev->next = newcell;
    list->size++;
}

void delete_at(t_list *list, int index) {
    if (index == 0) {
        t_cell *first = list->head;
        if (first == NULL)
            return;
        list->head = first->next;
        free(first);
        list->size--;
        return;
    }

    t_cell *prev = get_cell(list, index - 1);
    t_cell *cell = prev->next;
    if (prev == NULL || cell == NULL)
        return;
    prev->next = cell->next;
    free(cell);
    list->size--;
}

void print_list(t_list *list) {
    
    printf("[ ");
    t_cell *cell = list->head;
    if (cell == NULL) {
        printf("]\n");
        return;
    }
    
    while(cell->next != NULL) {
        printf("%d, ", cell->value);
        cell = cell->next;
    }
    printf("%d ]\n", cell->value);
}

void destroy_list(t_list *list) {
    
    t_cell *cell = list->head;
    while (cell != NULL) {
        t_cell *next = cell->next;
        free(cell);
        cell = next;
    }
    list->head = NULL;
}

t_list reverse(t_list *list) {
    t_list revlist = create_empty_list();
    t_cell *cell = list->head;
    while (cell != NULL) {
        push_front(&revlist, cell->value);
    }
    return revlist;
}

t_list map(int (*pf)(int), t_list *list) {
    t_list newlist = create_empty_list();
    
    t_cell *cell = list->head;
    while (cell != NULL) {
        push_front(&newlist, (*pf)(cell->value));
    }

    t_list revnew = reverse(&newlist);
    destroy_list(&newlist);
    return revnew;
}