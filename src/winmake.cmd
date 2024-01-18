@setlocal enableextensions
@cd /d "%~dp0"
mingw32-make clean arch=x86
mingw32-make run arch=x86
pause