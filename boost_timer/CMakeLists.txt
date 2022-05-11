cmake_minimum_required(VERSION 3.23)

# set the project name
project(timer LANGUAGES CXX)

# set Debug build type
set(CMAKE_BUILD_TYPE Debug)

# find the required libraries
set(Boost_USE_MULTITHREADED false)
find_package(Boost 1.54.0 REQUIRED COMPONENTS timer)

# add the library
add_library(fibonacci fibonacci.cpp fibonacci.hpp)

# add the executable
add_executable(timer timer.cpp)

# Method 1: Use include-directories and library variables.
# Note: We need to specify include directories.
#target_include_directories(timer PUBLIC ${Boost_INCLUDE_DIRS})
#target_link_libraries(timer ${Boost_TIMER_LIBRARY} fibonacci)

# Method 2: Use imported targets
# Note: We do not need to specify include directories.
target_link_libraries(timer Boost::timer fibonacci)
