
const byte intro = 6;

void setup() {
  // Pines de 2 (LSB) a 5 (MSB) Dip Switch (Entrada)
  for(int pinI = 2; pinI < 6; ++pinI)
    pinMode(pinI, INPUT);

 pinMode(intro, INPUT);  // Para botón de intro
    
  // Pines de 8 (LSB) a 12 (MSB) LEDs (Salida)
  for(int pinO = 8; pinO < 13; ++pinO)
    pinMode(pinO, OUTPUT);

}

int val1, val2, suma; // Guardará valores a sumar (val tiene MAX de 15) (suma MAX de 30)

void loop() {

  animacion();

  suma = val1 = val2 = 0;  // Necesario inicializar en ceros
  
  while(digitalRead(intro) == HIGH);   // Hasta que intro sea presionado
  // Lee val1 con pines 2 a 5 conviertendo a decimal
  for(int pin = 2, pot = 1; pin <= 5; ++pin, pot *=2)
    val1 += digitalRead(pin) * pot;
   for(int i = 8; i < 12; ++i)
    digitalWrite(i, digitalRead(i-6));
   //printBinary(val1); // Manda valor a LEDs
   delay(330);  // Delay de rebote
    
  while(digitalRead(intro) == HIGH);   // Hasta que intro sea presionado
  // Lee val2 con pines 2 a 5 conviertendo a decimal
  for(int pin = 2, pot = 1; pin <= 5; ++pin, pot *=2)
    val2 += digitalRead(pin) * pot;
   printBinary(val2); // Manda valor a LEDs
   delay(930);  // Delay de rebote y visualizar segundo sumando

  suma = val1 + val2;

  // Imprime en LEDs (pin 7 a 11), convierte suma a valor binario
  printBinary(suma);
  
  while(digitalRead(intro) == HIGH);   // Hasta que intro sea presionado
  delay(300);  // Delay de rebote
}

void animacion(){


  // Todo LED en LOW
  for(int i = 8; i < 13; ++i)
    digitalWrite(i, LOW);
  
  int nled = 8;
  while(nled < 13){
    digitalWrite(nled++, HIGH);
    delay(300);
  }

  // Todo LED en LOW
  for(int i = 8; i < 13; ++i)
    digitalWrite(i, LOW);

  --nled;
  while(nled > 7){
    digitalWrite(nled--, HIGH);
    delay(300);
  }
     
  // Todo LED en LOW
  for(int i = 8; i < 13; ++i)
    digitalWrite(i, LOW);
}

void printBinary(int bin){   // Imprime en los 5 LEDs el número bin

  // Todo LED en LOW
  for(int i = 8; i < 13; ++i)
    digitalWrite(i, LOW);

  // Como los LEDs ya están en LOW, solo activa unos como HIGH
  // Convierte a binairo e imprime
  int nled = 8;
  while(bin > 0){
    if(bin % 2 == 1)
      digitalWrite(nled, HIGH);
     bin /= 2;
     nled++;
  }
  
}
