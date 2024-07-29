cmake_minimum_required(VERSION 3.10)
project(project_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(project_2 main.c defense.c defense.h playcard.c playcard.h showcard.c showcard.h initial.c initial.h shuffle.c shuffle.h cards.c cards.h)