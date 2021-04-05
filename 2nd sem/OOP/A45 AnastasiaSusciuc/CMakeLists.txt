cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp UI/UI.h UI/UI.cpp Tests/tests.h Tests/tests.cpp Service/AdminService.h Service/AdminService.cpp Repository/TutorialsRepository.h Repository/TutorialsRepository.cpp DynamicVector/DynamicVector.h DynamicVector/DynamicVector.cpp Domain/tutorial.h Domain/tutorial.cpp Service/UserService.cpp Service/UserService.h Repository/WatchListRepository.cpp Repository/WatchListRepository.h)