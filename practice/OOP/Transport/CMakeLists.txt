cmake_minimum_required(VERSION 3.10)

project(Transport VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Transport src/main.cpp src/car.cpp src/bicycle.cpp src/transport.cpp)                                      