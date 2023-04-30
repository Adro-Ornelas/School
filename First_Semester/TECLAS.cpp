#include<stdio.h>
#include<conio.h>

int main(){
	char caracter;
	while(true){
		caracter=getch();
		printf("Tecla: %i \n",caracter);
		if(caracter==27) break;		
	}
}

