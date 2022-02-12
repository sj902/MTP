cmake_minimum_required(VERSION 3.10)
project(GCE C)

set(CMAKE_C_STANDARD 99)

add_executable(GCE main.c doubly_linked_list.h adjacency.h bloom.h bloom.c)