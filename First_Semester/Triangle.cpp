#include<stdio.h>
#include<conio.h>
main (){
	for(int i=1;i<=20;i++){
		for(int j=1;j<=i;j++){
			printf(" *");
		}
		for(int k=19;k>=i;k--){
		printf(" #");	
		}	
		printf("\n");
	}
}
