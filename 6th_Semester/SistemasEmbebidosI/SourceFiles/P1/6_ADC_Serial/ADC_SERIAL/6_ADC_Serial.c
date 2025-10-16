// ADC_Serial.c
#include <16F877A.h>
#device adc=8
// Con cristal de 20,000,000 Hz
#use delay (clock=20M)

// XTAl de alta velocidad, no watch dog, no proteger código, no low voltage protection
#fuses HS, NOWDT, NOPROTECT, NOLVP

#use rs232(baud=57600, xmit=pin_c6, rcv=pin_c7)

#byte PORTA=0X05
#byte PORTB=0x06
#byte PORTC=0x07
#byte PORTD=0x08

#byte trisa=0X85
#byte trisb=0X86
#byte trisc=0X87
#byte trisd=0X88


long inputA;
void main(){

   
   set_tris_a(0b00000001);          //Pongo el RA0 como entrada
   setup_adc_ports(all_analog);     //Pongo todo el puerto a analogo
   setup_adc(adc_clock_internal);   //Selecciono reloj interno para conversion
 
   
   while(1){
      set_adc_channel(0);
      delay_ms(1);
      inputA = read_adc();          // Lee digital de ADC
      putc(inputA);                 // Envía de manera serial, la entrada digital del adc al otro pic
       
   }
   
}
