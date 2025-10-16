// 3_Color.ino

#include <LiquidCrystal.h>
// Establece filas y columnas de LCD
#define LCD_ROWS 4
#define LCD_COLS 20

// Objeto LiquidCrystal (RS, E, D4, D5, D6, D7) son (D7, D6, D5, D4, D3, D2) respectivamente
LiquidCrystal lcd(5, 4, 3, 2, 1, 0);

#define S3 9
#define S2 8
#define OUT 7
#define LED_RED A3
#define LED_GREEN A1
#define LED_BLUE A4
#define LED_WHITE A2

void setup() {
  
  lcd.begin(LCD_COLS, LCD_ROWS);  // Incia pantalla LCD
  
  pinMode(S3, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(OUT, INPUT);  

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);
}

void loop() {
  int red, green, blue;
  
  // Mide con filtro rojo:
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red = pulseIn(OUT, LOW);  // Mide el pulso bajo
  delay(200); // Estabiliza sensor
  
  // Mide con filtro verde:
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  green = pulseIn(OUT, LOW);  // Mide el pulso bajo
  delay(200); // Estabiliza sensor
  
  // Mide con filtro azul:
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blue = pulseIn(OUT, LOW);  // Mide el pulso bajo
  delay(200); // Estabiliza sensor

  lcd.clear();
  lcd.print("R: ");
  lcd.print(red);
  lcd.setCursor(0, 1);
  lcd.print("G: ");
  lcd.print(green);
  lcd.setCursor(0, 2);
  lcd.print("B: ");
  lcd.print(blue);

  // Asigna cursor
  lcd.setCursor(0, 3);

  // Apaga todo LED
    digitalWrite(LED_WHITE, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
    
  if(red < 70 && green < 100 && blue < 100){  // COLOR BLANCO
    lcd.print("Blanco");
    digitalWrite(LED_WHITE, HIGH);
  } else if(red < 140 && green < 110 && blue < 160){ // COLOR VERDE
    lcd.print("Verde");
    digitalWrite(LED_GREEN, HIGH);
  } else if(red > 145 && green > 130 && blue < 130){  // COLOR AZUL
    lcd.print("Azul");
    digitalWrite(LED_BLUE, HIGH);
  } else if(red < 80 && green > 145 && blue > 120){ // COLOR ROJO
    lcd.print("Rojo");
    digitalWrite(LED_RED, HIGH);
  } else if(red > 170 && green > 200 && blue > 170){ // COLOR NEGRO
    lcd.print("Negro");
  } else {    // Sin color
    lcd.print("");
  }
}
