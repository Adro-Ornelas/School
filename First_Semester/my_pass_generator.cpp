#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int main(){
	int numAscii, charAscii, charlength=0;
	char palabra[20];
	
	//Semilla de números aleatorios
	srand(time(0));
	printf("Palabra a convertir: ");
	scanf("%s",&palabra);
	
	printf("\n");
	charlength=strlen(palabra);
	printf("Largo de cadena: %i \n\n", charlength);
	
	for(int i=0; i<charlength; i++){
		for(int j=0; j<10; j++){
		    charAscii=1+(rand()%255);
		    while(true){
				charAscii=1 +(rand()%255);
				if(charAscii>64 && charAscii<125) break;
			}
		printf("%c\b",charAscii);
		Sleep(20);
		}
		numAscii=1 +(rand()%255);
		while(true){
			numAscii=1 +(rand()%255);
			if(numAscii>64 && numAscii<125) break;
		}
		printf("%c",numAscii);
	}
}
