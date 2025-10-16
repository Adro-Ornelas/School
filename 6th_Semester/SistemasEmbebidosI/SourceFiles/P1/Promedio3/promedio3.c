// Promedio de tres números
#include <16F877A.h>

// XTAl de alta velocidad, no watch dog, no proteger código, no low voltage protection
#fuses HS, NOWDT, NOPROTECT, NOLVP

// Con cristal de 20,000,000 Hz
#use delay (clock=20M) 

// Establece las direcciones de los puertos
#byte portb=0x06
#byte portc=0x07
#byte portd=0x08
#byte trisb=0x86
#byte trisc=0x87
#byte trisd=0x88

void animac(){
	// Animación de inicio
	portb = 0b00011000;
	delay_ms(700);
	portb = 0b00111100;
	delay_ms(700);
	portb = 0b01111110;
	delay_ms(700);
	portb = 0b11111111;
	delay_ms(700);
	portb = 0;
	delay_ms(700);
}

void main(){
   	
   	
	trisb = 0x00; // Puerto B como salida (8 LEDs)
	trisc = 0xff; // Puerto C como entrada (dip switch)
	trisd = 0xff; //  RD7 como entrada (tecla "intro/enter") 
   	
	long int suma; // Guardará la suma de tres números
   	
	while(1){
		suma = 0;
		animac();	// Animación de inicio
	   	
		for(int i=0; i < 3; ++i) {	// Ciclo para pedir tres números
			while(input(PIN_D7)); // Mientras el boton a RD7 no se presione
			suma += portc; // Suma el valor actual
			portb = portc; // Muestra la entrada en puerto B (LEDs)
			delay_ms(900); // Delay de rebote
		}
	   	
		portb = 0; // Salida en BAJO para efecto de parpadeo
		delay_ms(300);
	   	
		suma /= 3;	// El promedio de tres número es su suma dividida entre 3
	   	
		portb = suma; // Muestra resultado

		delay_ms(1000);	// Delay 1 segundo
		// No continuar hasta presionar el boton a RD7
		while(input(PIN_D7));
	}
   	
}



