@echo off
@echo off
title Bienvenid@ %USERNAME% a @Im_blog menu
color 3
mode con:cols=80 lines=40

:inicio
set var=0
cls
echo ----------------------
echo %DATE% %TIME%
echo ----------------------
echo .

echo 1 Triangulo
echo 2 Cirulo
echo 3 Cuadrado
::echo 4 Opcion 4
::echo 5 Opcion 5
echo 6 Salir 
echo ----------------------
echo .

rem set /p var=^> Seleccione una opcion [1-6]:
set /p var=  Seleccione una opcion [1-6]:

if "%var%"=="0" goto inicio
if "%var%"=="1" goto op1
if "%var%"=="2" goto op2
if "%var%"=="3" goto op3
::if "%var%"=="4" goto op4
::if "%var%"=="5" goto op5
if "%var%"=="6" goto salir

::Mensaje de error, validación cuando se selecciona una opcion fuera de rango
echo . El numero %var% no es una opcion valida
echo .
pause
echo .
goto:inicio

:op1
   ::Triangulo
   color 06
   echo .
   echo . Has elegido la opcion No. 1
   echo . Dibujando Triangulo de color amarillo...
   echo .
   echo .           /\
   echo .          /  \
   echo .         /    \
   echo .        /      \
   echo .       /        \
   echo .      /          \
   echo .     /            \ 
   echo .    /              \
   echo .   /                \
   echo .  /__________________\
   echo .
   pause
   color 03
   goto:inicio

:op2
   ::Circulo
   color 04
   echo .
   echo . Has elegido la opcion No. 2
   echo . Dibujando Circulo de color rojo...
   echo .
   echo .       .adHHHHHHbn.
   echo .      dHHHHHHHHHHHHb
   echo .     dHHHHHHHHHHHHHHb
   echo .    dHHHHHHHHHHHHHHHHb
   echo .    HHHHHHHHHHHHHHHHHH
   echo .    VHHHHHHHHHHHHHHHHP
   echo .     YHHHHUHHHHHHHHHP
   echo .      YHHHHHHHHHHHHP
   echo .       "YUHHHHHHUP" 
   echo .
   echo .
   pause
   color 03
   goto:inicio

:op3
   ::Cuadrado
   color 02
   echo .
   echo . Has elegido la opcion No. 3
   echo . Dibujando Cuadrado de color verde...
   echo .
   echo .  _______________________
   echo .  I                     I
   echo .  I                     I
   echo .  I                     I
   echo .  I                     I
   echo .  I                     I
   echo .  I                     I
   echo .  I                     I
   echo .  I                     I
   echo .  I_____________________I
   echo .  
   pause
   color 03
   goto:inicio

:salir
echo.
echo Saliendo...