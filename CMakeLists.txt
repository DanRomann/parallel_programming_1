cmake_minimum_required(VERSION 3.9)
project(lab1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES lab1.cpp lab2.cpp mpi.cpp)
add_executable(OpenMP_Lab1 ${SOURCE_FILES})