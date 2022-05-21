cmake_minimum_required(VERSION 3.23)

# set the project name
project(coverage LANGUAGES CXX)

# set Debug build type
set(CMAKE_BUILD_TYPE Debug)

# define options for enabling the code coverage
# Note: To enable the option in CLI,
# use "-D ENABLE_COVERAGE=true" when generate the native build files
# e.g. "cmake -S . -B tmp -D ENABLE_COVERAGE=true"
option(ENABLE_COVERAGE false)

if(ENABLE_COVERAGE)
  # include the CodeCoverage.cmake file
  include(CodeCoverage.cmake)

  append_coverage_compiler_flags()
endif()

# add the executable
add_executable(random random.cpp)

if(ENABLE_COVERAGE)
  setup_target_for_coverage_lcov(
    NAME coverage
    EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/run_tests
    EXECUTABLE_ARGS ${CMAKE_CURRENT_BINARY_DIR}
    LCOV_ARGS -rc lcov_branch_coverage=1
    GENHTML_ARGS --branch-coverage DEPENDENCIES random)
    # Note: to build the coverage target:
    # use "--target coverage" to express the target you want to build
    # instead of the default target when generate the build code
    # e.g. "cmake --build tmp --target coverage"
endif()
