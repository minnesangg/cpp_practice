cmake_minimum_required(VERSION 3.10)

project(BookStore VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(BookStore src/main.cpp src/Book.cpp src/BookStore.cpp)     