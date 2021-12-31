cmake_minimum_required(VERSION 3.16)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(Matrix main.cpp matrix.h matrix.cpp SLAU.h SLAU.cpp)