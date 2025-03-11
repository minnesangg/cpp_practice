cmake_minimum_required(VERSION 3.10)

project(TaskManager VERSION 1.0)

include_directories(D:/c++/data_structures/my_vector/src include)

add_executable(TaskManager src/main.cpp src/task.cpp src/taskManager.cpp)     

target_sources(TaskManager PRIVATE 
    D:/c++/data_structures/my_vector/src/mnsng_vector.h
)

