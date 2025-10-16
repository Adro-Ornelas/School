// 4_Distancia

#include <LiquidCrystal.h>
// Establece filas y columnas de LCD
#define LCD_ROWS 4
#define LCD_COLS 20

// Objeto LiquidCrystal (RS, E, D4, D5, D6, D7) son (D7, D6, D5, D4, D3, D2) respectivamente
LiquidCrystal lcd(5, 4, 3, 2, 1, 0);

// Defincion de pines
#define TRIGGER 11
#define ECHO 10
#define zumbador A0
#define LED1 A1
#define LED2 A2
#define LED3 A3
#define LED4 A4

// Definicion de notas
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047

int notas[15]{
  /*  Notas a tocar por el zumbador   
   *  Dos octavas, más agudo(B5) = más cerca
   *  
  */
  NOTE_C4,
  NOTE_D4,
  NOTE_E4,
  NOTE_F4,
  NOTE_G4,
  NOTE_A4,
  NOTE_B4,
  NOTE_C5,
  NOTE_D5,
  NOTE_E5,
  NOTE_F5,
  NOTE_G5,
  NOTE_A5,
  NOTE_B5,
  NOTE_C6
 
};

void setup() {  
  lcd.begin(LCD_COLS, LCD_ROWS);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(zumbador, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {

  long t;   // Tiempo que demora en llegar el echo
  float d;   // Distancia

  // Enviar pulso de 1s0us
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  t = pulseIn(ECHO, HIGH);  // Obtenemos ancho de pulso
  // Velocidad del sonido tomada como 340 m/s = 0.034 cm/us
  d = t * 0.034 / 2;   // Distancia, divide entre dos por ida y regreso
  d = roundf(d * 10) / 10.0;  // Redondea 1 decimal
  lcd.clear();
  lcd.print("Distancia:");
  lcd.setCursor(0, 1);
  lcd.print(d); 
  lcd.print(" cm");

  /* Tono del zumbador usando notas musicales, mas cerca, mas agudo
   *  Cada nota indica 2 centímetros
   *  Son 15 notas, por lo que 15*2cm = 30cm, ruido empieza de 1 cm a 2cm
  */
  byte ruido = 30 - d;    // Indice del arreglo notas
  
  ruido /= 2;
  // Toca la nota adecuada, sonido por medio segundo
  if(ruido < 30)
    tone(zumbador, notas[ruido], 300);

  // Apaga todo LED
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  // Enciende distancia con 4 LEDs, cada uno con 7 cm
  if(d < 7)
    digitalWrite(LED1, HIGH);
  else if(d < 14)
    digitalWrite(LED2, HIGH);
  else if(d < 21)
    digitalWrite(LED3, HIGH);
  else if(d < 28)
    digitalWrite(LED4, HIGH);
      
  delay(350); // Delay para sonido y un tiempo de desfase
}
