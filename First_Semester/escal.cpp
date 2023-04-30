#include<stdio.h>
#include<conio.h>

int main(){
	int i=0, espacio=59;
	while(i<8){	
		for (int a=0;a<5;a++) printf("*");
		
		for (int z=0;z<espacio;z++) printf(" ");
		espacio-=8;
		
		for (int a=0;a<5;a++) printf("*");
		
		printf("\n");
		
		for(int b=0;b<3;b++){
			for(int c=0;c<=i;c++) printf("    ");	
		    printf("*");
		    
		espacio+=8;    
		for (int w=0;w<espacio;w++) printf(" ");
		espacio-=8;
		
		printf("*\n");
		    
		}
		for(int c=0;c<=i;c++) printf("    ");
		i++;
	}
	for (int a=0;a<5;a++) printf("*");
}
