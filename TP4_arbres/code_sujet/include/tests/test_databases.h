#ifndef TEST_DB_H
#define TEST_DB_H

#include "database/database_array.h"
#include "database/database_tree.h"
#include "database/database_prefix_tree.h"

void measure_array_method(const unsigned int n);

void measure_tree_method(const unsigned int n);

void measure_prefix_tree_method(const unsigned int n);

#endif