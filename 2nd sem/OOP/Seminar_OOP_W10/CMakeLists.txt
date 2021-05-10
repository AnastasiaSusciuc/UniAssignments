cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP main.cpp tests/test.cpp tests/test.h Domain/IComponent.cpp Domain/IComponent.h Domain/IBasicComponent.cpp Domain/IBasicComponent.h Domain/BasicComponent.cpp Domain/BasicComponent.h Domain/IBorderedComponent.cpp Domain/IBorderedComponent.h Domain/BorderedComponent.cpp Domain/BorderedComponent.h Domain/ILayout.cpp Domain/ILayout.h Domain/HorizontalLayout.cpp Domain/HorizontalLayout.h Domain/VerticalLayout.cpp Domain/VerticalLayout.h Domain/Label.cpp Domain/Label.h)