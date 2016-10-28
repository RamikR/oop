set PROGRAM="%~1"

rem invalid arguments
%PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt correctAnswers\rightOutput1.txt
if ERRORLEVEL 1 goto err
echo Test for invalid arguments succeeded!

rem dec2bin 10 
%PROGRAM% "10" > "%TEMP%\output.txt""
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" correctAnswers\rightOutput2.txt
if ERRORLEVEL 1 goto err
echo Test for dec2bin 10 succeeded!

rem dec2bin abc
%PROGRAM% "abc" > "%TEMP%\output.txt""
if NOT ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" correctAnswers\rightOutput3.txt
if ERRORLEVEL 1 goto err
echo Test for dec2bin abc succeeded!

rem dec2bin 13a45b6c
%PROGRAM% "13a45b6c" > "%TEMP%\output.txt""
if NOT ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" correctAnswers\rightOutput4.txt
if ERRORLEVEL 1 goto err
echo Test for dec2bin 13a45b6c succeeded!

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1