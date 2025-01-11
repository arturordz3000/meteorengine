#!/bin/bash

BUILD_DIR="build"
BUILD_CONAN_DIR="$BUILD_DIR/conan"

echo "Making sure build directory exists..."
if [ ! -d "$BUILD_DIR"]; then
    echo "Build directory does not exist. Creating it now..."
    mkdir -p "$BUILD_DIR"
    echo "Build directory created!"
fi

echo "Installing dependencies..."
conan install . --build=missing --output-folder=$BUILD_CONAN_DIR

echo "Building project..."
cmake -DCMAKE_TOOLCHAIN_FILE=build/conan/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=release
cmake -S . -B ./build 
cmake --build ./build