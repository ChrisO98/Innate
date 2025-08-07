@echo off
setlocal

REM Choose the preset
REM set PRESET=vs2022-debug
set PRESET=debug
set CONFIG=Debug

REM Get build directory path (must match what's in CMakePresets.json)
set BUILD_DIR=build\%PRESET%

REM Check if configuration is needed
if not exist "%BUILD_DIR%\CMakeCache.txt" (
    echo [CMake] Configuring project with preset %PRESET%...
    cmake --preset %PRESET%
    IF %ERRORLEVEL% NEQ 0 (
        echo [Error] CMake configure failed.
        exit /b %ERRORLEVEL%
    )
) else (
    echo [CMake] Already configured. Skipping configure step.
)

REM Build project (like bin-int)
echo [CMake] Building project...
cmake --build --preset build-%PRESET%
IF %ERRORLEVEL% NEQ 0 (
    echo [Error] Build failed.
    exit /b %ERRORLEVEL%
)

REM Run the application
echo [Run] Launching Sandbox.exe...
call bin\%CONFIG%\Sandbox\Sandbox.exe

endlocal
pause
