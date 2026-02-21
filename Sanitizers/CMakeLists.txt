cmake_minimum_required(VERSION 3.16)
project(SanitizerDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_ASAN  "Enable AddressSanitizer" OFF)
option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" OFF)
option(ENABLE_TSAN  "Enable ThreadSanitizer" OFF)

set(SAN_FLAGS -g -O0 -fno-omit-frame-pointer)

if(ENABLE_ASAN)
    add_compile_options(${SAN_FLAGS} -fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

if(ENABLE_UBSAN)
    add_compile_options(${SAN_FLAGS} -fsanitize=undefined -fno-sanitize-recover=all)
    add_link_options(-fsanitize=undefined)
endif()

if(ENABLE_TSAN)
    add_compile_options(${SAN_FLAGS} -fsanitize=thread)
    add_link_options(-fsanitize=thread)
endif()

add_executable(asan_demo  src/asan_demo.cpp)
add_executable(ubsan_demo src/ubsan_demo.cpp)
add_executable(tsan_demo  src/tsan_demo.cpp)