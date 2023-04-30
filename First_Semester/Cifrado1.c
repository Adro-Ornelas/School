 #include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
	char word[20]="", cifrad[20]="";
	int cifrado;
	
	printf("Escribe una palabra a cifrar: ");
	scanf("%s",&word);
	for(int i=0; i<strlen(word); i++){
		cifrado=word[i] + 1;
		if(cifrado==91) cifrado=65; //Caso Z-A
		if(cifrado==123) cifrado=97; //Caso z-a
		cifrad[i]+=cifrado;
	}
	printf("%s",cifrad);
	for(int i=0; i<20; i++) cifrad[i]=0;
	
	printf("\n\nEscribe una palabra a descifrar: ");
	scanf("%s",&word);
	for(int i=0; i<strlen(word); i++){
		cifrado= word[i] - 1;
		if(cifrado==64) cifrado=90; //Caso A-Z
		if(cifrado==96) cifrado=122; //Caso a-z
		cifrad[i]+=cifrado;
	}
	printf("%s",cifrad);
	
	
}

