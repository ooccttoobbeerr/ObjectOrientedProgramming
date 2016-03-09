@echo off
SET program="%1"
if %program% == "" goto err

echo Test1 > out.txt
%program% input.txt output.txt >> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt out1.txt
if ERRORLEVEL 1 goto testFailed

echo Test2 > out.txt
%program% input2.txt >> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt out2.txt
if ERRORLEVEL 1 goto testFailed

echo Test3 > out.txt
%program% "cat.txt" "output.txt" >> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt out3.txt
if ERRORLEVEL 1 goto testFailed

echo Test4 > out.txt
%program% "input2.txt" "ouput.txt" >> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt out4.txt
if ERRORLEVEL 1 goto testFailed

echo OK
pause
exit /B

:testFailed
echo Testing failed
pause
exit /B

:err
echo Usage: test.bat <Path to program>