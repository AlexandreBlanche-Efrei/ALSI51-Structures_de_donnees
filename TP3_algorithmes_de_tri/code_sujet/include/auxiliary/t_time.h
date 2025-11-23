#ifndef TIME_H
#define TIME_H

#include <sys/time.h>

// For Windows compatibility
/*******************************************/
#define timersub(tvp, uvp, vvp)                                         \
 do {                                                            \
         (vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;          \
         (vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;       \
         if ((vvp)->tv_usec < 0) {                               \
                 (vvp)->tv_sec--;                                \
                 (vvp)->tv_usec += 1000000;                      \
         }                                                       \
 } while (0)
/*******************************************/

typedef struct timeval t_time;

t_time start_timer();

t_time end_timer(t_time t_start);

void print_time_concise(t_time ti);

void print_time(t_time ti);

void print_samples(t_time samples[], unsigned int size);

#endif