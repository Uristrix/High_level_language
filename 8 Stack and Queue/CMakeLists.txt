cmake_minimum_required(VERSION 3.16)
project(stack_queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(stack_queue main.cpp stack.h queue.h)