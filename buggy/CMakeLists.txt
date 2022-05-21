cmake_minimum_required(VERSION 3.23)

# set the project name
project(buggy LANGUAGES CXX)

# set Debug build type
set(CMAKE_BUILD_TYPE Debug)

# include the file containing the sanitizer option
include(Sanitizers.cmake)

# add the executable
add_executable(buggy buggy.cpp)
