cmake_minimum_required(VERSION 3.15)
project(passenger C)

set(CMAKE_C_STANDARD 11)

add_executable(passenger main.c animal.c human.c human.h animal.h)