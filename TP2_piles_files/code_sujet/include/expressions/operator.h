#ifndef OPERATOR_H
#define OPERATOR_H

#include <stdbool.h>

typedef enum {
    ADD, SUB, MULT, DIV
} operator_type;

operator_type operator_of_char(char c);

// Returns a op b
int apply_op(operator_type op, int a, int b);

// Prints operator op
void print_operator(operator_type op);

// Returns true if op2 takes priority over op1
bool takes_priority(operator_type op1, operator_type op2);
#endif