#include<stdio.h>
#include<conio.h>

main(){
	int a=0, b=0;
		
		printf("EL NUMERO ES MAYOR O MENOR QUE \n");
		printf("Escribe un valor:");
		scanf("%i",&a);
		printf("Escribe un valor:");
		scanf("%i",&b);
		
		printf("\n");
		if(a==b){
			printf("Son iguales:\n %i = %i",a,b);
		}else{
			if(a>b){
				printf("%i es mayor que %i \n %i > %i ",a,b,a,b);
				}else{
				printf("%i es menor que %i \n % i < %i",a,b,a,b);	
			}
		}
}
