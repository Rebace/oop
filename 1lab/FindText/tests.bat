@echo off

set PROGRAM="%~1"

set OUT="%TEMP%/out.txt"

::�������� ���������� �����������������
%PROGRAM% test.txt word > %OUT%
if ERRORLEVEL 1 goto err
fc out.txt %OUT% || goto err
echo Test 1 passed

::�������� ��������� ������� ���������� ����������
%PROGRAM% word > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 2 passed

::�������� ���������� �����
%PROGRAM% test.txt "" > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 3 passed

echo All tested passed
exit /B 0

:err
echo Program testing failed
exit /B 1 