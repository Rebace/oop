@echo off

set PROGRAM="%~1"

set OUT="%TEMP%/out.txt"

::Проверка на начало границы
%PROGRAM% 0 > %OUT%
if ERRORLEVEL 1 goto err
fc out1.txt %OUT% || goto err
echo Test 1 passed

::Проверка на конец границы
%PROGRAM% 255 > %OUT%
if ERRORLEVEL 1 goto err
fc out2.txt %OUT% || goto err
echo Test 2 passed

::Проверка на нормальную работоспособность
%PROGRAM% 117 > %OUT%
if ERRORLEVEL 1 goto err
fc out3.txt %OUT% || goto err
echo Test 3 passed

::Проверка на нормальноую длину байта
%PROGRAM% 1 > %OUT%
if ERRORLEVEL 1 goto err
fc out4.txt %OUT% || goto err
echo Test 4 passed

::Проверка на отсутсвие аргумента
%PROGRAM%  > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 5 passed

::Проверка на выход за границы байта
%PROGRAM% -1 > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 6 passed

::Проверка на выход за границы байта
%PROGRAM% 256 > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 7 passed

::Проверка на не цифровой ввод
%PROGRAM% 15.5 > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 8 passed

echo All tested passed
exit /B 0

:err
echo Program testing failed
exit /B 1 