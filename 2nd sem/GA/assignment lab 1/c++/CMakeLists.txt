cmake_minimum_required(VERSION 3.17)
project(c__)

set(CMAKE_CXX_STANDARD 14)

add_executable(c__ main.cpp Graphs/DirectedGraph.cpp Graphs/DirectedGraph.h Externals/read_write.cpp Externals/random_graph.cpp TestDG/testDG.cpp TestDG/testDG.h)