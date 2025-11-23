#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "structures/string_type.h"

#include <stdbool.h>

typedef string T;

typedef struct s_node {
    struct s_node *left;
    struct s_node *right;
    T value;
} t_node;

typedef struct {
    t_node *root;
    unsigned int size;
} string_tree;

string_tree create_empty_tree();

void insert_bst(string_tree *t, const T val);

bool search_in_tree(const string_tree *t, const T val);

void list_all_entries_tree(const string_tree *t);

//////////////////////////////////////

void insert_avl(string_tree *t, const T val);

//////////////////////////////////////

bool export_mermaid(const string_tree *t, const char *file_name);

void destroy_tree(string_tree *t);

#endif