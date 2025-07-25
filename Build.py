import os
import shutil
import subprocess
from pathlib import Path

# Configurable paths
PROJECT_DIR = Path(__file__).resolve().parent
EXTERNAL_DIR = PROJECT_DIR / "External"
BUILD_DIR = PROJECT_DIR / "Build"
SDL_BUILD_DIR = EXTERNAL_DIR / "SDL" / "build"
BIN_PATH = BUILD_DIR / "bin" / "Release" / "GenesisGame"

SUBMODULES = {
    "SDL":  "https://github.com/libsdl-org/SDL.git",
    "Json": "https://github.com/nlohmann/json.git",
    "Glfw": "https://github.com/glfw/glfw.git"
}

def run(cmd, cwd=None, check=True):
    print(f"> {cmd}")
    subprocess.run(cmd, cwd=cwd, check=check, shell=True)

def check_and_repair_submodule(name, url):
    folder = EXTERNAL_DIR / name
    gitmodule_path = PROJECT_DIR / ".git" / "modules" / "External" / name

    if not folder.exists() or not any(folder.iterdir()):
        print(f"[Genesis Build] {name} submodule folder missing or empty. Repairing...")
        try:
            run(f"git submodule deinit -f External/{name}")
        except subprocess.CalledProcessError:
            pass  # Allow if deinit fails (was never initialized)
        shutil.rmtree(folder, ignore_errors=True)
        shutil.rmtree(gitmodule_path, ignore_errors=True)
        run(f"git submodule add {url} External/{name}")
    else:
        print(f"[Genesis Build] {name} submodule already exists.")

def build_sdl():
    print("[Genesis Build] Building SDL3 (static)...")
    run(f"cmake -B {SDL_BUILD_DIR} -S {EXTERNAL_DIR / 'SDL'} -DSDL_STATIC=ON -DSDL_SHARED=OFF -DSDL_TEST=OFF")
    run(f"cmake --build {SDL_BUILD_DIR} --config Release")

def configure_genesis():
    BUILD_DIR.mkdir(exist_ok=True)
    print("[Genesis Build] Configuring Genesis CMake...")
    run(f"cmake .. -DSDL_STATIC=ON -DSDL_SHARED=OFF", cwd=BUILD_DIR)

def build_genesis():
    print("[Genesis Build] Building Genesis Game...")
    run(f"cmake --build . --config Release", cwd=BUILD_DIR)

def launch_game():
    if (BIN_PATH.with_suffix(".exe")).exists():
        print("[Genesis Build] Build complete. Launching game...")
        run(f'"{BIN_PATH.with_suffix(".exe")}"')
    elif BIN_PATH.exists():
        print("[Genesis Build] Build complete. Launching game...")
        run(f'"{BIN_PATH}"')
    else:
        print("[Genesis Build] Build succeeded, but executable not found.")

def main():
    print("[Genesis Build] Cloning Necessary Repositories...")
    for name, url in SUBMODULES.items():
        check_and_repair_submodule(name, url)

    build_sdl()
    try:
        configure_genesis()
    except subprocess.CalledProcessError:
        print("[Genesis Build] CMake configuration failed.")
        return

    build_genesis()
    launch_game()

if __name__ == "__main__":
    main()
