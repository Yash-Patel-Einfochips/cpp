cmake_minimum_required(VERSION 3.20)
project(SharedLib)
include_directories(include)
add_library(SharedLib src/SharedHello.cpp)