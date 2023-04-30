#include<stdio.h>
#include<conio.h>

int main(){
	int i=0, val;
	double promedio, suma;
	
	while(i<10){
		printf("Escribe un valor: ");
		scanf("%i",&val);
		suma+=val;
		i++;
	}
	printf("\nLa suma es %f\n",suma);
	promedio=suma/10;
	printf("El promedio es %f",promedio);
}
