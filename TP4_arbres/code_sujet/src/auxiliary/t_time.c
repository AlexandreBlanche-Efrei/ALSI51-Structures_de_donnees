#include "auxiliary/t_time.h"
#include <stdio.h>

t_time start_timer() {
    t_time t_start;
    gettimeofday(&t_start, NULL);
    return t_start;
}

t_time end_timer(t_time t_start) {
    t_time t_end, t_duration;
    gettimeofday(&t_end, NULL);
    timersub(&t_end, &t_start, &t_duration);
    return t_duration;
}

inline void print_time_concise(t_time ti) {
    printf("%ld.%06ld", (long int)ti.tv_sec, (long int)ti.tv_usec);
}

inline void print_time(t_time ti) {
    print_time_concise(ti);
    printf(" seconds\n");
}

void print_samples(t_time samples[], unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        print_time_concise(samples[i]);
        printf(" ");
    }
    printf("\n");
}