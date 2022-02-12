cmake_minimum_required(VERSION 3.9)
project(mts C)

set(CMAKE_C_STANDARD 99)

add_executable(mts main.c
        bloom.c
        bloom.h)