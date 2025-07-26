cmake_minimum_required(VERSION 3.10)

project(BookingSystem VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(BookingSystem src/main.cpp src/booking_system.cpp src/hotel.cpp src/room.cpp)