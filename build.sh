#!/bin/bash

BUILD_DIR="build"
BUILD_CONAN_DIR="$BUILD_DIR/conan"

echo "Making sure build directory exists..."
if [ ! -d "$BUILD_DIR" ]; then
    echo "Build directory does not exist. Creating it now..."
    mkdir -p "$BUILD_DIR"
    echo "Build directory created!"
fi

echo "Installing dependencies..."
conan install . --build=missing --output-folder=$BUILD_CONAN_DIR

echo "Building project..."
cmake -S . -B "$BUILD_DIR" \
    -DCMAKE_TOOLCHAIN_FILE="$BUILD_CONAN_DIR/conan_toolchain.cmake" \
    -DCMAKE_PREFIX_PATH="$PWD/$BUILD_CONAN_DIR" \
    -DCMAKE_BUILD_TYPE=Release
cmake --build "$BUILD_DIR"