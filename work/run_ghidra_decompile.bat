@echo off
REM Black & White headless Ghidra batch decompiler
REM Usage: run_ghidra_decompile.bat [chunk_addresses.txt] [output.txt]
REM
REM First run: imports binary + analyzes + decompiles (slow, ~10-20 min)
REM Subsequent runs with -process: reuses existing project (fast, ~1-2 min)

set GHIDRA_HOME=C:\tools\ghidra\ghidra_12.0.3_PUBLIC
set PROJECT_DIR=D:\recomp\pc\bw\work\ghidra_project
set PROJECT_NAME=BW_v100
set BINARY=D:\recomp\pc\bw\game_data\runblack_decrypted.exe
set SCRIPT_DIR=D:\recomp\pc\bw\work
set ADDRESSES=%~1
set OUTPUT=%~2

if "%ADDRESSES%"=="" set ADDRESSES=D:\recomp\pc\bw\work\chunk1_addresses.txt
if "%OUTPUT%"=="" set OUTPUT=D:\recomp\pc\bw\work\decompiled_chunk1.txt

echo ============================================================
echo  Black and White Headless Ghidra Batch Decompiler
echo ============================================================
echo  Ghidra:     %GHIDRA_HOME%
echo  Project:    %PROJECT_DIR%\%PROJECT_NAME%
echo  Binary:     %BINARY%
echo  Addresses:  %ADDRESSES%
echo  Output:     %OUTPUT%
echo ============================================================

REM Check if project already exists
if exist "%PROJECT_DIR%\%PROJECT_NAME%.rep" (
    echo Project already exists — reusing (no re-analysis)
    echo Running decompiler script...
    "%GHIDRA_HOME%\support\analyzeHeadless.bat" ^
        "%PROJECT_DIR%" "%PROJECT_NAME%" ^
        -process "%PROJECT_NAME%" ^
        -noanalysis ^
        -scriptPath "%SCRIPT_DIR%" ^
        -postScript ghidra_batch_decompile.py "%ADDRESSES%" "%OUTPUT%"
) else (
    echo First run — importing binary and analyzing (this takes 10-20 minutes)...
    "%GHIDRA_HOME%\support\analyzeHeadless.bat" ^
        "%PROJECT_DIR%" "%PROJECT_NAME%" ^
        -import "%BINARY%" ^
        -processor "x86:LE:32:default" ^
        -cspec "windows" ^
        -scriptPath "%SCRIPT_DIR%" ^
        -postScript ghidra_batch_decompile.py "%ADDRESSES%" "%OUTPUT%" ^
        -max-cpu 4
)

echo.
echo ============================================================
echo  Done! Output written to: %OUTPUT%
echo ============================================================
echo.
echo Next step: paste the output into Claude with:
echo   "Translate this Ghidra output for [MethodName]"
echo.
pause
