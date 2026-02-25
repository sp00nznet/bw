@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
if errorlevel 1 (
    echo ERROR: vcvarsall failed > D:\recomp\pc\bw\vendor\SafeDiscLoader2\build_result.txt
    exit /b 1
)
echo vcvarsall OK > D:\recomp\pc\bw\vendor\SafeDiscLoader2\build_result.txt
msbuild D:\recomp\pc\bw\vendor\SafeDiscLoader2\version-proxy.vcxproj /p:Configuration=Release /p:Platform=Win32 /v:normal >> D:\recomp\pc\bw\vendor\SafeDiscLoader2\build_result.txt 2>&1
echo MSBUILD_EXIT=%ERRORLEVEL% >> D:\recomp\pc\bw\vendor\SafeDiscLoader2\build_result.txt
exit /b %ERRORLEVEL%
