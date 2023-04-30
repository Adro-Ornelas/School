// IMPORTAR LIBRERIAS SOLO EN WINDOWS O LINUX

#include<stdio.h>
#ifdef _WIN32
 #include<conio.h>
 #include<windows.h>
#else
 #include<stdlib.h>
#endif

// METODO PARA LIMPIAR PANTALLA

void clear_scr(){

	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif

}

