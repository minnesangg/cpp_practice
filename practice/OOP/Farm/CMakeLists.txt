cmake_minimum_required(VERSION 3.10)

project(Farm)

include_directories(D:/c++/data_structures/my_vector/src include)

add_executable(Farm src/main.cpp src/animal.cpp src/farm.cpp src/farmEntity.cpp src/plant.cpp)

target_sources(Farm PRIVATE 
    D:/c++/data_structures/my_vector/src/mnsng_vector.h
)

