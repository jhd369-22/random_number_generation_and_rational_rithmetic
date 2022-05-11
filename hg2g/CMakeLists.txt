cmake_minimum_required(VERSION 3.23)

# set the project name
project(hg2g LANGUAGES CXX)

# set Debug build type
set(CMAKE_BUILD_TYPE Debug)

# include directory
include_directories(include)

# add subdirectories
add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(src)
