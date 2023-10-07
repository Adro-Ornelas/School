@echo off
mode con:cols=100 lines=40
echo  ------------------
echo     "SUMA DESIGN"
echo  ------------------
set /p val1=Digite el primer valor:
set /p val2=Digite el segundo valor:
set /a result=val1+val2
echo -------------------------------------------
echo   [ %val1% ] + [ %val2% ] = [ %result% ]
echo -------------------------------------------