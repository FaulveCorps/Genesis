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

cd Build

REM Run cmake configure with live output + log file
powershell -Command "cmake .. | Tee-Object -FilePath ..\build_output.txt"

REM Run cmake build with live output + append to log file
powershell -Command "cmake --build . --config Debug | Tee-Object -FilePath ..\build_output.txt -Append"

echo:

REM Check if Debug folder exists
if exist "%cd%\Debug" (
    echo   Build Successful . . .
) else (
    echo   Build Failed <!> . . .
    echo:
    echo   Relevant Error Lines:
    echo   ----------------------

    findstr /i "error" ..\build_output.txt

    echo   ----------------------
)

:loop
goto loop
