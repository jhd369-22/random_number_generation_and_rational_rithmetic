cmake_minimum_required(VERSION 3.10)

# set the project name
project(buggy LANGUAGES CXX)

# include the file containing the sanitizer option
include(Sanitizers.cmake)

# add the executable
add_executable(buggy buggy.cpp)
