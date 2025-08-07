#!/bin/bash

# Set preset here; match your CMakePresets.json names
PRESET=debug

echo "[CMake] Configuring project with preset '$PRESET'..."
cmake --preset "$PRESET"
if [ $? -ne 0 ]; then
    echo "[Error] CMake configure failed."
    exit 1
fi

echo "[CMake] Building project..."
cmake --build --preset "build-$PRESET"
if [ $? -ne 0 ]; then
    echo "[Error] Build failed."
    exit 1
fi

# Optional: run your executable (adjust path as needed)
echo "[Run] Launching Sandbox..."
MODE=Debug
./bin/$MODE/Sandbox/Sandbox
