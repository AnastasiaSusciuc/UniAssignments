cmake_minimum_required(VERSION 3.17)
project(A3___DLLA_IteratedListFINALFINAL)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A3___DLLA_IteratedListFINALFINAL
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IteratedList.cpp
        IteratedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
