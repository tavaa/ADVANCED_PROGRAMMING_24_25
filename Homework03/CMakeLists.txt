cmake_minimum_required(VERSION 3.15)
project(scientific_toolbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(pybind11 REQUIRED)

add_subdirectory(src)

