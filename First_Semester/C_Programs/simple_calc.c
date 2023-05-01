#include<stdio.h>
#include<conio.h>
#include<windows.h>

int main(){
	char opt;
	int val1, val2;
		
	while(true){
	printf("	1. SUMA\n");
	printf("	2. RESTA\n");
	printf("	3. MULTIPLIACI%cN\n",-32);
	printf("	4. DIVISI%cN\n",-32);
	printf("	<<Esc=Salir>>\n\n");
	printf("	-Elige una opci%cn: ",162);
	opt=getch();
	
	printf("\n\n");
	
	if(opt=='1') printf("		SUMA\n");
	if(opt=='2') printf("		RESTA\n");
	if(opt=='3') printf("		MULTIPLICACI%cN\n",-32);
	if(opt=='4') printf("		DIVISI%cN\n",-32);
	if(opt==27) break;
	
	printf("	Escribe un valor: ");
	scanf("%i",&val1);
	printf("	Escribe otro valor: ");
	scanf("%i",&val2);
	
	switch(opt){
		
		case '1':
			printf("	%i + %i = %i\n",val1,val2,val1+val2);
			getch();
			system("cls");
			break;
			
			case '2':
			printf("	%i - %i = %i\n",val1,val2,val1-val2);
			getch();
			system("cls");
			break;
			
			case '3':
			printf("	%i * %i = %i\n",val1,val2,val1*val2);
			getch();
			system("cls");
			break;
		
			case '4':
			printf("	%i / %i = %i\n",val1,val2,val1/val2);
			getch();
			system("cls");
			break;
		}
	}
	
}
