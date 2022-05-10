# add hg2g_header library
add_library(hg2g_header hg2g/hg2g.hpp)

# set LINKER_LANGUAGE be C++
set_target_properties(hg2g_header PROPERTIES LINKER_LANGUAGE CXX)
