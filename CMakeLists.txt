cmake_minimum_required(VERSION 3.10)

project(Bank VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(Bank src/main.cpp)
