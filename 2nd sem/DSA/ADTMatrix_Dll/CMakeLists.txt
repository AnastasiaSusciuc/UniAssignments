cmake_minimum_required(VERSION 3.16)
project(ADTMatrix_DLL)

set(CMAKE_CXX_STANDARD 14)

add_executable(ADTMatrix_DLL
        App.cpp
        ExtendedTest.h
        ExtendedTest.cpp
        ShortTest.h
        ShortTest.cpp
        Matrix.h
        Matrix.cpp
        MatrixIterator.cpp
        MatrixIterator.h
        )