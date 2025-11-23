#ifndef DATABASE_TREE_H
#define DATABASE_TREE_H

#include "structures/bin_tree.h"

typedef struct {
    string_tree data;
} database_tree;

bool is_in_database_tree(const database_tree *db, const string s);
void insert_in_database_tree(database_tree *db, const string s);
void enumerate_database_tree(const database_tree *db);
#endif