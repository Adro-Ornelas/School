#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int main(){
	int j=0, numAscii, charAscii, charAsciianter, charlength=0;
	char palabra[20], password[20]="", cadenaletra[20], letra;
	
	//Semilla de números aleatorios
	srand(time(0));
	printf("Palabra a convertir: ");
	scanf("%s",palabra);
	
	printf("%s \n\n",palabra);
	charlength=strlen(palabra);
	
	printf("Largo de cadena: %i \n\n", charlength);
	
	/*printf("Generando n%cmeros aleatorios...\n\n",163);
	for(int i=0; i<100; i++){
		numAscii= 32 + (rand()%223);
		printf("%i-",numAscii);
	}*/
	printf("\n\n");
	
	for(int j=0; j<charlength; j++){
		numAscii= 64 + (rand()%61); 
		
		for(int i=0; i<10; i++){
			charAscii= 64 + (rand()%61);
			Sleep(10);
			printf("%c\b",charAscii);
			
		}
		printf("%c", numAscii);
	}
	printf("\n\n\n");

	while(j<charlength){
		for(int i=0;i<10;i++){
			charAscii= 1 + (rand()%255);
			if(charAscii>32){
				Sleep(50);
				printf("%c\b",charAscii);
			}
		}
		printf("%c", charAscii);
		j++;
	}
	
}
