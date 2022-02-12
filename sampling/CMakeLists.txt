cmake_minimum_required(VERSION 3.9)
project(sampling)

set(CMAKE_CXX_STANDARD 11)

add_executable(sampling
        bloom.c
        bloom.h
        bloomTree.c
        bloomTree.h
        md5.c
        md5.h
        murmur.c
        sampleMultipleFromTree.c
        sampling.c
        thpool.c
        thpool.h)
