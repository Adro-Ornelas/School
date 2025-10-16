#define inter0 2  // Interrupcion 0 (D2)
volatile int pulsos = 0; // Para usar en interrupción
void setup() {
 // Inicio serial en la velocidad adecuada
 Serial.begin(57600);

 // Interrupción en subida para motor
 attachInterrupt(digitalPinToInterrupt(inter0), giro, RISING);
}

void loop() {
 delay(999);  // Delay de casi 1 segundo para corrección
 Serial.print(pulsos * 12); // 5 aspas, ... pulsos / 5 * 60seg
 Serial.print("RPM");
 
}
void giro(){  // nuevo pulso
 ++pulsos;
}
