#include "auxiliary/random_string.h"

#include <stdio.h>
#include <stdlib.h>

// Pseudorandom string

int index_of_char(const char c) {
    return c - (c >= 'a' ? ('a' - 10) : '0');
}

int char_of_index(const int index) {
    return (index < 10) ? '0' + index : 'a' + index - 10;
}

string random_string() {

    static unsigned char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz";

    const unsigned int length = MIN_STRING_LENGTH + (((unsigned int) rand()) % (MAX_STRING_LENGTH - MIN_STRING_LENGTH));
    string s = (string) malloc((length + 1) * sizeof(unsigned char));
    for (unsigned int i = 0; i < length; i++) {
        const unsigned int index = ((unsigned int) rand()) % (sizeof(charset) - 1);
        s[i] = charset[index];
    }
    s[length] = '\0';
    return s;
}


// Predictible random string

#define MAX_RAND_VAL 3973976131u
//1313547u
// 20 bits of information
// we use the first 2 bytes

// const unsigned int A = 3791873u; //  1% denied
// const unsigned int A = 3791871u; // 80% denied
// const unsigned int B = 1098711;//17u;
// const unsigned int M = MAX_RAND_VAL;
// return (rand * A + B);
unsigned int get_next_rand(const unsigned int rand) {
    const unsigned int A = 3791873u;
    const unsigned int B = 1098711u;
    return (rand * A + B);
}

unsigned int get_init_rand() {
    return 343513213u;
}

string get_next_random_string(unsigned int *rand) {
    
    //return random_string();
    
    const unsigned int length = MIN_STRING_LENGTH + (*rand % (MAX_STRING_LENGTH - MIN_STRING_LENGTH));
    string s = (string) malloc((length + 2) * sizeof(unsigned char));


    const int nb_iter = (length / 3) + (length % 3 != 0);
    char *p = s;
    for (int i = 0; i < nb_iter; i++) {
        *rand = get_next_rand(*rand);
        const int index = 3 * i;
        s[index]     = char_of_index((*rand)        % CHAR_SET_SIZE);
        s[index + 1] = char_of_index((*rand >> 6)   % CHAR_SET_SIZE);
        s[index + 2] = char_of_index((*rand >> 12)  % CHAR_SET_SIZE);
    }
    s[length] = '\0';
    return s;
}