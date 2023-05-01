#include<stdio.h>
#include<conio.h>
int main(){
	int a=0, b=1, c=0;
	
	while(a<9999){
		printf("%i, ", a);
		c=a+b, a=b, b=c;
	}
}

