cmake_minimum_required(VERSION 3.3)
project(Stack_CPU)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Stack_CPU ${SOURCE_FILES})