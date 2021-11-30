cmake_minimum_required(VERSION 3.20)
project(StackAndQueue)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        header/structures.h
        header/stack.tpp
)

set(PROJECT_SOURCES
        source/structures.cpp
)

add_executable(StackAndQueue main.cpp ${PROJECT_HEADERS} ${PROJECT_SOURCES})
