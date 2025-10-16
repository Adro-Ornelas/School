// 4_Interrupts

#include <LiquidCrystal.h>

#define LCD_ROWS 4
#define LCD_COLS 20

#define LED1 4    // (D4)
#define inter0 2  // Interrupcion 0 (D2)
#define inter1 3  // Interrupcion 1 (D3)

  // Objeto LiquidCrystal (RS, E, D4, D5, D6, D7) son (A0, A1, A2, A3, A4, A5) respectivamente
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

void setup() {

  lcd.begin(LCD_COLS, LCD_ROWS);            // LCD con 20 columnas, 4 filas
  pinMode(LED1, OUTPUT);                    // Pin a LED de salida
  
  // Pines 3 y 2 Para activar interrupciones con solo un boton y resistencia a tierra
  pinMode(inter0, INPUT_PULLUP);                 
  pinMode(inter1, INPUT_PULLUP);                 

  // Interrupcion A con el Timer1: LED cada 10 seg
  
  TCCR1A = 0;       // Modo normal, desconectado de OC1A
  TCCR1B = 0;
  TCCR1B |= (1 << CS10)|(1 << CS12);  // Modo CTC Presc de 1024
  // Timer inicia en cero
  TCNT1 = 0;        
  OCR1A = 62500;  // (62500 * 1024)/(16Mhz) = 4 s
  TIMSK1 |= (1 << OCIE1A); // Activa interrupcion overflow

  // Interrupción B con INT0: Muestra nombre en LCD 
  attachInterrupt(digitalPinToInterrupt(inter0), intExt0, FALLING); // Activar en BAJADA
  
  // Interrupción B con INT0: Muestra salido e LCD 
  attachInterrupt(digitalPinToInterrupt(inter1), intExt1, RISING); // Activar en SUBIDA
}

void loop() {
  // Numeros del 0 - 99 en display

  lcd.clear();
  
  byte i = 0;
  byte tmp = 0;
  
  while(i < 100){
    
    // Manejar saltos de linea y nuevas pantallas cuando la actual se llena
    if((tmp % 5) == 0) {
      if(tmp == 20){
        tmp = 0;
        lcd.clear();
      } else {
        lcd.setCursor(0, tmp / 5);
      }
    }
    ++tmp;
    lcd.print(i++);  // Imprime e incrementa
    lcd.print(", ");        
    delay(500); // Delay de visualizacion
  }
}


ISR(TIMER1_COMPA_vect){
  
  TCNT1 = 0;          // Reinicia contador
  digitalWrite(LED1, !digitalRead(LED1));  // Toggle LED
 
}

void intExt0(){
    lcd.setCursor(4, 1);
    lcd.print("Adro Ornelas");
}

void intExt1(){
    lcd.setCursor(1, 2);
    lcd.print("SALUDOS CORDIALES");
}
