#include<stdio.h>
#include<conio.h>

int main(){
	int i=0, variable, space;
	printf("Numero de escalones: ");
	scanf("%i",&variable);
    space=8*variable-5;

	while(i<variable){
		for(int k=0;k<5;k++) printf("*");
		for(int w=0; w<space; w++) printf(" ");
		for(int k=0; k<5; k++) printf("*");	
		printf("\n");
                
		for(int m=0;m<3;m++){
			for(int n=0;n<=i;n++) printf("    ");
			printf("*");
			for(int w=0; w<space; w++) printf(" ");
			printf("*\n");
		}

		for(int j=0; j<=i;j++) printf("    ");
		i++;
		space-=8;
	}	

	for(int k=0;k<5;k++) printf("*");
}
