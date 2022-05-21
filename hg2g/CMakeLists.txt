cmake_minimum_required(VERSION 3.23)

# set the project name
project(hg2g LANGUAGES CXX)

# set Debug build type
set(CMAKE_BUILD_TYPE Debug)

# include directory
include_directories(include)

# add hg2g_lib library
add_library(hg2g_lib lib/answer.cpp lib/question.cpp)

# add the executable
add_executable(answer src/answer.cpp)

target_link_libraries(answer hg2g_lib)
