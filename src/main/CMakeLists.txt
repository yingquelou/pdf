cmake_path(GET CMAKE_CURRENT_LIST_DIR STEM PROJ)
include_directories(..)
add_executable(${PROJ} test.cpp)