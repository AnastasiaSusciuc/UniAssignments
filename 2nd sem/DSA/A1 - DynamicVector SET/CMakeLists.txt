cmake_minimum_required(VERSION 3.17)
project(A1___DynamicVector_SET)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A1___DynamicVector_SET
        App.cpp
        src/ExtendedTest/ExtendedTest.cpp
        src/ExtendedTest/ExtendedTest.h
        src/Set/Set.cpp
        src/Set/Set.h
        src/SetIterator/SetIterator.cpp
        src/SetIterator/SetIterator.h
        src/ShortTest/ShortTest.cpp
        src/ShortTest/ShortTest.h src/Set/set_v2.cpp)
