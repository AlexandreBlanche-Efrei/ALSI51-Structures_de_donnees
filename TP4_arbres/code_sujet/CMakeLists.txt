cmake_minimum_required(VERSION 4.0)
project(TP4 C)

set(CMAKE_C_STANDARD 23)

add_compile_options(-O3)
add_compile_options(-fshort-enums)
include_directories(include/)

add_executable(TP4
        src/main.c
        src/structures/array.c
        src/structures/bin_tree.c
        src/structures/prefix_tree.c
        src/structures/string_type.c
        src/auxiliary/random_string.c
        src/auxiliary/t_time.c
        src/database/database_array.c
        src/database/database_tree.c
        src/database/database_prefix_tree.c
        src/tests/test_databases.c
        src/tests/test_structures.c
)
