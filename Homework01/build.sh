#!bin/bash

#directory paths
INCLUDE_DIR="include"
SRC_DIR="src"
BUILD_DIR="build"
EXECUTABLE="sparse_matrix"

#compilation of source files
g++ -std=c++17 -Wall -Wpedantic "$SRC_DIR/main.cpp"  "$SRC_DIR/SparseMatrixCOO.cpp" "$SRC_DIR/SparseMatrixCSR.cpp" -I"$INCLUDE_DIR" -o "$BUILD_DIR/$EXECUTABLE"

#check for successful compilation
if [[$? -ne 0]]; then
    echo "Compilation failed"
    exit 1
fi

#run executable
echo "Running sparse_matrix.exe"
cd $BUILD_DIR
./$EXECUTABLE