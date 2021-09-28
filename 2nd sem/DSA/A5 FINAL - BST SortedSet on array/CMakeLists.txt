cmake_minimum_required(VERSION 3.17)
project(A5___BST_SortedSet_as_SLLA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A5___BST_SortedSet_as_SLLA
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedSet.cpp
        SortedSet.h
        SortedSetIterator.cpp
        SortedSetIterator.h)
