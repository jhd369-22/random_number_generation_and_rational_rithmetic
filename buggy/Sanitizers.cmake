# define options for enabling the Address Sanitizer(ASan) and
# the Undefined Behavior Sanitizer(UBSan).
# to enable the option in CLI, use "-D ENABLE_ASAN=true -D ENABLE_UBSAN=true"
option(ENABLE_ASAN false)
option(ENABLE_UBSAN false)

if(ENABLE_ASAN)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif()

if(ENABLE_UBSAN)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined")
endif()
