#include "tests/test_databases.h"

#include "auxiliary/random_string.h"
#include "auxiliary/t_time.h"

#include <stdio.h>

#define GENERATE_MEASURE_FUNC(type)                                 \
                                                                    \
    void measure_##type ##_method(const unsigned int n) {           \
                                                                    \
        database_##type db;                                         \
        db.data = create_empty_##type ();                           \
                                                                    \
        unsigned int rand = get_init_rand();                        \
        unsigned int denied = 0;                                    \
        const t_time start_time = start_timer();                    \
                                                                    \
        for (unsigned int i = 0; i < n; i++) {                      \
            const string s = get_next_random_string(&rand);         \
            if (!is_in_database_##type (&db, s))                    \
                insert_in_database_##type (&db, s);                 \
            else                                                    \
                denied++;                                           \
        }                                                           \
                                                                    \
        const t_time duration_insertion = end_timer(start_time);    \
        printf("%s method\n", #type);                               \
        printf("Time elapsed: ");                                   \
        print_time(duration_insertion);                             \
        printf("Number of elements tested: %u\n", n);               \
        printf("Strings added: %u\n", db.data.size);                \
        printf("Denied: %u (%u%%)\n", denied, 100 * denied / n);    \
        printf("----------------------\n");                         \
    }                                                               \

GENERATE_MEASURE_FUNC(array);

GENERATE_MEASURE_FUNC(tree);

GENERATE_MEASURE_FUNC(prefix_tree);