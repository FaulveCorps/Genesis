@echo off
setlocal
set BUILD_DIR=build
set EXECUTABLE=Genesis.exe
set EXECUTABLE_PATH=%BUILD_DIR%\Executable\Debug\%EXECUTABLE%

echo [Genesis Build] Initializing Git Submodules...
git submodule update --init --recursive
if %ERRORLEVEL% neq 0 (
    echo [Error] Failed to initialize submodules.
    exit /b 1
)

echo [Genesis Build] Creating Build Directory...
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
cd %BUILD_DIR%

echo [Genesis Build] Generating Project with CMake...
cmake .. -G "Visual Studio 17 2022" -A x64
if %ERRORLEVEL% neq 0 (
    echo [Error] CMake configuration failed.
    exit /b 1
)

echo [Genesis Build] Building Project...
cmake --build . --config Debug
if %ERRORLEVEL% neq 0 (
    echo [Error] Build failed.
    exit /b 1
)

echo [Genesis Build] Checking Executable...
if exist %EXECUTABLE_PATH% (
    echo [Genesis Build] Launching %EXECUTABLE%...
    start "" "%EXECUTABLE_PATH%"
) else (
    echo [Error] Executable not found: %EXECUTABLE_PATH%
    exit /b 1
)

endlocal
