@echo off

call "setup_mingw.bat"

cd .

if "%1"=="" ("%MINGW_ROOT%\mingw32-make.exe"  -j 12 -l 12 -Oline -f RollAxisAutopilot.mk all) else ("%MINGW_ROOT%\mingw32-make.exe"  -j 12 -l 12 -Oline -f RollAxisAutopilot.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1