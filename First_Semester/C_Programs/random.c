#include<stdio.h>
#include<string.h>

int main(){
	int shift, cubo=1;
	char bin[50]="1000000000000000001", output;

	for(int a=0; a<strlen(bin); a++) cubo*=2;

	printf("%i\n",cubo);

	for(int i=0; i<cubo; i++){
		output=bin[strlen(bin)-1];
		printf("%s - %c\n", bin, output);
	
		if(bin[strlen(bin)-1] != bin[strlen(bin)-2]){
			shift=49; //Si son distintos resulta 1
		}else{
			shift=48; //Si son iguales resulta 0
		}	
	
		for(int j=strlen(bin)-1; j>=1; j--) bin[j]=bin[j-1];
		bin[0]=shift;

	}
}
