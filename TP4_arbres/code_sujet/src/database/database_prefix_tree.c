#include "database/database_prefix_tree.h"

//#include <stdio.h>

bool is_in_database_prefix_tree(const database_prefix_tree *db, const string s) {
    return search_in_prefix_tree(&db->data, s);
}

void insert_in_database_prefix_tree(database_prefix_tree *db, const string s) {
    insert_in_prefix_tree(&db->data, s);
}

void enumerate_database_prefix_tree(const database_prefix_tree *db) {
    list_all_entries_prefix_tree(&db->data);
}