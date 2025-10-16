// LCD_Serial.c
#include <16F877A.h>

// Con cristal de 20,000,000 Hz
#use delay (clock=20M)

// XTAl de alta velocidad, no watch dog, no proteger código, no low voltage protection
#fuses HS, NOWDT, NOPROTECT, NOLVP

#use rs232(baud=57600, xmit=pin_c6, rcv=pin_c7, bits=8)
#include <lcd.c>

#byte PORTB=0x06
#byte PORTC=0x07
#byte PORTD=0x08

#byte trisb=0X86
#byte trisc=0X87
#byte trisd=0X88

int valor;
#int_RDA
void RDA_isr(){
   valor = getc();
}

void main(){
   
     trisd=0X00; // Puerto D como salida a LCD
     enable_interrupts(INT_RDA);
     enable_interrupts(GLOBAL);
     lcd_init();
     
     while(1){
       lcd_gotoxy(1, 1);
       // Como son 8 bits y máximo 5 volts, hace regla de tres con estos valores
       printf(lcd_putc, "Leo %f V", valor * 5.0 / 255.0);
       
       lcd_gotoxy(1, 2);
       lcd_putc("Es ");
       
       // > 2.5 V es mayor, de lo contrario es menor
       if(valor > 128)
         lcd_putc("mayor");
       else
         lcd_putc("menor");
     }
}
