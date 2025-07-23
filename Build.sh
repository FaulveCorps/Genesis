#!/bin/bash

# Store current directory
CURRENT_DIR=$(pwd)

echo "[Genesis Build] Cloning SDL3..."

# Only add submodule if not already added
if [ ! -d "External/SDL" ]; then
    git submodule add https://github.com/libsdl-org/SDL.git External/SDL
else
    echo "[Genesis Build] SDL submodule already exists."
fi

cd "$CURRENT_DIR"
if [ ! -d "External/Json" ]; then
    git submodule add https://github.com/nlohmann/json.git External/Json
else
    echo "[Genesis Build] Json submodule already exists."
fi

cd "$CURRENT_DIR"

# Kill possible interfering Git processes (if needed)
pkill -f "code" > /dev/null 2>&1
pkill -f "git-gui" > /dev/null 2>&1
pkill -f "git" > /dev/null 2>&1
pkill -f "git-bash" > /dev/null 2>&1
pkill -f "gitk" > /dev/null 2>&1

# Build SDL3 (Static)
echo "[Genesis Build] Building SDL3 (static)..."
cmake -B External/SDL/build -S External/SDL -DSDL_STATIC=ON -DSDL_SHARED=OFF -DSDL_TEST=OFF
cmake --build External/SDL/build --config Release

# Ensure main Build directory exists
if [ ! -d "Build" ]; then
    mkdir Build
fi

echo "[Genesis Build] Configuring Genesis CMake..."
cd Build
cmake .. -DSDL_STATIC=ON -DSDL_SHARED=OFF

if [ $? -ne 0 ]; then
    echo "[Genesis Build] CMake configuration failed."
    exit 1
fi

echo "[Genesis Build] Building Genesis Game..."
cmake --build . --config Release

# Run the built game if successful
if [ -f "bin/Release/GenesisGame" ]; then
    echo "[Genesis Build] Build complete. Launching game..."
    ./bin/Release/GenesisGame
else
    echo "[Genesis Build] Build succeeded, but executable not found."
fi

cd "$CURRENT_DIR"