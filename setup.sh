#!/bin/bash

# Set preset here; match your CMakePresets.json names
PRESET=debug
CONFIG=Debug
BUILD_DIR="build/$PRESET"

if test -f "$BUILD_DIR/CMakeCache.txt"; then
        echo "[CMake] Already configured. Skipping configure step."
else
        echo "[CMake] Configuring project with preset $PRESET..."
        cmake --preset $PRESET
        if [ $? -ne 0 ]; then
                echo "[Error] Build failed."
                exit 1
        fi
fi

echo "[CMake] Building project..."
cmake --build --preset "build-$PRESET"
if [ $? -ne 0 ]; then
    echo "[Error] Build failed."
    exit 1
fi

# Optional: run your executable (adjust path as needed)
echo "[Run] Launching Sandbox..."
./bin/$CONFIG/Sandbox/Sandbox
