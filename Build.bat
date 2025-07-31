@echo off
setlocal
set BUILD_DIR=build
set EXECUTABLE=Genesis.exe
set EXECUTABLE_PATH=%BUILD_DIR%\Executable\Debug\%EXECUTABLE%
set GENIE_PATH=External\bx\tools\bin\windows\genie.exe
set BGFX_DIR=External\bgfx
set BGFX_BUILD_DIR=%BGFX_DIR%\.build
set BGFX_SLN=%BGFX_BUILD_DIR%\bgfx.sln
set SHADERC_PROJECT=shaderc

:: Kill Git/VS Code instances (optional)
taskkill /F /IM Code.exe >nul 2>&1
taskkill /F /IM git-gui.exe >nul 2>&1
taskkill /F /IM git.exe >nul 2>&1
taskkill /F /IM git-bash.exe >nul 2>&1
taskkill /F /IM gitk.exe >nul 2>&1

echo [Genesis Build] Initializing Git Submodules...
git submodule update --init --recursive
if %ERRORLEVEL% neq 0 (
    echo [Error] Failed to initialize submodules.
    exit /b 1
)

:: Download Genie if not present
if not exist Tools\genie (
    echo [Genesis Build] Downloading Genie...
    git clone https://github.com/bkaradzic/genie Tools\genie
    if %ERRORLEVEL% neq 0 (
        echo [Error] Failed to clone Genie.
        exit /b 1
    )
)

:: Generate project files for bgfx using Genie
echo [Genesis Build] Generating bgfx project with Genie...
pushd %BGFX_DIR%
..\bx\tools\bin\windows\genie.exe vs2022
if %ERRORLEVEL% neq 0 (
    echo [Error] Failed to run Genie.
    popd
    exit /b 1
)
popd

:: Build shaderc tool via MSBuild (Visual Studio)
echo [Genesis Build] Building shaderc tool via Visual Studio...
msbuild External\bgfx\.build\projects\vs2022\shaderc.vcxproj /p:Configuration=Debug /p:Platform=x64

:: Optional: Verify shaderc built successfully
if exist "%BGFX_BUILD_DIR%\win64_vs2022\bin\shadercDebug.exe" (
    echo [Genesis Build] shaderc built successfully.
) else (
    echo [Error] shaderc binary not found after build.
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
