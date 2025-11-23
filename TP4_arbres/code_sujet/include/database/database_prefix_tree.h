#ifndef DATABASE_PREFIX_TREE_H
#define DATABASE_PREFIX_TREE_H

#include "structures/prefix_tree.h"

typedef struct {
    prefix_tree data;
} database_prefix_tree;

bool is_in_database_prefix_tree(const database_prefix_tree *db, const string s);
void insert_in_database_prefix_tree(database_prefix_tree *db, const string s);
void enumerate_database_prefix_tree(const database_prefix_tree *db);
#endif