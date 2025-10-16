// 1_Menu

// A4 (18) como interruptor que activa Display con un BJT 2N2222
#define DISPLAY_E 18

// A5 (19) como boton enter, se activa con LOW
#define ENTER 19

// Pines D9 - D2 (9 - 2) como entrada MSB - LSB
const byte DIPs[8] = {9, 8, 7, 6, 5, 4, 3, 2};

// Pines D10, D11, D12, D13, A0, A1, A2, A3 (Numeros 10 - 17) MSB - LSB
const byte LEDs[8] = {10, 11, 12, 13, 14, 15, 16, 17};

// Nombre con distribución de display (g-f-e-d-c-b-a-.)
// 'Adro Ornelas2.'
const byte nombre[13] = {0xEF, 0xBC, 0xA0, 0xB8, 0x00, 0x7E, 0xA0, 0xA8, 0xF6, 0x70, 0xEF, 0xDA, 0xB7};

void setup() {
  
  // Para activar display como salida
  pinMode(ENTER, OUTPUT);

  // Boton bytero como entrada
  pinMode(ENTER, INPUT);

  // Pines de LEDs como salida, Pines de DIPs como entrada
  for(byte i = 0; i < 8; ++i){
    pinMode(DIPs[i], INPUT);
    pinMode(LEDs[i], OUTPUT);
  }
}

void loop() {

  animacion();
  byte opt;
  byte y, z;
  
  while(digitalRead(ENTER) == HIGH);  // Espera pulso de botón
  opt = readDIPs();                  // Lee entrada
  printLEDs(opt);                     // Imprime seleccion
  delay(680);                         // Delay rebote + tiempo para visualizar
  printLEDs(0x00);                     // Limpia salida
  
  if(opt == 0x00){    // Corrimiento LEDs
      
        byte i = 0;
        for(byte k = 0; k < 2; ++k){
          while(i < 8){
              digitalWrite(LEDs[i], HIGH);
              delay(50);
              digitalWrite(LEDs[i], LOW);
              ++i;
            }
          while(i > 0){
              --i;
              digitalWrite(LEDs[i], HIGH);
              delay(50);
              digitalWrite(LEDs[i], LOW);
            }
        }
           
  } else if (opt == 0x01){ // Suma de dos numeros    
    
      while(digitalRead(ENTER) == HIGH); // Espera pulso de botón
      y = readDIPs();                   // Lee valor 1
      printLEDs(y);                     // Imprime entrada
      delay(330);                       // Delay rebote
      
      while(digitalRead(ENTER) == HIGH); // Espera pulso de botón
      z = readDIPs();                   // Lee valor 2
      printLEDs(z);                     // Imprime entrada
      delay(680);                       // Delay rebote y visualizacion

      printLEDs(y + z);                 // Imprime suma
            
  } else if (opt == 0x02){  // Resultado de (y*y + 3*z) / (2 * y)
      
      while(digitalRead(ENTER) == HIGH);// Espera pulso de botón
      y = readDIPs();                   // Lee valor 1
      printLEDs(y);                     // Imprime entrada
      delay(330);                       // Delay rebote
      
      while(digitalRead(ENTER) == HIGH);// Espera pulso de botón
      z = readDIPs();                   // Lee valor 2
      printLEDs(z);                     // Imprime entrada
      delay(680);                       // Delay rebote y visualizacion

      byte r = (y*y + 3*z) / (2 * y);   // Calcula resultado
      // Si y = 0x49 y z = 0x99, r = 27
      printLEDs(r);                     // Imprime resultado
       
  } else if (opt == 0x03){
    
    // Semaforo con LEDs LSB (4, 5, 6, 7) (array indexes)
    // Verde - vuelta - amarillo - rojo
    // Verde y vuelta con flecha
    printLEDs(0x0C);
    delay(4000);
    // Solo verde
    printLEDs(0x008);
    delay(4000);
    // Amarillo
    printLEDs(0x02);
    delay(1000);
    // Rojo
    printLEDs(0x01);
    delay(1000);
        
  } else if (opt == 0x04) { // Numeros de y a z
      
      while(digitalRead(ENTER) == HIGH);// Espera pulso de botón
      y = readDIPs();                   // Lee valor 1
      printLEDs(y);                     // Imprime entrada
      delay(330);                       // Delay rebote
      
      while(digitalRead(ENTER) == HIGH);// Espera pulso de botón
      z = readDIPs();                   // Lee valor 2
      printLEDs(z);                     // Imprime entrada
      delay(680);                       // Delay rebote y visualizacion

      while(y <= z) {                    // Si es ascendente
        printLEDs(y++);
        delay(300);
      }      
      while(y >= z) {                    // Si es descendente
        printLEDs(y--);
        delay(300);
      }
      
      
  } else if (opt == 0x05){    // Nombre en display

    // Activa display
    digitalWrite(DISPLAY_E, HIGH);

    // Imprime tabla de valores
    for(byte i = 0; i < 13; ++i){
      printLEDs(nombre[i]);
      delay(600);
    }    
    // Desactiva display
    digitalWrite(DISPLAY_E, LOW);
  }
  while(digitalRead(ENTER) == HIGH);  // Espera pulso de botón
}

void animacion(){
  
  byte i = 8;
  digitalWrite(DISPLAY_E, HIGH); // Activa display
  
  // Apagar LEDs
  while(i > 0){
    digitalWrite(LEDs[--i], LOW);
    delay(15);
  }
  // Animacion, tres corrimientos de izq a derehca
  for(byte j = 0; j < 3; ++j){
    while(i < 8){
      digitalWrite(LEDs[i++], HIGH);
      delay(30);
    }
    while(i > 0){
      digitalWrite(LEDs[--i], LOW);
      delay(30);
    }
  }
  digitalWrite(DISPLAY_E, LOW); // Desactiva display
}

byte readDIPs(){
  // Devuelve el valor decimal de 8 bits introducido por el DIP Switch
  byte val;
  for(byte i = 0; i < 8; ++i)
    bitWrite(val, i, digitalRead(DIPs[7 - i]));
   return val;
}

void printLEDs(byte val){ 
  // Imprime el parametro val en 8 LEDs
  for(byte i = 0; i < 8; ++i)
    digitalWrite(LEDs[i], bitRead(val, 7 - i)); 
   
}
