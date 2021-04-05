cmake_minimum_required(VERSION 3.16)
project(A2___SLL_MultiMap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A2___SLL_MultiMap
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMMIterator.cpp
        SMMIterator.h
        SortedMultiMap.cpp
        SortedMultiMap.h)
