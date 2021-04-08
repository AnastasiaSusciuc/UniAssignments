cmake_minimum_required(VERSION 3.17)
project(c__)

set(CMAKE_CXX_STANDARD 14)

add_executable(c__ main.cpp Graphs/DirectedGraph.cpp Graphs/DirectedGraph.h TestDG/testDG.cpp TestDG/testDG.h Externals/external_functions.cpp Externals/external_functions.h)