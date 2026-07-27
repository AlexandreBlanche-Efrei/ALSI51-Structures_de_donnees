#include "structures/string_type.h"

int string_comp(const string s1, const string s2) {
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] < s2[i]) ? -1 : 1;
    }
    return 0;
}

bool string_eq(const string s1, const string s2) {
    return (string_comp(s1, s2) == 0);
}

unsigned int string_length(const string s) {
    int i = 0;
    for (; s[i] != '\0'; i++);
    return i;
}