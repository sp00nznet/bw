@echo off
rem Run every test_*.exe next to the given exe (or in the given folder) and
rem fail if any fails. netlab's QA calls this with the path of one of them;
rem by hand: tools\run_tests.cmd src\build\Release
rem Tests that need game data print "note: ... skipped" and still exit 0.
setlocal enabledelayedexpansion
set "DIR=%~1"
if not exist "%DIR%\" set "DIR=%~dp1"
if "%DIR%"=="" set "DIR=."
set /a PASS=0, FAIL=0
rem test_loader / test_mp2 / test_g3d are inspection tools that take a file, not tests.
for %%t in ("%DIR%\test_*.exe") do if /i not "%%~nt"=="test_loader" if /i not "%%~nt"=="test_mp2" if /i not "%%~nt"=="test_g3d" (
  "%%t" > "%TEMP%\bw_test.log" 2>&1
  rem Not "if errorlevel 1": a crash or a missing DLL exits negative (0xC0000135).
  if !errorlevel! neq 0 (
    set /a FAIL+=1
    echo FAIL %%~nt
    type "%TEMP%\bw_test.log"
  ) else (
    set /a PASS+=1
    echo ok   %%~nt
    findstr /b /c:"note:" "%TEMP%\bw_test.log"
  )
)
echo %PASS% passed, %FAIL% failed
if %FAIL% gtr 0 exit /b 1
if %PASS%==0 (echo no test_*.exe in "%DIR%" & exit /b 1)
exit /b 0
