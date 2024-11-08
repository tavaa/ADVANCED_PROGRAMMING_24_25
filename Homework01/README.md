# Sparse Matrix Implementation in C++

This project contains the material for the first homework assignment of the *Advanced Programming course* for the academic year 2024-25. This course is offered jointly by SISSA (International School for Advanced Studies) and UniTS (Università degli Studi di Trieste), Trieste, Italy.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Structure](#structure)
- [Usage](#usage)
- [References](#references)

## Introduction

This project implements a Sparse Matrix in C++ using different storage formats such as COO (Coordinate List) and CSR (Compressed Sparse Row). Sparse matrices are used to efficiently represent and manipulate matrices that have a significant number of zero elements.

## Features

- **COO Format**: Easily add non-zero elements to the matrix using coordinate lists.
- **CSR Format**: Efficiently store and access non-zero elements for faster matrix-vector multiplication.
- **Basic Operations**: Support for basic operations such as creating, multiplying, and accessing elements within the matrix.
- **Error Handling**: Proper handling of out-of-bounds errors and invalid operations.

## Prerequisites

- C++ compiler (e.g., g++, clang++).
- CMake (optional, for building).
- Make (optional, if you are using Makefile).

## Structure

- `src/`: Contains source files
  - `SparseMatrixCOO.cpp`
  - `SparseMatrixCSR.cpp`
  - `main.cpp`
- `build/`: Directory for binary files
- `include/`: Contains header files
  - `SparseMatrixCOO.hpp`
  - `SparseMatrixCSR.hpp`
  - `SparseMatrix.hpp`
- `build.sh`: Script for building the project

## Usage

1. **Clone or download the repository**:
   

2. **Run build.sh**:

	Ensure to have right permission and run `build.sh` to compile the file and execute the code.

3. **Test functionalities inside main.cpp**:

	Use the examples within the `main.cpp` file to perform the various operations.


## References

1. Barrett, R., Berry, M., Chan, T. F., Demmel, J., Donato, J., Dongarra, J., ... & Van der Vorst, H. (1994). Templates for the Solution of Linear Systems: Building Blocks for Iterative Methods. Society for Industrial and Applied Mathematics.
2. Saad, Y. (2003). Iterative Methods for Sparse Linear Systems. Society for Industrial and Applied Mathematics.
3. Intel, "Sparse Matrix Storage Formats", disponibile su Intel Developer Zone.
4. Erase function: https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/ erase function.
5. Templates Usage: https://www.programiz.com/cpp-programming/class-templates
6. Assignement Repository: https://github.com/pcafrica/advanced_programming_2024-2025/tree/main

