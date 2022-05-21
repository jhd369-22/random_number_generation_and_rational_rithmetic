cmake_minimum_required(VERSION 3.23)

# set the project name
project(fibonacci LANGUAGES CXX)

# set Debug build type
set(CMAKE_BUILD_TYPE Debug)

# add the library
add_library(fibonacci_lib fibonacci.cpp fibonacci.hpp)

# add the executable
add_executable(fibonacci main.cpp)

target_link_libraries(fibonacci fibonacci_lib)
