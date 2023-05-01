#include<stdio.h>
#include<windows.h>
#include<conio.h>

int main(){
	char opt;
	int num=1;
	while(opt != 13){	
	system("cls");

	printf("1. OPCION");
	if(num==1) printf("	*"); 	
	printf("\n2. OPCION");
	if(num==2) printf("	*");
	printf("\n3. OPCION");
	if(num==3) printf("	*");
	printf("\n4. OPCION");
	if(num==4) printf("	*");
	printf("\n");
	opt=getch();
	
	if(opt==72){
		num--;	
	}else if(opt==80){
		num++;
	}
	
	if(num>4) num=1;
	if(num<1) num=4;
	}
	
	switch(num){
		case 1:
			printf("Has elgido la opcion 1\n");
			system("pause");
			break;
		case 2:
			printf("Has elgido la opcion 2\n");
			system("pause");
			break;
			
		case 3:
			printf("Has elgido la opcion 3\n");
			system("pause");
			break;
			
		case 4:
			printf("Has elgido la opcion 4\n");
			system("pause");
			break;
			
	}
}


//up 72
//down 80
//left 75
//right 77
//INtro 13
