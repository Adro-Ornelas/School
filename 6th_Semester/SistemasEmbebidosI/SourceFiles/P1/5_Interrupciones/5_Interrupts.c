// Password.c

#include <16F877A.h>

// Con cristal de 20,000,000 Hz
#use delay (clock=20M)

// XTAl de alta velocidad, no watch dog, no proteger código, no low voltage protection
#fuses HS, NOWDT, NOPROTECT, NOLVP

#byte PORTB=0x06
#byte PORTC=0x07
#byte PORTD=0x08

#byte trisb=0X86
#byte trisc=0X87
#byte trisd=0X88

int atimer0 = 0;
#int_rtcc
void aint_timer0() {
   
   set_rtcc(0);
   if(atimer0 > 7) {        // (4 / 20Mhz) * 256 * 256 * 76 = 0.9961
      output_toggle(PIN_C7);  // Prende y apga cada dos segundos
      atimer0 = 0;
      
   } else {
      atimer0++;
   }
}

#int_ext
void aint_ext() {       // Función de interrupción extera B0
      // Imprimir en display "Adro Ornelas2"
        //   La distribución del display es g-f-e-d-c-b-a
        portb = 0b11101110;   // A
        delay_ms(500);
        portb = 0b10111100;   // d
        delay_ms(500);
        portb = 0b10100000;   // r
        delay_ms(500);
        portb = 0b10111000;   // o
        delay_ms(500);
        portb = 0b00000000;   // Espacio
        delay_ms(200);
        portb = 0b01111110;   // O
        delay_ms(500);
        portb = 0b10100000;   // r
        delay_ms(500);
        portb = 0b10101000;   // n
        delay_ms(500);
        portb = 0b11110110;   // e
        delay_ms(500);
        portb = 0b01110000;   // L
        delay_ms(500);
        portb = 0b11101110;   // A
        delay_ms(500);
        portb = 0b11011010;   // S
        delay_ms(500);
        portb = 0b10110110;   // 2
        delay_ms(500);
}

void main() {

   trisb = 0x01;  // Puerto B como salida, excepto B0 para interrupción 
   PORTB = 0x00;  // Puerto B inicia en BAJO
   trisc = 0x00;  // Puerto C como salida
   PORTC = 0x00;  // Puerto C inicia en BAJO
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256 | RTCC_8_BIT);   // Timer 0 con prescaler de 256
   set_timer0(0);                                  // Timer 0 inicia en 0
   enable_interrupts(int_timer0);                  // Habilita interrupciones por timer 0
   enable_interrupts(int_ext);
   enable_interrupts(global);                      // Habilita interrupciones
   
   // Números del 0 al 9
   // La distribución del display es g-f-e-d-c-b-a-.
   const char numbers[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC, 0xDA, 0xFA, 0x0E, 0xFE, 0XCE};
   
   int i = 0;  // Para mostrar número
   
   while(1){
      portb = numbers[i++];   // Imprime número y aumeta índice
      if(i > 9)
         i = 0;               // Evitar sobrepasar índice
         delay_ms(200);
   }  
}
