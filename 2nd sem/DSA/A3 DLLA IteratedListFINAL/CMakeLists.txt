cmake_minimum_required(VERSION 3.17)
project(A3_DLLA_IteratedListFINAL)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A3_DLLA_IteratedListFINAL
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IteratedList.cpp
        IteratedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
