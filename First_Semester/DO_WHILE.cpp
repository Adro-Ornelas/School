#include<stdio.h>
#include<conio.h>

int main(){
	int val,suma,fact=1;
	
	printf("\t	*************************\n");
	printf("\t	*   FACTORIAL Y SUMA    *\n");
	printf("\t	*************************\n");
	
	printf("Escribe un valor: ");
	scanf("%i",&val);
	
	printf("******************************************************************\n");
	printf("*		SUMA    		FACTORIAL		 *\n");
	printf("*                                                                *\n");
	do{
		if(val!=0)fact=fact*val; 
		suma=suma+val;
		printf("*		%i                      %i			 *\n",suma,fact);
		val--;
		
	}while(val>=1);
	
	printf("******************************************************************\n");
	printf("*                         RESULTADO                              *\n");
	printf("* \t SUMA: %i \t\t\t FACTORIAL: %i \t *\n",suma,fact);
	printf("******************************************************************\n");
}

