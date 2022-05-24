cmake_minimum_required(VERSION 3.23)

# set the project name
project(test_code LANGUAGES CXX)

# set Debug build type
set(CMAKE_BUILD_TYPE Debug)

# find catch2
find_package(Catch2 REQUIRED)

# include directory
include_directories(include)

# add library
add_library(random_lib lib/random.cpp include/random.hpp)

add_library(rational_lib include/rational.hpp)

# add executable
add_executable(test_random app/test_random.cpp)
target_link_libraries(test_random random_lib Catch2::Catch2)

add_executable(test_rational app/test_rational.cpp)
target_link_libraries(test_rational rational_lib Catch2::Catch2)



