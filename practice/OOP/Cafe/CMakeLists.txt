cmake_minimum_required(VERSION 3.10)

project(Cafe)

include_directories(D:/c++/data_structures/my_vector/src include)

add_executable(Cafe src/main.cpp src/menuItem.cpp src/order.cpp src/cafe.cpp src/cook.cpp src/waiter.cpp src/manager.cpp 
                                                                                                        src/employee.cpp)

target_sources(Cafe PRIVATE 
    D:/c++/data_structures/my_vector/src/mnsng_vector.h
)

