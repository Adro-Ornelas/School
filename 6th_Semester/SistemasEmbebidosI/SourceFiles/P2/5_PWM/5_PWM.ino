// 5_PWM

#define pinANG 0
#define pinLED 3

void setup() {

  Serial.begin(9600);           // Serial a 9600 baudios
  pinMode(pinANG, INPUT);       // Pin a entrada analogica
  pinMode(pinLED, OUTPUT);      // Pin a LED, salida
  
}

void loop() {

   int readA = analogRead(pinANG);    // Lee valor analogico con ADC
   // Divide entre cuatro, resolucion del ADC simplificada a 8 bits para escribir con PWM
   analogWrite(pinLED, readA / 4);        // PWM a LED
   float voltaje = readA * 5.0 / 1023.0;
   Serial.print(voltaje);             // Imprime en monitor valor en volts
   Serial.print(" V - \t");             // Tabulador para imprimir ambos
   Serial.println(readA);             // Imprime en monitor valor de ADC

}
