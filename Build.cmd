@echo off
echo:
echo   Build Starting . . . 
echo:
REM Delete existing Build folder
if exist Build (
    rmdir /s /q Build
)

REM Create new Build folder
mkdir Build

REM Run CMake to configure the project
cd Build
cmake ..

cmake --build . --config Debug
echo:
echo   Build Done (You can exit this now) . . .
:loop
goto loop