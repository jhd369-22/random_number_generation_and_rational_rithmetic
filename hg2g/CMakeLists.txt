cmake_minimum_required(VERSION 3.10)

# set the project name
project(hg2g LANGUAGES CXX)

# include directory
include_directories(include)

# add subdirectories
add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(src)
