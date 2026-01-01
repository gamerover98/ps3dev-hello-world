cmake_minimum_required(VERSION 3.25.1)
project(ps3dev_hello_world)

set(CMAKE_CXX_STANDARD 14)

include_directories(source)

add_executable(
        ps3dev_hello_world
        source/main.cpp
        source/main.h)
