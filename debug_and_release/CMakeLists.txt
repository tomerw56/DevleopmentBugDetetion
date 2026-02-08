cmake_minimum_required(VERSION 3.20)
project(BuildConfigDemos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_executable(stl_bounds_demo stl_bounds_demo.cpp)
add_executable(iterator_invalid iterator_invalid.cpp)

if (MSVC)
    # Debug: enable extra runtime checks
    target_compile_options(stl_bounds_demo PRIVATE
        $<$<CONFIG:Debug>:/RTC1>
    )
endif()
