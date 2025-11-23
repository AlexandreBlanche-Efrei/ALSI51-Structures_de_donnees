#include "expressions/token.h"
#include <stdio.h>

t_token token_of_int(int val) {
    t_token t;
    t.type = NUMBER;
    t.val = val;
    return t;
}

t_token token_of_operator(operator_type op) {
    t_token t;
    t.type = OPERATOR;
    t.op = op;
    return t;
}

t_token token_of_parenthesis(char c) {
    t_token t;
    t.type = PARENTHESIS;
    t.paren_type = (c == '(');
    return t;
}

// Returns true if the token is a left parenthesis
bool is_left_parenthesis(t_token *t) {
    return t->paren_type;
}
// Returns true if the token is a right parenthesis
bool is_right_parenthesis(t_token *t) {
    return !t->paren_type;
}

void print_token(t_token *token) {
    
    switch (token->type)
    {
        case NUMBER:
            printf("%d", token->val);
            break;
        case OPERATOR:
            print_operator(token->op);
            break;
        case PARENTHESIS:
            printf("%c", is_left_parenthesis(token) ? '(' : ')');
            break;
    }
}