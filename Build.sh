#!/bin/bash
set -e

CURRENT_DIR=$(pwd)

echo "[Genesis Build] Cloning Necessary Repositories..."

check_and_repair_submodule() {
  MODULE=$1
  URL=$2
  FOLDER="External/$MODULE"
  GITMODULES_PATH=".git/modules/External/$MODULE"

  if [ ! -d "$FOLDER" ] || [ -z "$(ls -A "$FOLDER" 2>/dev/null)" ]; then
    echo "[Genesis Build] $MODULE submodule folder is missing or empty. Repairing..."
    git submodule deinit -f "$FOLDER" 2>/dev/null || true
    rm -rf "$FOLDER"
    rm -rf "$GITMODULES_PATH"
    git submodule add "$URL" "$FOLDER"
  else
    echo "[Genesis Build] $MODULE submodule already exists."
  fi
}

check_and_repair_submodule "SDL"  "https://github.com/libsdl-org/SDL.git"
check_and_repair_submodule "Json" "https://github.com/nlohmann/json.git"
check_and_repair_submodule "Glfw" "https://github.com/glfw/glfw.git"

echo "[Genesis Build] Building SDL3 (static)..."
cmake -B External/SDL/build -S External/SDL -DSDL_STATIC=ON -DSDL_SHARED=OFF -DSDL_TEST=OFF
cmake --build External/SDL/build --config Release

mkdir -p Build
cd Build

echo "[Genesis Build] Configuring Genesis CMake..."
cmake .. -DSDL_STATIC=ON -DSDL_SHARED=OFF

echo "[Genesis Build] Building Genesis Game..."
cmake --build . --config Release

BIN="./bin/Release/GenesisGame"
if [ -f "$BIN.exe" ]; then
  echo "[Genesis Build] Build complete. Launching game..."
  "$BIN.exe"
elif [ -f "$BIN" ]; then
  echo "[Genesis Build] Build complete. Launching game..."
  "$BIN"
else
  echo "[Genesis Build] Build succeeded, but executable not found."
fi

cd "$CURRENT_DIR"
