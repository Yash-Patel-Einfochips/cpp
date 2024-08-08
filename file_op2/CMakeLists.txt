cmake_minimum_required(VERSION 3.20)
project(file_op2)
# Copy test.txt to the binary directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/romeoandjuliet.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
add_executable(file_op2 main.cpp)