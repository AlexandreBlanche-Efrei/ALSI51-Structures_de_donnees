#include "auxiliary/tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms/selection_sort.h"
#include "algorithms/insertion_sort.h"
#include "algorithms/bubble_sort.h"
#include "algorithms/quick_sort.h"
#include "algorithms/merge_sort.h"

algorithm algo_selection = {"Selection sort", &selection_sort, NULL};
algorithm algo_insertion = {"Insertion sort", &insertion_sort, NULL};
algorithm algo_bubble = {"Bubble sort", &bubble_sort, NULL};
algorithm algo_quick = {"Quick sort", &quick_sort, NULL};
algorithm algo_merge = {"Merge sort", &merge_sort, NULL};

algorithm *algos[NB_ALGO] = {
    //&algo_selection,
    //&algo_insertion,
    //&algo_bubble,
    //&algo_quick,
    //&algo_merge
};

void measure_algorithms() {

    T t[ARRAY_SIZE];
    fill_random(t, ARRAY_SIZE);
    T t_test[ARRAY_SIZE];

    const unsigned int step = ARRAY_SIZE / (NB_SAMPLES + 1);

    printf("Starting tests\n");
    for (unsigned int index_algo = 0; index_algo < NB_ALGO; index_algo++) {
        algorithm *algo = algos[index_algo];
        printf("%s\n", algo->name);
        algo->samples = malloc(NB_SAMPLES * sizeof(t_time));
        unsigned int size = 0;

        for (unsigned int sample_number = 0; sample_number < NB_SAMPLES; sample_number++) {
            size += step;
            copy(t, t_test, 0, size - 1);
            t_time time_start = start_timer();
            (*algo->function)(t_test, size);
            algo->samples[sample_number] = end_timer(time_start);
            if (!is_sorted(t_test, size))
                raise_error(algo->name);
        }
    }
    printf("Done\n");

// Décommenter le #define pour passer en mode export
//#define EXPORT_CSV

#ifndef EXPORT_CSV
    /* TODO : affichage des samples dans la console */
#else
    /* TODO : export des données en CSV */
#endif

    // Free the allocated samples
    for (unsigned int index_algo = 0; index_algo < NB_ALGO; index_algo++) {
        const algorithm *algo = algos[index_algo];
        free(algo->samples);
    }
}

void test_algorithms() {

    const unsigned int size = ARRAY_SIZE;
    T t[ARRAY_SIZE];
    fill_random(t, size);

    printf("Original: ");
    print_array(t, size);
    printf("\n");
    for (unsigned int index_algo = 0; index_algo < NB_ALGO; index_algo++) {
        T t_test[ARRAY_SIZE];
        copy(t, t_test, 0, size - 1);
        algorithm *algo = algos[index_algo];
        (*algo->function)(t_test, size);
        printf("%s: ", algo->name);
        int nb = 14 - strlen(algo->name);
        for (int i = 0; i < nb; i++)
            printf(" ");
        print_array(t_test, size);

        if (!is_sorted(t_test, size))
            printf("%s error: array is not sorted\n", algo->name);
    }
}