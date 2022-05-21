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

# The foreach command iterates over each item in each given list.
# The <items> following the ITEMS keyword are processed as in the
# first variant of the foreach command.
# The forms LISTS A and ITEMS ${A} are equivalent.

foreach(SRC_FILE IN LISTS SRC_LIST)
  # DIRECTORY = Directory without file name
  # NAME      = File name without directory
  # EXT       = File name longest extension (.b.c from d/a.b.c)
  # NAME_WE   = File name with neither the directory nor the longest extension
  # LAST_EXT  = File name last extension (.c from d/a.b.c)
  # NAME_WLE  = File name with neither the directory nor the last extension
  # PATH      = Legacy alias for DIRECTORY (use for CMake <= 2.8.11)

  get_filename_component(SRC_NAME ${SRC_FILE} NAME_WLE)

  # add the executable
  add_executable(${SRC_NAME} ${SRC_FILE})

  target_link_libraries(${SRC_NAME} PRIVATE CGAL::CGAL utility)
endforeach(SRC_FILE ${SRC_LIST})
