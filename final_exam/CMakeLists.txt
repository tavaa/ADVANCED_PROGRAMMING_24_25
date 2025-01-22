cmake_minimum_required(VERSION 3.15)
project(MusicLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(pybind11 REQUIRED)

pybind11_add_module(music_library
    music_library/bindings.cpp
)

target_link_libraries(music_library PRIVATE pybind11::module)

