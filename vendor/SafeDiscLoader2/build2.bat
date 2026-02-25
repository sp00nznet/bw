@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 > build_log.txt 2>&1
echo vcvarsall result: %ERRORLEVEL% >> build_log.txt
msbuild version-proxy.sln /p:Configuration=Release /p:Platform=x86 /v:normal >> build_log.txt 2>&1
echo msbuild result: %ERRORLEVEL% >> build_log.txt
