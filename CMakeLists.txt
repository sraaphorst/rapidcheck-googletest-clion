cmake_minimum_required(VERSION 3.14)
project(rapidcheck_setup)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)
add_executable(rapidcheck_setup main.cpp)