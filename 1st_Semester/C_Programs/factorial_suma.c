#include<stdio.h>
#include<conio.h>

int main(){
	int val=0, suma=0, factorial=1;
	
	printf("SUMA Y FACTORIAL\n");
	printf("Escribe un valor entero:");
	scanf("%i",& val);
	
	printf("*************************************************************\n");
	printf("* CONTADOR  -  SUMA  -  FACTORIAL\n*\n");
	for(int i=1; i<=val;i++){
		suma=suma+i;
		factorial=factorial*i;
		printf("*    %i		%i	  %i \n",i,suma,factorial);
	}
	printf("**************************************************************");
}










