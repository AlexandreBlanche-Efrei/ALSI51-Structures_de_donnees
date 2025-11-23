#include "database/database_array.h"

#include <stdlib.h>

bool is_in_database_array(const database_array *db, const string s) {
    return search_in_array(&db->data, s);
}

void insert_in_database_array(database_array *db, const string s) {
    push_back(&db->data, s);
}

void enumerate_database_array(const database_array *db) {
    list_all_entries_array(&db->data);
}