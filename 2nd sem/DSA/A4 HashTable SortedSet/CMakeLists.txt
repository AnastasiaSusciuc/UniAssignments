cmake_minimum_required(VERSION 3.17)
project(A4_HashTable_SortedSet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A4_HashTable_SortedSet
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedSet.cpp
        SortedSet.h
        SortedSetIterator.cpp
        SortedSetIterator.h)
