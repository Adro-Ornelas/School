// Password.c

#include <16F877A.h>

// Con cristal de 20,000,000 Hz
#use delay (clock=20M) 
#include <lcd.c>	// Pantalla
#define USE_PORTB_KBD 
#include <kbd.c>	// Teclado
#include <math.h>
// XTAl de alta velocidad, no watch dog, no proteger código, no low voltage protection
#fuses HS, NOWDT, NOPROTECT, NOLVP

#define TDELAY 1800	// Delay para visualizar

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
   	

   	
   	
	char c;
	int temp;
   	
	while(1){	// Menú
		lcd_cursor_on(false);
		lcd_putc("\f1-Caminata\n2-Promedio de 3");
		delay_ms(TDELAY);
		lcd_putc("\f3-Mayor de tres\n4-Par de 0 a 90");
		delay_ms(TDELAY);
		lcd_putc("\f5-De X a Y\n6-EQ Hipotenusa");
		delay_ms(TDELAY);
		lcd_putc("\fSeleccionar[1-6]\n[0]Restart:");
		lcd_cursor_on(true);
		do{	// Itera hasta recibir elección del menú
			c = kbd_getc();
		} while(c == '\0');
	   	
		switch(c){
			case '1':	// Caminata
				lcd_cursor_on(false);
				lcd_putc("\f1-Caminata");
				for(int x = 1; x <= 16; ++x){	// 16 posiciones de caminata
					lcd_gotoxy(x, 2);
					lcd_putc(0x7E);		// Escribe caracter
					delay_ms(200);
					lcd_putc("\b ");	// Vuelve a las coordenadas y borra anterior
				}
				for(int x = 16; x > 0; --x){	// 16 posiciones de caminata
					lcd_gotoxy(x, 2);
					lcd_putc(0x7F);		// Escribe caracter
					delay_ms(200);
					lcd_gotoxy(x, 2);	// Regresar a coordenada
					lcd_putc(" ");	// Borra caracter
				}
			break;
		   	
			case '2':	// Promedio de tres
				long int suma = 0;	// Guardará suma (max 297)
				double avg;		// Guardará promedio
				lcd_putc("\f2-Promedio de 3");
			   	
				for(int i = 1; i <=3; ++i){	// Ciclo para tres valores
					lcd_gotoxy(1, 2);
					printf(lcd_putc, "                ");	// Limpia línea 2
					lcd_gotoxy(1, 2);
					printf(lcd_putc, "Valor %d: ", i);
					do{	// Itera hasta recibir elección del primer dígito
						c = kbd_getc();
					} while(c == '\0');
				   	
					lcd_putc(c);		// Imprime en pantalla primer dígito
					temp = (c - 0x30) * 10;	// Resta 0x30 por ASCII
				   	
					do{	// Itera hasta recibir elección del segundo dígito
						c = kbd_getc();
					} while(c == '\0');
				   	
					lcd_putc(c);		// Imprime en pantalla segundo dígito
					temp += c - 0x30;	// Resta 0x30 por ASCII
					suma += temp;
					delay_ms(200);	// Delay para visualizar el número completo
				}
			   	
				avg = suma / 3.0;
				lcd_gotoxy(1,2);
				printf(lcd_putc, "                ");	// Limpia línea 2
				lcd_gotoxy(1,2);
				printf(lcd_putc, "Media = %g", avg);	// Imprime promedio
			   	
			break;
		   	
			case '3':	// Mayor de tres números
		   	
				lcd_putc("\f3-Mayor de 3");
				int mayor;	// Sólo guardará el mayor
			   	
				for(int i = 1; i <=3; ++i){	// Ciclo para tres valores
					lcd_gotoxy(1, 2);
					printf(lcd_putc, "                ");	// Limpia línea 2
					lcd_gotoxy(1, 2);
					printf(lcd_putc, "Valor %d: ", i);
					do{	// Itera hasta recibir elección del primer dígito
						c = kbd_getc();
					} while(c == '\0');
				   	
					lcd_putc(c);		// Imprime en pantalla primer dígito
					temp = (c - 0x30) * 10;	// Resta 0x30 por ASCII
				   	
					do{	// Itera hasta recibir elección del segundo dígito
						c = kbd_getc();
					} while(c == '\0');
				   	
					lcd_putc(c);		// Imprime en pantalla segundo dígito
					temp += c - 0x30;	// Resta 0x30 por ASCII
				   	
					if(1 == i)			// El primero es el primer mayor
						mayor = temp;
					else
						if(temp > mayor) // Si se introduce otro dato mayor, ese será "mayor"
							mayor = temp;
				   	
					delay_ms(200);	// Delay para visualizar el número completo
				}
			   	
				lcd_gotoxy(1,2);
				printf(lcd_putc, "                ");	// Limpia línea 2
				lcd_gotoxy(1,2);
				printf(lcd_putc, "Mayor = %d", mayor);	// Imprime mayor
							   	
			break;
		   	
			case '4':	// Pares de 0 a 90
				/*	Como se usará una línea de 16 espacios y cada número
					necesita de 4 lugares: "XX, ", en cada línea caben 4
					números, por lo que se imprimirán 4 valores, se
					borraran y apareceran los siguientes			   	
				*/
			   	
				lcd_putc("\f3-Par de 0-90");
				for(int i = 0, cuatro = 0; i <= 90; i+=2, ++cuatro){
					if(cuatro == 4)
						cuatro = 0;
					if(cuatro == 0){	// Cada cuatro limpia y regresa
						lcd_gotoxy(1, 2);
						printf(lcd_putc, "                ");	// Limpia línea 2
						lcd_gotoxy(1, 2);
					}
					printf(lcd_putc, "%d, ", i);
					delay_ms(800);	// Delay para visualizar
				}
			   	
			break;
		   	
			case '5':	// Números de X a Y
			   	
				int values[2];	// Guarda x y y
				lcd_putc("\f5-De X a Y\n");
			   	
				for(int i = 0; i < 2; ++i){	// Ciclo para dos valores
					printf(lcd_putc, "Valor %d: ", i + 1);
					do{	// Itera hasta recibir elección del primer dígito
						c = kbd_getc();
					} while(c == '\0');
				   	
					lcd_putc(c);		// Imprime en pantalla primer dígito
					values[i] = (c - 0x30) * 10;	// Resta 0x30 por ASCII
				   	
					do{	// Itera hasta recibir elección del segundo dígito
						c = kbd_getc();
					} while(c == '\0');
				   	
					lcd_putc(c);		// Imprime en pantalla segundo dígito
					values[i] += c - 0x30;	// Resta 0x30 por ASCII
				   	
					lcd_gotoxy(1,2);
					printf(lcd_putc, "                ");	// Limpia línea 2
					lcd_gotoxy(1,2);	// Regresa cursor
				}
				int cuatro = 0;
				while(values[0] <= values[1]){
					if(cuatro == 4)
						cuatro = 0;
					if(cuatro == 0){	// Cada cuatro limpia y regresa
						lcd_gotoxy(1, 2);
						printf(lcd_putc, "                ");	// Limpia línea 2
						lcd_gotoxy(1, 2);
					}
					printf(lcd_putc, "%d, ", values[0]);
					delay_ms(800);	// Delay para visualizar
					++values[0];
					++cuatro;
				}
			   	
			break;
			case '6':	// Ecuación de la hipotenusa
				// c = sqrt(a^2 + b^2)
				int a, b;	// Guarda catetos a y b (max 9 c/u)
				double h;	// Guarda hipotenusa
				lcd_putc("\f6-EQ-Hipotenusa\n");
			   	
			   	
				printf(lcd_putc, "Cateto 1:");	// Limpia línea 2
				do{	// Itera hasta recibir a
					c = kbd_getc();
				} while(c == '\0');
				a = c - 0x30;
			   	
				lcd_gotoxy(1,2);
				printf(lcd_putc, "                ");	// Limpia línea 2
				lcd_gotoxy(1,2);
				printf(lcd_putc, "Cateto 2:");
				do{	// Itera hasta recibir b
					c = kbd_getc();
				} while(c == '\0');
				b = c - 0x30;
			   	
				h = sqrt(a*a + b*b);
			   	
				lcd_gotoxy(1,2);
				printf(lcd_putc, "                ");	// Limpia línea 2
				lcd_gotoxy(1,2);	// Regresa cursor
				printf(lcd_putc, " c = %g", h);	// Imprime
			   	
			   	
			break;
		   	
			case '0':	// Si la selección es cero, reinicia
				break;
			default:	// Si la selección es invalida, muetsra mensaje y reinicia
				lcd_putc("\fOpcion invalida");
				delay_ms(TDELAY);
				c = '0';
			break;
		   	
		}
		if(c != '0'){
			delay_ms(500);
			lcd_cursor_on(true);
			lcd_putc("\a[Any]Reiniciar:");
   	
			while(kbd_getc() == '\0');	// Itera hasta recibir cualquier tecla
		}	   	
	}   	
}
