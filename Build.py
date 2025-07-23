import os
import platform
import subprocess
import pathlib
import sys

def run_command(command, error_message):
    """Run a shell command and exit on failure."""
    try:
        result = subprocess.run(command, check=True, text=True, capture_output=True)
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"{error_message}: {e.stderr}")
        sys.exit(1)

def main():
    # Store current directory
    current_dir = pathlib.Path.cwd()
    print("[Genesis Build] Current directory:", current_dir)

    # Detect platform
    is_windows = platform.system() == "Windows"
    is_macos = platform.system() == "Darwin"
    is_linux = platform.system() == "Linux"

    # Define paths
    sdl_dir = current_dir / "External" / "SDL"
    json_dir = current_dir / "External" / "Json"
    build_dir = current_dir / "Build"
    executable_path = build_dir / "bin" / "Release" / ("GenesisGame.exe" if is_windows else "GenesisGame")
    app_bundle_path = build_dir / "bin" / "Release" / "GenesisGame.app"

    # Clone SDL3 submodule
    print("[Genesis Build] Cloning SDL3...")
    if not sdl_dir.exists():
        run_command(
            ["git", "submodule", "add", "https://github.com/libsdl-org/SDL.git", "External/SDL"],
            "[Genesis Build] Failed to add SDL submodule"
        )
    else:
        print("[Genesis Build] SDL submodule already exists.")

    # Clone Json submodule
    print("[Genesis Build] Cloning Json...")
    if not json_dir.exists():
        run_command(
            ["git", "submodule", "add", "https://github.com/nlohmann/json.git", "External/Json"],
            "[Genesis Build] Failed to add Json submodule"
        )
    else:
        print("[Genesis Build] Json submodule already exists.")

    # Optionally kill interfering Git processes (Windows-specific, skipped on Linux/macOS unless needed)
    if is_windows:
        for proc in ["Code.exe", "git-gui.exe", "git.exe", "git-bash.exe", "gitk.exe"]:
            try:
                subprocess.run(["taskkill", "/F", "/IM", proc], check=True, capture_output=True)
            except subprocess.CalledProcessError:
                pass  # Ignore if process not found

    # Build SDL3 (Static)
    print("[Genesis Build] Building SDL3 (static)...")
    sdl_build_dir = sdl_dir / "build"
    cmake_args = [
        "cmake", "-B", str(sdl_build_dir), "-S", str(sdl_dir),
        "-DSDL_STATIC=ON", "-DSDL_SHARED=OFF", "-DSDL_TEST=OFF"
    ]
    if not is_windows:
        cmake_args.append("-DCMAKE_BUILD_TYPE=Release")
    run_command(cmake_args, "[Genesis Build] Failed to configure SDL3")
    build_args = ["cmake", "--build", str(sdl_build_dir)]
    if is_windows:
        build_args.append("--config")
        build_args.append("Release")
    run_command(build_args, "[Genesis Build] Failed to build SDL3")

    # Ensure Build directory exists
    if not build_dir.exists():
        build_dir.mkdir()
        print("[Genesis Build] Created Build directory")

    # Configure Genesis CMake
    print("[Genesis Build] Configuring Genesis CMake...")
    os.chdir(build_dir)
    cmake_args = ["cmake", "..", "-DSDL_STATIC=ON", "-DSDL_SHARED=OFF"]
    if not is_windows:
        cmake_args.append("-DCMAKE_BUILD_TYPE=Release")
    run_command(cmake_args, "[Genesis Build] CMake configuration failed")

    # Build Genesis Game
    print("[Genesis Build] Building Genesis Game...")
    build_args = ["cmake", "--build", "."]
    if is_windows:
        build_args.append("--config")
        build_args.append("Release")
    run_command(build_args, "[Genesis Build] Failed to build Genesis Game")

    # Run the built game if successful
    if executable_path.exists():
        print("[Genesis Build] Build complete. Launching game...")
        if not is_windows:
            os.chmod(executable_path, 0o755)  # Ensure executable permissions on Linux/macOS
        run_command([str(executable_path)], "[Genesis Build] Failed to run game")
    elif is_macos and app_bundle_path.exists():
        print("[Genesis Build] Build complete. Launching macOS app...")
        run_command(["open", str(app_bundle_path)], "[Genesis Build] Failed to launch macOS app")
    else:
        print("[Genesis Build] Build succeeded, but executable or app bundle not found.")

    # Return to original directory
    os.chdir(current_dir)

if __name__ == "__main__":
    main()