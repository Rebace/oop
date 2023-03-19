@echo off

set PROGRAM="%~1"

set OUT="%TEMP%/out.txt"

::Проверка неверного количества символов в матрице
%PROGRAM% test1.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 1 passed

::Проверка нормальной работоспособности
%PROGRAM% test2.txt > %OUT%
if ERRORLEVEL 1 goto err
fc out2.txt %OUT% || goto err
echo Test 2 passed

::Проверка нулевого определителя
%PROGRAM% test3.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 3 passed

::Проверка на отсутствие аргумента
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 4 passed

echo All tested passed
exit /B 0

:err
echo Program testing failed
exit /B 1 