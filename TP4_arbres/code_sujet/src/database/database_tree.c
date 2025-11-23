#include "database/database_tree.h"

#include <stdlib.h>

bool is_in_database_tree(const database_tree *db, const string s) {
    return search_in_tree(&db->data, s);
}

void insert_in_database_tree(database_tree *db, const string s) {
    insert_bst(&db->data, s);
}

void enumerate_database_tree(const database_tree *db) {
    list_all_entries_tree(&db->data);
}
