cmake_minimum_required(VERSION 3.16)
project(GameOfLife LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GameOfLife
    main.cpp
    GameOfLife.cpp
    GameOfLife.h
)

target_include_directories(GameOfLife PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
    target_compile_options(GameOfLife PRIVATE /W4)
else()
    target_compile_options(GameOfLife PRIVATE -Wall -Wextra -Wpedantic)
endif()
