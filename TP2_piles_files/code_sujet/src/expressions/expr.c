#include "expressions/expr.h"
#include "structures/stack.h"
#include <stdio.h>
#include <stdlib.h>

// Returns true if the expression has no token left
bool is_empty_expr(t_expr *expr) {
    // TODO
    return true;
}

// Adds a token at the back of the expression
void add_token(t_expr *expr, T token) {
    // TODO
}

// Returns the token at the front of the expression
// and deletes it from the expression
T get_next_token(t_expr *expr) {
    // TODO
    t_token t;
    return t;
}

// Prints the content of the expression
void print_expr(t_expr *expr) {
    print_queue(&expr->token_queue);
}

///// Parsing

// Returns the int at the beginning of the string pointed at by p_s
// Moves p_s to after the int
int parse_int(char **p_s) {

    char *s = *p_s;
    int n = (*s) - '0';
    s++;
    while (*s >= '0' && *s <= '9') {
        n = 10 * n + (*s - '0');
        s++;
    }
    *p_s = s - 1;
    return n;
}

// Converts the string s to an expression of type t_expr
t_expr parse_expr(char *s) {

    t_expr expr;
    expr.token_queue = create_empty_queue();
    bool parsed_number = false;

    while (*s != '\0') {

        if (*s == ' ') {
            s++;
            continue;
        }
    
        t_token token;
        if (*s >= '0' && *s <= '9') {
            int n = parse_int(&s);
            token = token_of_int(n);
            parsed_number = true;
        }
        // Unary minus
        else if (!parsed_number && *s == '-') {
            s++;
            if (*s >= '0' && *s <= '9') {
                int n = parse_int(&s);
                token = token_of_int(-n);
                parsed_number = true;
            }
            else {
                printf("parse_expr: wrong syntax (\"%s\")\n", s);
                exit(EXIT_FAILURE);
            }
        }
        // Operator
        else if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '^') {
            token = token_of_operator(operator_of_char(*s));
            parsed_number = false;
        }
        else if (*s == '(' || *s == ')') {
            token = token_of_parenthesis(*s);
        }
        else {
            printf("parse_expr: wrong symbol %c (\"%s\")\n", *s, s);
            exit (EXIT_FAILURE);
        }

        add_token(&expr, token);
        s++;
    }

    return expr;
}

///// Evaluation

void error_rpn() {
    printf("Error: expression is not in Reverse Polish notation\n");
    exit(EXIT_FAILURE);
}

// Returns the result of the evaluation of the expression expr, in Reverse Polish notation
int eval_rpn(t_expr *expr) {

    t_stack stack = create_empty_stack();

    while (!is_empty_expr(expr)) {

        t_token token = get_next_token(expr);

        switch (token.type) {
            case NUMBER: {
                // TODO
                break;
            }
            case OPERATOR: {
                // TODO
                break;
            }
            default:
                error_rpn();
        }         
    }

    // TODO
    int res = 0; // TODO

    destroy_stack(&stack);
    return res;
}

// Converts an expression in infix notation to Reverse Polish notation
t_expr shunting_yard(t_expr *expr) {
    t_expr output;
    output.token_queue = create_empty_queue();
    t_stack op_stack = create_empty_stack();

    while (!is_empty_expr(expr)) {
        
        t_token t = get_next_token(expr);
        
        switch (t.type) {
            case NUMBER:
                // TODO
                break;
            case OPERATOR:
                // TODO
                // use function takes_priority, declared in operator.h, to be implemented in operator.c
                break;
            case PARENTHESIS:
                // TODO
                break;
        }
    }

    while (!is_empty_stack(&op_stack)) {
        // TODO
    }

    destroy_stack(&op_stack);
    return output;
}

// Returns the result of the evaluation of the expression expr in infix notation
int eval_expr(t_expr *expr) {
    // TODO
    return 0;
}

// Returns the result of the evaluation of the expression in infix notation represented by the string s
int eval(char *s) {
    // TODO
    return 0;
}