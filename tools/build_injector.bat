@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
cl.exe /nologo /O2 /Fe:D:\recomp\pc\bw\tools\inject_and_run.exe D:\recomp\pc\bw\tools\inject_and_run.c /link /SUBSYSTEM:CONSOLE
echo BUILD_EXIT=%ERRORLEVEL%
