cmake_minimum_required(VERSION 4.0)
project(TP2 C)
 
set(CMAKE_C_STANDARD 23)
 
include_directories(include/)

add_executable(TP2
        src/main.c
        src/structures/stack.c
        src/structures/queue.c
        src/structures/list_double-ended.c
        src/expressions/operator.c
        src/expressions/token.c
        src/expressions/expr.c
)