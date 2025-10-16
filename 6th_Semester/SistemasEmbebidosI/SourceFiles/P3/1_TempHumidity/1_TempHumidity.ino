// Sensor de velocidad (RPM)
#include <DHT.h>
#include <LiquidCrystal.h>


#define DHTPIN 8 // Sensor a pin D8
#define DHTTYPE DHT11
#define indica 13  // Indicador en D3

// Objeto sensor de temperatura y humedad (DHT11)
DHT dht(DHTPIN, DHTTYPE);

// Establece filas y columnas de LCD
#define LCD_ROWS 4
#define LCD_COLS 20

// Objeto LiquidCrystal (RS, E, D4, D5, D6, D7) son (D7, D6, D5, D4, D3, D2) respectivamente
LiquidCrystal lcd(5, 4, 3, 2, 1, 0);

void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS);    // Inicia LCD
  // Inicia DHT11
  dht.begin();
  pinMode(indica, OUTPUT);
}

void loop() {
  delay(1000);  // Delay 1 segundo

  
  float temp = dht.readTemperature(); // Lee tem en celcius
  float humd = dht.readHumidity();

  
  lcd.clear();  // Limpia lcd
  
  lcd.print("HUMEDAD: ");
  lcd.setCursor(0, 1);
  lcd.print(humd);
  lcd.print(" %");
  lcd.setCursor(0, 2);
  lcd.print("TEMPERATURA (C): ");
  lcd.setCursor(0, 3);
  lcd.print(temp);
  lcd.print("  C");

  
  if(isnan(temp) || isnan(humd)){
    lcd.clear();
    lcd.print("Error en el sensor");
  }

  // Si temperatura sobrepasa los 35 C enciende
  if(temp > 31)
    digitalWrite(indica, HIGH);
   else
    digitalWrite(indica, LOW);
}
