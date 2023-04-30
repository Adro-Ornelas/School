#include<stdio.h>
#include<conio.h>

int main(){
	int val1=0,val2,suma=0,resta=0,multi=0,divis=0;
	printf("Suma-Resta-Division-Multiplicaion \n");
	printf("Escribe un valor: ");
	scanf("%i", &val1);
	printf("Escribe otro valor: ");
	scanf("%i", &val2);
	printf("\n");
	
	suma=val1+val2;
	resta=val1-val2;
	multi=val1/val2;
	divis=val1*val2;
	
	printf("          Suma: %i + %i = %i \n",val1,val2,suma);
	printf("         Resta: %i - %i = %i \n",val1,val2,resta);
	printf("Multiplicacion: %i / %i = %i \n",val1,val2,multi);
	printf("      Division: %i * %i = %i \n",val1,val2,divis);	
}
