cmake_minimum_required(VERSION 3.20)
project(inheritance)
set(SOURCE_FILES src/main.cpp src/Account.cpp src/Account_Util.cpp src/Checking_Account.cpp src/Savings_Account.cpp src/Trust_Account.cpp)
include_directories(include)
add_executable(Inheritance ${SOURCE_FILES})