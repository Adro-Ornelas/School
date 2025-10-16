// Password.c

#include <16F877A.h>

// Con cristal de 20,000,000 Hz
#use delay (clock=20M) 
#include <lcd.c>	// Pantalla
#define USE_PORTB_KBD 
#include <kbd4x4.c>	// Teclado

// XTAl de alta velocidad, no watch dog, no proteger código, no low voltage protection
#fuses HS, NOWDT, NOPROTECT, NOLVP

#byte PORTB=0x06
#byte PORTC=0x07
#byte PORTD=0x08

#byte trisb=0X86
#byte trisc=0X87
#byte trisd=0X88

void main() {
   
   	
	// trisb=0x00; Puerto B a teclado
	trisc=0x00;	// Puerto C, 2 bits menos significativos a LED
	trisd=0X00; // Puerto D como salida a LCD
   	
	portc = 0;	// Estado inicial del puerto C en BAJO
	// Activa resistencias en pull up puerto B
	PORT_B_PULLUPS(0xFF);
   
	kbd_init();
	lcd_init();
   	
	printf(lcd_putc, "Adro\nOrnelas");	// Print
	delay_ms(5000);	// Delay 5 secs
   	
	const char passw[4]={'1', '2', '3', '9'};	// Contraseña correcta
	char passwu[4];	// Contraseña que se recibe
	char c;	// Char individual recibido
	int ichar;	// Índice para la cotraseña que se recibe
	while(1){
		lcd_putc("\f");	// Clear display
		lcd_putc("Contrase");  	
		lcd_putc(0xEE);	// Escribir ñ
		lcd_putc("a:\n");
		lcd_cursor_on(true);	// Activar cursor
		ichar = 0;
		while(ichar < 4){	// Mientras menos de 4 chars introducidos
			c = kbd_getc();
			if(c != '\0'){	// If a key was pressed
				switch(c){	// Decodifica tecla
			   	
					case '1':
						lcd_putc('7');
						passwu[ichar] = '7';
					break;
					case '2':
						lcd_putc('8');
						passwu[ichar] = '8';
					break;
					case '3':
						lcd_putc('9');
						passwu[ichar] = '9';
					break;
				   	
					case '4':
					case '5':
					case '6':
					case '0':
						lcd_putc(c);
						passwu[ichar] = c;
					break;
		   	
					case '7':
						lcd_putc('1');
						passwu[ichar] = '1';
					break;
					case '8':
						lcd_putc('2');
						passwu[ichar] = '2';
					break;
					case '9':
						lcd_putc('3');
						passwu[ichar] = '3';
					break;
				   	
					default:
						--ichar; // Si no fue un número no es válido
				}
				++ichar;	// Aumenta índice de cadena de carácteres 
			}
		} 
	   	
		int iguales = 1;	// Como booleano, será true hasta ser false
		for(int i = 0; i < 4; ++i)	// Comparar contraseñas
			if(passw[i] != passwu[i])
				iguales = 0;
			   	
		lcd_gotoxy(11,1);
		lcd_putc(' ');	// Borrar dos puntos
		lcd_gotoxy(1, 2);	// Ir a segunda linea
		if(iguales == 1){	// Si contraseña correcta
			lcd_putc("CORRECTA");
			output_high(PIN_C1);	// Encender LED verde
		} else {
			lcd_putc("INCORRECTA");
			output_high(PIN_C0);	// Encender LED rojo
		}
	   	
		while(kbd_getc() == '\0'); // No continuar hasta presionar una tecla
		portc = 0;	// Estado inicial del puerto C en BAJO
	}
}
