@echo off

set PROGRAM="%~1"

set OUT="%TEMP%/out.txt"

::�������� �� ������ �������
%PROGRAM% 0 > %OUT%
if ERRORLEVEL 1 goto err
fc out1.txt %OUT% || goto err
echo Test 1 passed

::�������� �� ����� �������
%PROGRAM% 255 > %OUT%
if ERRORLEVEL 1 goto err
fc out2.txt %OUT% || goto err
echo Test 2 passed

::�������� �� ���������� �����������������
%PROGRAM% 117 > %OUT%
if ERRORLEVEL 1 goto err
fc out3.txt %OUT% || goto err
echo Test 3 passed

::�������� �� ����������� ����� �����
%PROGRAM% 1 > %OUT%
if ERRORLEVEL 1 goto err
fc out4.txt %OUT% || goto err
echo Test 4 passed

::�������� �� ��������� ���������
%PROGRAM%  > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 5 passed

::�������� �� ����� �� ������� �����
%PROGRAM% -1 > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 6 passed

::�������� �� ����� �� ������� �����
%PROGRAM% 256 > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 7 passed

::�������� �� �� �������� ����
%PROGRAM% 15.5 > %OUT%
if NOT ERRORLEVEL 1 goto err
echo Test 8 passed

echo All tested passed
exit /B 0

:err
echo Program testing failed
exit /B 1 