// Menu.c

#include <16F877A.h>
// XTAl de alta velocidad, no watch dog, no proteger código, no low voltage protection
#fuses HS, NOWDT, NOPROTECT, NOLVP

// Con cristal de 20,000,000 Hz
#use delay (clock=20M) 
   
#byte PORTB=0x06
#byte PORTC=0x07
#byte PORTD=0x08

#byte trisb=0X86
#byte trisc=0X87
#byte trisd=0X88

void main(){

   // Puerto B como salida exepto el MSB, que será botón "enter"
   trisb=0x80;
   // Puerto C como salida a 8 LEDs
   trisc=0x00;
   // Puerto D como entrada a dip switch 8 segmentos
   trisd=0XFF;
   
   int option;
   long x, y, z;
   
   // Main Loop
   while(1) {

     portb = 0;      // Limpia salidas
     portc = 0;
   
      // Animación de inicio
      for(int i = 0; i < 3; ++i){
      portc = 0b00011000;
      delay_ms(100);
      portc = 0b00111100;
      delay_ms(100);
      portc = 0b01111110;
      delay_ms(100);
      portc = 0b11111111;
      delay_ms(100);
      }
      portc = 0;
      // Fin animación
     
      // Option Loop
      while(input(PIN_B7));  // Cuando PIN_B7 sea 0 el botón fue presionado
      option = portd;   // Lee dip switch 
      delay_ms(300);   // Retardo por rebote
      
      
      portc = option;   // Muestra opción elegida en LEDs
      switch(option) {
         
         case 1:  // Animacion rotabit
            
            // De izquierda a derecha: (barra de progreso)
            int x = 0x80;
            for(int i = 0; i < 8; ++i){
               portc = x;
               x >>= 1; // Rota un bit a la derecha
               x += 0x80;
               delay_ms(100);
            }
            x = 0xFF;
            for(int i = 0; i < 8; ++i){
               x -= 0x01;
               x >>= 1; // Rota un bit a la derecha
               portc = x;
               delay_ms(100);
            }
            // De derecha a izquierda: (barra de desprogreso)
            x = 0x01;
            for(int i = 0; i < 8; ++i){
               portc = x;
               x <<= 1; // Rota un bit a la derecha
               x += 0x01;
               delay_ms(100);
            }
            x = 0xFF;
            for(int i = 0; i < 8; ++i){
               x -= 0x80;
               x <<= 1; // Rota un bit a la derecha
               portc = x;
               delay_ms(100);
            }
            
         break;
         
         case 2:   // División de dos números
          while(input(PIN_B7));  // Hasta que el botón sea presionado
           x = portd;      // Lee valor
           portc = x;      // Muestra x recibido
            delay_ms(300);   // Delay de rebote
           while(input(PIN_B7));  // Hasta que el botón sea presionado
           y = portd;      // Lee valor
           portc = y;      // Muestra valor recibido
            delay_ms(900);   // Delay de rebote y visualizar valor
            portc = 0;      // Limpia salida para efecto de parpadeo
            delay_ms(200);   // Delay de parpadeo
            if(0 == y)      // Si el divisor es cero terminar
               break;
            portc = x / y;   // Muestra la división en los LEDs
         break;
         
         case 3:   // MCD de dos números
          while(input(PIN_B7));  // Hasta que el botón sea presionado
           x = portd;      // Lee valor
           portc = x;      // Muestra valor recibido
           delay_ms(300);   // Delay de rebote
           while(input(PIN_B7));  // Hasta que el botón sea presionado
           y = portd;      // Lee valor
           portc = y;      // Muestra valor recibido
           delay_ms(900);   // Delay de rebote y visualizar valor
           portc = 0;      // Limpia salida para efecto de parpadeo
           delay_ms(200);   // Delay de parpadeo
             
            // Calcula MCD con el algoritmo de euclides
            if(y > x) {      // y debe ser menor o igual a x
               z = y;
               y = x;
               x = z;
            }
            while(x % y != 0){
               z = x % y;
               x = y;
               y = z;
            }
            
            portc = y;      // Muestra MCD
            
         break;
              
         case 4:   // Mayor de tres números
          while(input(PIN_B7));  // Hasta que el botón sea presionado
          x = portd;      // Lee valor 1
          portc = x;      // Muestra valor recibido
           delay_ms(300);   // Delay de rebote
           while(input(PIN_B7));  // Hasta que el botón sea presionado
          y = portd;      // Lee valor 2
          portc = y;      // Muestra valor recibido
           delay_ms(300);   // Delay de rebote
          while(input(PIN_B7));  // Hasta que el botón sea presionado
          z = portd;      // Lee valor 3
          portc = z;      // Muestra valor recibido
           delay_ms(900);   // Delay de rebote y visualizar valor
           portc = 0;      // Limpia salida para efecto de parpadeo
           delay_ms(200);   // Delay de parpadeo
           
           // Encuentra el mayor y lo imprime
           if(x > z)
              if(x > y)
                 portc = x;
              else
                 portc = y;
           else
              if(z > y)
                 portc = z;
              else
                 portc = y;
           
         break;
         
         case 5:   // Fórmula (xy + yz) / (x^2 + z^2)
              
          while(input(PIN_B7));  // Hasta que el botón sea presionado
          x = portd;      // Lee valor 1
          portc = x;      // Muestra valor recibido
           delay_ms(300);   // Delay de rebote
           while(input(PIN_B7));  // Hasta que el botón sea presionado
          y = portd;      // Lee valor 2
          portc = y;      // Muestra valor recibido
           delay_ms(300);   // Delay de rebote
          while(input(PIN_B7));  // Hasta que el botón sea presionado
          z = portd;      // Lee valor 3
          portc = z;      // Muestra valor recibido
           delay_ms(900);   // Delay de rebote y visualizar valor
           portc = 0;      // Limpia salida para efecto de parpadeo
           delay_ms(200);   // Delay de parpadeo
         
           // r = (xy + yz) / (x^2 + z^2) Si x=10,y=100,z=2, R=11
           portc = (x*y + y*z) / (x*x + z*z);
              
           /*   Alternativa
              Fórmula de Bhaskara (chicharronera)
              Importar math.h
              // Resultado positivo:
              portc = (-b + sqrt(b*b - 4*a*c) / (2*a);
              // Retardo:
              delay_ms(900);
              // Resultado negativo:
              portc = (-b - sqrt(b*b - 4*a*c) / (2*a);
                 
           */
         break;
         
         case 6:   // Imprimir en display "Adro Ornelas2"
         //   La distribución del display es g-f-e-d-c-b-a
           portb = 0b01110111;   // A
           delay_ms(500);
           portb = 0b01011110;   // d
           delay_ms(500);
           portb = 0b01010000;   // r
           delay_ms(500);
           portb = 0b01011100;   // o
           delay_ms(500);
           portb = 0b00000000;   // Espacio
           delay_ms(200);
           portb = 0b00111111;   // O
           delay_ms(500);
           portb = 0b01010000;   // r
           delay_ms(500);
           portb = 0b01010100;   // n
           delay_ms(500);
           portb = 0b01111011;   // e
           delay_ms(500);
           portb = 0b00111000;   // L
           delay_ms(500);
           portb = 0b01110111;   // A
           delay_ms(500);
           portb = 0b01101101;   // S
           delay_ms(500);
           portb = 0b01011011;   // 2
           delay_ms(500);
         break;
         
         default: // Opción inválida
         portc = 0b01010101;
      }  
       while(input(PIN_B7));   // Hasta que el botón sea presionado
   }
   
}
