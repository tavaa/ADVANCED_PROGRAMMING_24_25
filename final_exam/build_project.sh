#!/bin/bash

BUILD_DIR="build"

if [ ! -d "$BUILD_DIR" ]; then

    mkdir "$BUILD_DIR" && cd "$BUILD_DIR"
else

    cd "$BUILD_DIR"
fi

cmake ..

make -j4

cd ..
