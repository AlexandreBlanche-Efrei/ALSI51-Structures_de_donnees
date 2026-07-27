cmake_minimum_required(VERSION 4.0)
project(TP1 C)

set(CMAKE_C_STANDARD 23)

include_directories(include/)

add_executable(TP1
        src/main.c
        src/list_array.c
)
