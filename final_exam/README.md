# Exam 11.02.2025 - Music Library

This project contains the material for the written exam of the *Advanced Programming course* for the academic year 2024-25. This course is offered jointly by SISSA (International School for Advanced Studies) and UniTS (Università degli Studi di Trieste), Trieste, Italy.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Structure](#structure)
- [Usage](#usage)
- [Implementation Choices](#implementation-choices)
- [Tested On](#tested-on)
- [Contributions](#contributions)
- [References](#references)

## Introduction

The goal of this framework is to design and build a database to manage music player entities such as songs albums and playlists. Each of these will have unique attributes and behaviours but they also share some common functionalities.

## Features

* Database for several music entities types.
* Interactive script for testing functionalities in c++.
* easy to build and intuitive.
* Advanced function to shuffle music within playlists.

## Prerequisites

- C++ compiler (e.g., g++).
- cmake (3.15 MINIMUM REQUIRED)
- Python3. (built with python 3.10.16)
- Pybind11 (pybind11-dev 2.9.1-2)

## Structure

- `music_library/`: Contains source files
    - `bindings.cpp`: Contains the C++ binding
    - `Album.hpp`: Contains derived class album
    - `Database.hpp`: Contains generic container class for several types T
    - `Song.hpp`: Contains derived class song
    - `Playlist.hpp`: Contains derived class playlist
    - `MusicEntity`: Contains abstract base class
    - `main.cpp`: iterative Script to test the source C++ code.
- `build/`: Contains binary files and libraries.
- `CMakeLists.txt`: cmake file to build the project.
- `main.py`: Script to explore the use of the python code.
- `run_test_source.sh`: Script for run the test of source code.
- `build_project.sh`: Script for building the project.


## Usage

1. **Clone or Download the Repository**  

   ```bash
   git clone https://github.com/tavaa/ADVANCED_PROGRAMMING_24_25.git
   cd ADVANCED_PROGRAMMING_24_25/final_exam/
   ```

2. **Build the Project and Run tests**  

   *cmake*

   In order to build the module, run the bash script that works with CMakeLists.txt

   ```bash
   chmod +x build_project.sh
   ./build_project.sh
   ```
   Once the script has been executed, you will find something like "*.cpython-310-x86_64-linux-gnu.so" on the `build/` directory.

    *test source code*

    To exploit the original C++ source code used in this project, you need to authorize and execute `run_test_source.sh` shell script.

    ```bash
    chmod +x run_test_source.sh
    ./run_test_source.sh
    ```

    The output in the terminal will be the interactive test developed within the `main.cpp` script.

   *run test bindings*
   
   To exploit the C++/python bindings used in this project, you need to execute `main.py` script.

    ```python
    python main.py
    ```
   
## Implementation Choices

* The framework was designed with a modular approach, separating the module functionalities into distinct classes for songs, albums, and playlists, all inheriting from a common base class `MusicEntity`. 
* This ensures code reusability and maintainability. 
* The `Database` class template was implemented to manage collections of these entities, with a specialization for playlists to support shuffling.  * The use of CMake simplifies the build process, and pybind11 was employed to create Python bindings, making the library accessible from both C++ and Python. 
* Various scripts for testing and building are deployed, with the use of shell script to make easy the tests.


## Tested on

The whole project has been developed and tested on Ubuntu 22.04.3 LTS (WSL)

## Contributions

**Author**
* Tavano Matteo <matteo.tavano@studenti.units.it>

## References 

1. Advanced Programming course: https://github.com/pcafrica/advanced_programming_2024-2025
