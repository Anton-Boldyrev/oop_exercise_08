


cmake_minimum_required(VERSION 3.5.1)
project(oop_exercise_08)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g3 -Wextra -pthread")

add_executable(oop_exercise_08 main.cpp point.cpp rectangle.cpp trapezoid.cpp rhombus.cpp)




