#include<stdio.h>
#include<conio.h>
#include<windows.h>

int main(){
	char name[20];
	printf("Escribe tu nombre: \n");
	scanf("%s",&name);
	system("cls");
	
	for(int i=1; i<=50; i++){
		printf("%s; %i \n",name,i);
	}
}
