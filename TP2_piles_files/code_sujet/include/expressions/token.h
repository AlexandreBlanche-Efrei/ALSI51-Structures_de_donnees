#ifndef TOKEN_H
#define TOKEN_H

#include <stdbool.h>
#include "expressions/operator.h"

typedef enum {
    NUMBER, OPERATOR, PARENTHESIS
} token_type;

typedef struct {
    token_type type;
    int val;
    operator_type op;
    bool paren_type;
} t_token;

// Returns a token of type NUMBER containing the value val
t_token token_of_int(int val);

// Returns a token of type OPERATOR containing the operator op
t_token token_of_operator(operator_type op);

// Returns a token of type PARENTHESIS containing the parenthesis described by c = '(' or ')'
t_token token_of_parenthesis(char c);

// Returns true if the token is a left parenthesis
bool is_left_parenthesis(t_token *t);

// Returns true if the token is a right parenthesis
bool is_right_parenthesis(t_token *t);

// Prints the given token
void print_token(t_token *token);
#endif