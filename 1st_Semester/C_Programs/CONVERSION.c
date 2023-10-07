#include<stdio.h> 
//#include<conio.h>

int main(){
	int val=0;
	float convers=0;
	printf("\t\tCt°-F°, CM-INCHES M-Ft MI/H-KM/H\n");
	printf("Escribe un valor: ");
	scanf("%i",&val);

	printf("---------------------------------------------------------\n");
	printf("*                     TEMPERATURE                       *\n");
	printf("* Celcius to Farenheit      |   Farenheit to Celcius    *\n");
	convers=val*1.8+32;
	printf("* %i C = %f F	    |",val,convers);
	convers=(val-32)/1.8;
	printf("   %i F = %f C	*\n",val,convers);
	printf("---------------------------------------------------------");

	printf("\n\t\t   LENGTH\n");
	printf("Centimeters to inches \t   Inches to Centimeters\n");
	convers=val*0.3937;
	printf("%i cm = %f in\t",val,convers);
        convers=val/0.3937;
	printf("   %i in = %f cm\n",val,convers);
	
	printf("\nMeters to feets \t   Feets to Meters\n");
	convers=val*3.281;
	printf("%i m = %f ft\t",val,convers);
	convers=val/3.281;
	printf("   %i ft = %f m\n",val,convers);
	
	printf("\n\t\t   SPEED\n");
	printf("mi/h to km/h \t\t   km/h to mi/h\n");
	convers=val*1.609;
	printf("%i mi/h = %f km/h",val,convers);
	convers=val/1.609;
	printf("   %i km/h = %f mi/h\n",val,convers);
}

