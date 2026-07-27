#ifndef EXPR_H
#define EXPR_H

#include "expressions/token.h"
#include "structures/queue.h"

typedef struct {
    t_queue token_queue;
} t_expr;

// Returns true if the expression has no token left
bool is_empty_expr(t_expr *expr);

// Adds a token at the back of the expression
void add_token(t_expr *expr, T token);

// Returns the token at the front of the expression and deletes it from the expression
T get_next_token(t_expr *expr);

// Prints the content of the expression
void print_expr(t_expr *expr);

int parse_int(char **p_s);

// Converts the string s to an expression of type t_expr
t_expr parse_expr(char *s);

// Returns the result of the evaluation of the expression expr, in Reverse Polish notation
int eval_rpn(t_expr *expr);

// Converts an expression in infix notation to Reverse Polish notation
t_expr shunting_yard(t_expr *expr);

// Returns the result of the evaluation of the expression expr, in infix notation
int eval_expr(t_expr *expr);

// Returns the result of the evaluation of the expression in infix notation represented by the string s
int eval(char *s);

#endif
