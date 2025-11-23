#ifndef DATABASE_H
#define DATABASE_H

#include "structures/array.h"

typedef struct {
    string_array data;
} database_array;

bool is_in_database_array(const database_array *db, const string s);
void insert_in_database_array(database_array *db, const string s);
void enumerate_database_array(const database_array *db);
#endif