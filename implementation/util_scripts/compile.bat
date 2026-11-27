REM Utility script to compile the bitonic_sort.cpp file using g++ with C++20 standard and address sanitizer enabled.

REM echo off to suppress command output
@echo off
REM setlocal to ensure that environment changes are local to this script
setlocal

REM Check if g++ is available in the PATH
where g++ >nul 2>nul
if errorlevel 1 (
    echo Error: g++ was not found in PATH.
    exit /b 1
)

REM Obtain the g++ version
for /f "tokens=1 delims=." %%V in ('g++ -dumpfullversion -dumpversion 2^>nul') do set "GCC_MAJOR=%%V"
if not defined GCC_MAJOR (
    echo Error: Could not determine the g++ version.
    exit /b 1
)
REM Check if the GCC version is at least 12 and if not, print an error message and exit with a non-zero status code
if %GCC_MAJOR% LSS 12 (
    echo Error: GCC 12 or newer is required. Found GCC %GCC_MAJOR%.
    exit /b 1
)

REM Compile the bitonic_sort.cpp file with the specified flags, if any error occurs during compilation, exit with a non-zero status code
g++ -std=c++20 -O2 -Wall -Wextra -Werror -fsanitize=address "%~dp0..\bitonic_sort.cpp" -o "%~dp0..\bitonic_sort.exe"
if errorlevel 1 exit /b 1

REM Print a success message indicating the location of the compiled executable and exit with a zero status code
echo Build successful: "%~dp0..\bitonic_sort.exe"
exit /b 0
