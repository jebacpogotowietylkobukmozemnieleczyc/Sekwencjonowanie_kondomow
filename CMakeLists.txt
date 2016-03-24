cmake_minimum_required(VERSION 2.8.4)
project(bio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(bio ${SOURCE_FILES})