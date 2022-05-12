cmake_minimum_required(VERSION 3.23)

# set the project name
project(cgal_in_circle LANGUAGES CXX)

# set Debug build type
set(CMAKE_BUILD_TYPE Debug)

# find the CGAL libraries
find_package(CGAL REQUIRED)

# GCC need compile option
add_compile_options("-frounding-math")

# set SRC_LIST
set(SRC_LIST in_circle.cpp in_sphere.cpp)

# add the library
add_library(utility utility.cpp utility.hpp)

foreach(SRC_FILE ${SRC_LIST})
  get_filename_component(SRC_NAME ${SRC_FILE} NAME_WLE)

  # add the executable
  add_executable(${SRC_NAME} ${SRC_FILE})
  target_link_libraries(${SRC_NAME} PRIVATE CGAL::CGAL utility)
endforeach(SRC_FILE ${SRC_LIST})
