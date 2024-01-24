cmake_minimum_required(VERSION 3.5)
project(pdf VERSION 0.1.0 LANGUAGES C CXX)

string(REPEAT "-" 80 SPLITLINE)


set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
    message("${SPLITLINE}")
    message("${CMAKE_BINARY_DIR}")
    message("${SPLITLINE}")
add_executable(pdf main.cpp)