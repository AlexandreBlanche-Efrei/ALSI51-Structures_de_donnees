#include "structures/algorithm.h"

#include <stdio.h>
#include <stdlib.h>


void export_csv(const char* file_name, algorithm *algos[], unsigned int nb_algos, unsigned int nb_samples, unsigned int step) {

    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("File could not be opened\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Size, ");
    unsigned int index_algo_init = 0;
    for (; index_algo_init < nb_algos - 1; index_algo_init++) {
        fprintf(file, "%s, ", algos[index_algo_init]->name);
    }
    fprintf(file, "%s\n", algos[index_algo_init]->name);
    for (unsigned int sample_number = 0; sample_number < nb_samples; sample_number++) {
        fprintf(file, "%u, ", (sample_number + 1) * step);
        unsigned int index_algo = 0;
        for (; index_algo < nb_algos - 1; index_algo++) {
            const t_time ti = algos[index_algo]->samples[sample_number];
            fprintf(file, "%ld.%06ld, ", (long int)ti.tv_sec, (long int)ti.tv_usec);
        }
        const t_time ti = algos[index_algo]->samples[sample_number];
        fprintf(file, "%ld.%06ld\n", (long int)ti.tv_sec, (long int)ti.tv_usec);
    }
    fclose(file);
}
