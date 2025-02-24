cmake_minimum_required(VERSION 3.10)

project(StudentManagement VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(StudentManagement src/main.cpp src/Student.cpp)                                      