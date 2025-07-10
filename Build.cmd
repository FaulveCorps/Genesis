@echo off
@title Altxxr0 / Compiler Build Script
@chcp 65001 >nul
cls
echo: ░██████╗░███████╗███╗░░██╗███████╗░██████╗██╗░██████╗
echo: ██╔════╝░██╔════╝████╗░██║██╔════╝██╔════╝██║██╔════╝
echo: ██║░░██╗░█████╗░░██╔██╗██║█████╗░░╚█████╗░██║╚█████╗░
echo: ██║░░╚██╗██╔══╝░░██║╚████║██╔══╝░░░╚═══██╗██║░╚═══██╗
echo: ╚██████╔╝███████╗██║░╚███║███████╗██████╔╝██║██████╔╝
echo: ░╚═════╝░╚══════╝╚═╝░░╚══╝╚══════╝╚═════╝░╚═╝╚═════╝░
echo:      █▀▀ ▄▀█ █▀▄▀█ █▀▀   █▀▀ █▄░█ █▀▀ █ █▄░█ █▀▀
echo:      █▄█ █▀█ █░▀░█ ██▄   ██▄ █░▀█ █▄█ █ █░▀█ ██▄
echo:
echo                   Altxxr0 / CBS
echo:
echo   Build Starting . . .
echo:

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
