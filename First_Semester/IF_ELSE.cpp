#include<stdio.h>
#include<conio.h>
int main(){
	int val=0;
	printf("IDENTIFICADOR DE NUM \n");
	printf("Escribe un valor: ");
	scanf("%i", &val);
	
	printf("\n");
	if(val==0) {
	   printf("El valor %i es neutral",val);
	} else {
		if(val>0){
	    printf("El valor %i es positivo",val);
	   } else {
	   	printf("El valor %i es negativo",val);
	   }
		
		
	}
}
