#include<stdio.h>
#include<string.h>

int main(){
	int shift, cubo=1;
	char bin[4]="1001", output;

	for(int a=0; a<strlen(bin); a++) cubo*=2;

	for(int i=0; i<cubo; i++){
		output=bin[strlen(bin)-1];
		printf("%s - %c\n", bin, output);
	
		if(bin[3] != bin[2]){
			shift=49;
		}else{
			shift=48;
		}	
		bin[3]=bin[2];
		bin[2]=bin[1];
		bin[1]=bin[0];
		bin[0]=shift;
	}
		
		for(int j=strlen(bin)-1; j>0; j--){
			bin[j]=bin[j-1];
			printf("	%c", bin[j]);
	}




}
