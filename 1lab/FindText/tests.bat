@echo off

set PROGRAM="%~1"

set OUT="%TEMP%/out.txt"

::ѕроверка нормальной работоспособности
%PROGRAM% test.txt word > %OUT%
if ERRORLEVEL 1 goto err
fc out.txt %OUT% || goto err
echo Test 1 passed

::ѕроверка отсутсви€ нужного количества аргументов
%PROGRAM% word > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 2 passed

::ѕроверка отсутстви€ слова
%PROGRAM% test.txt "" > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 3 passed

echo All tested passed
exit /B 0

:err
echo Program testing failed
exit /B 1 