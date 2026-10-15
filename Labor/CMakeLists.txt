cmake_minimum_required(VERSION 4.3)
project(Labor)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor_01 main.cpp
        defs.h
        person.cpp
        person.h
        customer.cpp
        customer.h)
