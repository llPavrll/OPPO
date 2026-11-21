cmake_minimum_required(VERSION 3.10)
project(lab1 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab1
        src/main.cpp
        src/real_estate.cpp
        src/real_estate.h
        src/real_estate_parser.cpp
        src/real_estate_parser.h
        src/sort_estates.cpp
        src/sort_estates.h
)