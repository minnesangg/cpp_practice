cmake_minimum_required(VERSION 3.10)

project(MinnesangVector)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_executable(minnesang_vector main.cpp src/mnsng_vector.h src/mnsng_vector_impl.h)

