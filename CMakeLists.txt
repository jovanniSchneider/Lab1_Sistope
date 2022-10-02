cmake_minimum_required(VERSION 3.21)
project(Lab_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab_1 lab1.c functions.c padre.c hijo.c padre.h hijo.h game.h functions.h hash.h gameList.h)
