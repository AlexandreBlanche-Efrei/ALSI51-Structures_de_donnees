#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "expressions/operator.h"

// Returns the operator corresponding to the character c
operator_type operator_of_char(char c) {
    switch(c) {
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MULT;
        case '/':
            return DIV;
        default:
            exit(EXIT_FAILURE);
    }
}

// Returns a op b
int apply_op(operator_type op, int a, int b) {
    switch (op) {
        case ADD:
            return a + b;
        case SUB:
            return a - b;
        case MULT:
            return a * b;
        case DIV:
            if (b == 0) {
                printf("Error: division by zero\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        default:
            exit(EXIT_FAILURE);
    }
}

void print_operator(operator_type op) {
    char c;
    switch (op) {
        case ADD:
            c = '+';
            break;
        case SUB:
            c = '-';
            break;
        case MULT:
            c = '*';
            break;
        case DIV:
            c = '/';
            break;
    }
    printf("%c", c);
}


// Returns true if op2 takes priority over op1 in (a op2 b op1 c)
bool takes_priority(operator_type op1, operator_type op2) {
    // to do
}
