#include <stdio.h>
#include <stdlib.h>

#include "linked_list/list_double-linked.h"


t_list create_empty_list() {
    t_list l;
    l.head = NULL;
    l.tail = NULL;
    l.size = 0;
    return l;
}

t_cell *create_cell(T val) {
    t_cell *newcell = (t_cell*) malloc(sizeof(t_cell));
    newcell->value = val;
    newcell->next = NULL;
    newcell->prev = NULL;
    return newcell;
}

void push_front(t_list *list, T val) {
    
    t_cell *newcell = create_cell(val);
    t_cell *first = list->head;
    if (first == NULL) {
        list->tail = newcell;
    }
    else {
        first->prev = newcell;
        newcell->next = first;
    }
    
    list->head = newcell;
    list->size++;
}

t_cell* get_cell_from_back(t_list *list, int index) {

    t_cell *cell = list->tail;
    if (cell == NULL)
        return NULL;

    int i = list->size - 1;
    while (!(i == index || cell == NULL)) {
        cell = cell->prev;
        i--;
    }
    return cell;
}

t_cell* get_cell(t_list *list, int index) {

    // size - index from the back, index + 1 from the front
    if (list->size - index < index + 1) {
        return get_cell_from_back(list, index);
    }

    t_cell *cell = list->head;
    if (cell == NULL)
        return NULL;

    int i = 0;
    while (!(i == index || cell == NULL)) {
        cell = cell->next;
        i++;
    }
    return cell;
}

void push_back(t_list *list, T val) {

    if (list->size == 0) {
        push_front(list, val);
        return;
    }
    t_cell *newcell = create_cell(val);
    t_cell *lastcell = list->tail;
    lastcell->next = newcell;
    newcell->prev = lastcell;
    list->tail = newcell;
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
    if (index == list->size) {
        push_back(list, val);
        return;
    }

    t_cell *prev = get_cell(list, index - 1);
    t_cell *newcell = create_cell(val);
    newcell->next = prev->next;
    newcell->prev = prev;
    prev->next = newcell;
    if (newcell->next != NULL) {
        newcell->next->prev = newcell;
    }
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
    if (index == list->size-1) {
        t_cell *last = list->tail;
        if (last == NULL)
            return;
        list->tail = last->prev;
        free(last);
        list->size--;
        return;
    }

    t_cell *prev = get_cell(list, index - 1);
    t_cell *cell = prev->next;
    if (prev == NULL || cell == NULL)
        return;

    t_cell *next = cell->next;
    free(cell);
    prev->next = next;
    if (next != NULL) {
        next->prev = prev;
    }
    
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
    list->tail = NULL;
}

void print_list_backward(t_list *list) {
    
    printf("[ ");
    t_cell *cell = list->tail;
    if (cell == NULL) {
        printf("]\n");
        return;
    }
    
    while(cell->prev != NULL) {
        printf("%d, ", cell->value);
        cell = cell->prev;
    }
    printf("%d ]\n", cell->value);
}

t_list map(T (*pf)(T), t_list *list) {
    t_list newlist = create_empty_list();
    
    t_cell *cell = list->head;
    while (cell != NULL) {
        push_back(&newlist, (*pf)(cell->value));
    }

    return newlist;
}