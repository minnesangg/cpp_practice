cmake_minimum_required(VERSION 3.10)

project(Company VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Company src/main.cpp src/intern.cpp src/employee.cpp src/manager.cpp src/engineer.cpp)                                      