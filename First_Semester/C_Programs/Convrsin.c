//Programa que realiza conversiones
#include<stdio.h>
#include<conio.h>

int main(){
        int val=0;
        float convers=0;
        printf("Escribe un valor: ");
        scanf("%i",&val);

        printf("---------------------------------------------------------\n");
        printf("*                     TEMPERATURE                       *\n");
        printf("* Celcius to Farenheit          Farenheit to Celcius    *\n");
        convers=val*1.8+32;
        printf("* %i C = %f F		",val,convers);
        convers=(val-32)/1.8;
        printf("%i F = %f C	*\n",val,convers);
	printf("---------------------------------------------------------\n");


        printf("---------------------------------------------------------\n");
        printf("*                        LENGTH                         *\n");
        printf("* Centimeters to inches         Iches to centimeters    *\n");
        convers=val*0.3937;
        printf("* %icm = %fin		",val,convers);
        convers=val/0.3937;
        printf("%icm = %fin	*\n",val,convers);
        printf("*                                                       *\n");
        printf("* Meters to feets               Feets to Meters         *\n");
        convers=val*3.281;
        printf("* %i m = %fft		",val,convers);
        convers=val/3.281;
        printf("%i m = %f ft	*\n",val,convers);
	printf("---------------------------------------------------------\n");

        printf("---------------------------------------------------------\n");
        printf("*                         SPEED                         *\n");
        printf("* mi/h to km/h                  km/h to mi/h            *\n");
        convers=val*1.609;
        printf("* %imi/h = %fkm/h	",val,convers);
        convers=val/1.609;
        printf("%imi/h = %fkm/h	*\n",val,convers);
	printf("---------------------------------------------------------\n");


}
