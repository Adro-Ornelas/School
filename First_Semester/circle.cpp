#include<stdio.h>
#include<conio.h>

int main(){
	
	for(int i=1;i<=20;i++){
		for(int j=20;j>=i;j--){
			printf("  ");
		}
		for(int a=1;a<=i;a++){
			printf("# ");
		}
		for(int b=1;b<=i;b++){
		printf("* ");
				
		}
		printf("\n");
	}
	
	for(int i=1;i<=20;i++){
		for(int j=1;j<=i;j++){
			printf("  ");
		}
		for(int a=20;a>=i;a--){
			printf("* ");
		}
		for(int b=20;b>=i;b--){
			printf("# ");
			
		}
		printf("\n");
	}
}

