#ifndef PREFIX_TREE_H
#define PREFIX_TREE_H

#include "auxiliary/random_string.h"

typedef struct s_prefix_node {
    struct s_prefix_node **table;
    bool table_empty;
    bool is_present;
} prefix_node;

typedef struct {
    prefix_node *root;
    unsigned int size;
} prefix_tree;

prefix_tree create_empty_prefix_tree();

void insert_in_prefix_tree(prefix_tree *t, const string s);

bool search_in_prefix_tree(const prefix_tree *t, const string s);

void list_all_entries_prefix_tree(const prefix_tree *t);

//////////////////////////////////////

bool export_mermaid_prefix_tree(const prefix_tree *t, const char *file_name);

void destroy_prefix_tree(prefix_tree *t);

#endif