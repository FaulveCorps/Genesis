@echo off
@title Altxxr0 / Compiler Build Script
@chcp 65001 >nul
cls
echo:    ░██████╗░███████╗███╗░░██╗███████╗░██████╗██╗░██████╗
echo:    ██╔════╝░██╔════╝████╗░██║██╔════╝██╔════╝██║██╔════╝
echo:    ██║░░██╗░█████╗░░██╔██╗██║█████╗░░╚█████╗░██║╚█████╗░
echo:    ██║░░╚██╗██╔══╝░░██║╚████║██╔══╝░░░╚═══██╗██║░╚═══██╗
echo:    ╚██████╔╝███████╗██║░╚███║███████╗██████╔╝██║██████╔╝
echo:    ░╚═════╝░╚══════╝╚═╝░░╚══╝╚══════╝╚═════╝░╚═╝╚═════╝░
echo:         █▀▀ ▄▀█ █▀▄▀█ █▀▀   █▀▀ █▄░█ █▀▀ █ █▄░█ █▀▀
echo:         █▄█ █▀█ █░▀░█ ██▄   ██▄ █░▀█ █▄█ █ █░▀█ ██▄
echo:
echo                      Altxxr0 / CBS
echo:   
echo   Build Starting . . .
echo:

REM === Prompt User for Action ===
echo   [1]   :   Build Only
echo   [2]   :   Download External Dependencies Only
echo   [3]   :   Download Dependencies + Build
set /p userChoice=   Choose an option (1/2/3): 

REM === Dependency Download Section ===
if "%userChoice%"=="2" goto :GetDependencies
if "%userChoice%"=="3" goto :GetDependenciesAndBuild
if "%userChoice%"=="1" goto :BuildOnly

:GetDependencies
echo.
echo   Downloading External Dependencies . . .
echo.

REM --- Clean External Folder ---
if exist External (
    echo   Cleaning existing External folder . . .
    rmdir /s /q External
    echo.
)
mkdir External
cd External

REM --- Capitalized External Folders & Repos ---
echo   Cloning dependencies . . .
echo.
git clone --recursive https://github.com/bkaradzic/bgfx.git Bgfx
echo.
git clone --recursive https://github.com/bkaradzic/bimg.git Bimg
echo.
git clone --recursive https://github.com/bkaradzic/bx.git Bx
echo.
git clone --recursive https://github.com/bulletphysics/bullet3.git Bullet
echo.
git clone --recursive https://github.com/libsdl-org/SDL.git SDL

echo   Dependencies Downloaded Successfully.
goto :EOF

:GetDependenciesAndBuild
call :GetDependencies
cd ..
goto :BuildOnly

:BuildOnly
if "%1"=="clean" (
    echo Cleaning Build directory . . .
    if exist Build (
        rmdir /s /q Build
    )
)

if not exist Build (
    mkdir Build
)

cd Build

if not exist CMakeCache.txt (
    powershell -Command "cmake .. | Tee-Object -FilePath ..\build_output.txt"
)

powershell -Command "cmake --build . --config Debug -- /m:4 | Tee-Object -FilePath ..\build_output.txt -Append"

echo:

if exist "%cd%\Debug" (
    dir /b "%cd%\Debug" | findstr . >nul
    if errorlevel 1 (
        echo   Build Failed <!> - Debug folder is empty.
        echo:
        echo   Relevant Error Lines:
        echo   ----------------------
        findstr /i "error" ..\build_output.txt
        echo   ----------------------
        exit /b 1
    ) else (
        echo   Build Successful . . .
    )
) else (
    echo   Build Failed <!> - Debug folder does not exist.
    echo:
    echo   Relevant Error Lines:
    echo   ----------------------
    findstr /i "error" ..\build_output.txt
    echo   ----------------------
    exit /b 1
)

goto :EOF
