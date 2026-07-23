cmake_minimum_required(VERSION 3.16)
project(GameOfLife LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GameOfLife
    src/main.cpp
    src/GameOfLife.cpp
    include/GameOfLife.h
)

target_include_directories(GameOfLife PRIVATE include)

if(MSVC)
    target_compile_options(GameOfLife PRIVATE /W4)
else()
    target_compile_options(GameOfLife PRIVATE -Wall -Wextra -Wpedantic)
endif()