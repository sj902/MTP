cmake_minimum_required(VERSION 3.9)
project(bloomTree)

set(CMAKE_CXX_STANDARD 11)

add_executable(bloomTree
        bloom.c
        bestLevel.c)
