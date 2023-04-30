#include<stdio.h>
#include<conio.h>

int main(){
	int i=1, div=1, impr=0, lines=0;
	printf("*******************************************************************************************\n");
	printf("***************************************************************************************** *\n");
	while(true){
		for(div=1; div<=i; div++){
			if(i%div==0) impr++;
		}
		if(impr==2){
			printf("%i,\t", i);
			lines++;
			if(lines%10==0){
				printf("\t* *");
				printf("\n");
			}
		}
		if(lines==100) break;
		i++;
		impr=0;
	}
}

