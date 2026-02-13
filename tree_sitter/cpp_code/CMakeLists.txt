cmake_minimum_required(VERSION 3.15)
project(cpp_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_demo
    src/main.cpp
    src/calculator.cpp
    src/parser.cpp
)
