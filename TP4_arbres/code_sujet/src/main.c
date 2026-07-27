#include <stdio.h>

#include "tests/test_databases.h"
#include "tests/test_structures.h"

int main() {

    #define N_STRINGS 100000
    for (int nb_strings = 10; nb_strings <= N_STRINGS; nb_strings *= 10) {
        measure_array_method(nb_strings);
    //  measure_tree_method(nb_strings);
    //  measure_prefix_tree_method(nb_strings);
        printf("----------------------\n");

        if (nb_strings < N_STRINGS) {
            measure_array_method(5 * nb_strings);
        //  measure_tree_method(5 * nb_strings);
        //  measure_prefix_tree_method(5 * nb_strings);
            printf("----------------------\n");
        }
    }
    
    // test structures
    // test_bin_tree();

    // test_prefix_tree();

    return 0;
}