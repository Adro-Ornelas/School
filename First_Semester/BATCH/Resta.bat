@echo off
mode con:cols=80 lines=40
echo %time%
timeout /t 8 > null
echo %time%
echo  -------------
echo     "RESTA"
echo  -------------
set /p val1=Digite el primer valor:
set /p val2=Digite el segundo valor:
set /a result=val1-val2
echo ----------------------------------------
echo    %val1% - %val2% = %result%
echo ----------------------------------------