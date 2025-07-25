@echo off
setlocal enabledelayedexpansion
set CURRENT_DIR=%cd%

REM Kill possible interfering Git processes
taskkill /F /IM Code.exe >nul 2>&1
taskkill /F /IM git-gui.exe >nul 2>&1
taskkill /F /IM git.exe >nul 2>&1
taskkill /F /IM git-bash.exe >nul 2>&1
taskkill /F /IM gitk.exe >nul 2>&1

echo [Genesis Build] Cloning Necessary Repositories...

REM === Function to check and repair submodule ===
call :CheckAndRepairSubmodule "SDL" "https://github.com/libsdl-org/SDL.git"
call :CheckAndRepairSubmodule "Json" "https://github.com/nlohmann/json.git"
call :CheckAndRepairSubmodule "Glfw" "https://github.com/glfw/glfw.git"
call :CheckAndRepairSubmodule "Glad" "https://github.com/altxxr0/glad.git"

REM Build SDL3 (Static)
echo [Genesis Build] Building SDL3 (static)...
cmake -B External/SDL/build -S External/SDL -DSDL_STATIC=ON -DSDL_SHARED=OFF -DSDL_TEST=OFF
cmake --build External/SDL/build --config Release

REM Ensure main Build directory exists
if not exist Build (
    mkdir Build
)

echo [Genesis Build] Configuring Genesis CMake...
cd Build
cmake .. -DSDL_STATIC=ON -DSDL_SHARED=OFF

if errorlevel 1 (
    echo [Genesis Build] CMake configuration failed.
    exit /b 1
)

echo [Genesis Build] Building Genesis Game...
cmake --build . --config Release

REM Run the built game if successful
if exist bin\Release\GenesisGame.exe (
    echo [Genesis Build] Build complete. Launching game...
    bin\Release\GenesisGame.exe
) else (
    echo [Genesis Build] Build succeeded, but executable not found.
)

cd %CURRENT_DIR%
endlocal
exit /b 0

REM === Subroutine to check and fix submodule ===
:CheckAndRepairSubmodule
set MODULE=%~1
set URL=%~2
set FOLDER=External\%MODULE%
set GITMODULES_PATH=.git\modules\External\%MODULE%

REM Check if folder is missing or empty
if not exist %FOLDER%\ (
    echo [Genesis Build] %MODULE% submodule folder is missing or empty. Repairing...
    git submodule deinit -f %FOLDER%
    rmdir /S /Q %FOLDER% >nul 2>&1
    if exist %GITMODULES_PATH%\ (
        rmdir /S /Q %GITMODULES_PATH% >nul 2>&1
    )
    git submodule add %URL% %FOLDER%
) else (
    echo [Genesis Build] %MODULE% submodule already exists.
)
exit /b
