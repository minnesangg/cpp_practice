cmake_minimum_required(VERSION 3.10)

project(Vehicles VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Vehicles src/main.cpp src/car.cpp src/motorcycle.cpp src/truck.cpp src/vehicle.cpp)                 