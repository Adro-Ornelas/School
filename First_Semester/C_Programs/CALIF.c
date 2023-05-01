#include<stdio.h>
#include<conio.h>

int main(){
	int i;
	
	printf("Escribe tu califiacion [0-100]: ");
	scanf("%i",&i);
	printf("\n");

	printf("*************************\n");
	if(i<0 || i>100)  printf("*Calificacion invalida	*\n");
	if(i>=0 && i<60)  printf("*	No aprobado	*\n");
	if(i>=60 && i<70) printf("*	Aprobado	*\n");
	if(i>=70 && i<80) printf("*	Regular		*\n");
	if(i>=80 && i<90) printf("*	Bien		*\n");
	if(i>=90 && i<100)printf("*	Muy bien!	*\n");
	if(i==100)		  printf("*	INSANO		*\n");	
	printf("*************************\n");
}


