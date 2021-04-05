cmake_minimum_required(VERSION 3.17)
project(fixed_kmap_dsa)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fixed_kmap_dsa
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        FixedCapBiMap.cpp
        FixedCapBiMap.h
        FixedCapBiMapIterator.cpp
        FixedCapBiMapIterator.h
        ShortTest.cpp
        ShortTest.h)
