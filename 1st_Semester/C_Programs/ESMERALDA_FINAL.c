#include<stdio.h>
#ifdef _WIN32
 #include<conio.h>
 #include<windows.h>
#else
 #include<stdlib.h>
#endif

int main(){
	int i=0, s=0, variable, space, space1=3;
	printf("Numero de escalones: ");
	scanf("%i",&variable);
    space=8*variable-5;
	s=variable;

	//TODA LA PARTE SUPERIOR DE LA FIGURA
	for(int j=0; j<s; j++) printf("    ");
	for(int k=0; k<5; k++) printf("*");
	printf("\n");
	while(s>0){
		for(int m=0; m<3; m++){
			for (int j=0; j<s; j++) printf("    ");
			printf("*");
			for (int w=0; w<space1; w++) printf(" ");
			printf("*\n");
		}
		s--;
		for (int j=0; j<s; j++) printf("    ");
		for (int k=0; k<5; k++) printf("*");
		for (int w=0; w<space1; w++) printf(" ");
		for (int k=0; k<5; k++) printf("*");
		printf("\n");
		space1+=8;
	}
	
	//TRES ASTERISCOS DE LA PARTE MEDIA
	space1-=1;
	for(int m=0; m<3; m++){
		printf("*");
		for(int w=0; w<=space1; w++) printf(" ");
		printf("*\n");
	}

	//TODA LA PARTE INFERIOR
	while(i<variable){
		for(int k=0; k<5;k++) printf("*");
		for(int w=0; w<space; w++) printf(" ");
		for(int k=0; k<5; k++) printf("*");	
		printf("\n");
                
		for(int m=0; m<3; m++){
			for(int n=0; n<=i; n++) printf("    ");
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
