// 2_LuzSonido
#include <LiquidCrystal.h>

// Establece filas y columnas de //lcd
#define LCD_ROWS 4
#define LCD_COLS 20

// Objeto LiquidCrystal (RS, E, D4, D5, D6, D7) son (D7, D6, D5, D4, D3, D2) respectivamente
LiquidCrystal lcd(5, 4, 3, 2, 1, 0);

// Actuadores AC
#define actu1 13
#define actu2 12

// LEDs de sonido
#define LED_LOW A1
#define LED_MED A2
#define LED_HIGH A3

// Sensores
#define luz A5
#define mic 6

void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.noCursor();
  pinMode(luz, INPUT);
  pinMode(mic, INPUT);
  pinMode(actu1, OUTPUT);
  pinMode(actu2, OUTPUT);
  pinMode(LED_LOW, OUTPUT);
  pinMode(LED_MED, OUTPUT);
  pinMode(LED_HIGH, OUTPUT);

  // Estado incial actuadores desactivados
  digitalWrite(actu1, LOW);
  digitalWrite(actu2, LOW);
}

// Cada 1000 iteraciones detona el nivel de sonido
#define ITERACIONES 500
int bufferSonido = 0;
int mil = 0;

int millisElapsed = 0;

void loop() {
  
  // Nivel de fotorresistencia
  int lightLevel = analogRead(luz);
    
  // Si valor de fotorresistencia mayor a 700 (MUY ILUMINADO) activa actuador1 
  if(lightLevel > 600)
    digitalWrite(actu1, 1);
  else
    digitalWrite(actu1, 0);

  // Si se detecta sonido, aumenta sonido
  if(digitalRead(mic))
    ++bufferSonido;
    
  if(mil == ITERACIONES){
    //Serial.println(bufferSonido);

    // NIVEL DE SONIDO SEGUN LED
    
    // PRIMERO APAGA TODOS LOS LEDS
    digitalWrite(LED_LOW, LOW);
    digitalWrite(LED_MED, LOW);
    digitalWrite(LED_HIGH, LOW);
     
    if(bufferSonido > 0)     // NIVEL DE SONIDO BAJO
        digitalWrite(LED_LOW, HIGH);
    if(bufferSonido > 70)    // NIVEL DE SONIDO MEDIO
        digitalWrite(LED_MED, HIGH);
    if(bufferSonido > 180){    // NIVEL DE SONIDO ALTO
        digitalWrite(LED_HIGH, HIGH);

        // Activa actuador 2
        digitalWrite(actu2, HIGH);

        // APaga todo led (excepto el de volumen alto)
        digitalWrite(LED_LOW, LOW);
        digitalWrite(LED_MED, LOW);
        
        // Imprime en pantalla mensaje de advertencia
        lcd.clear(); // Limpia lcd
        lcd.setCursor(4, 1);  //Posiciona en centro
        lcd.print("Party is OVER!");  
        delay(2000);  // Delay
        // Desctiva actuador 2
        digitalWrite(actu2, LOW);
    }

   
   // Imprime animación de sonido en pantalla
   int cols = bufferSonido / 9;
   // Sobre quince porque el ancho de la pantalla es 20 y el VOL MAX es 260, por lo que 260 / 20 = 13
   // Cursor en inicial
   lcd.setCursor(0, 0);
   // Imprime en pantalla en toda fila el ancho de sonido detectado
   // Los espacios que no se imprimen se limpia, para visualizar mejor la animación
   for(int i = 0; i < 4; ++i){
    for(int j = 0; j < cols; ++j){
        lcd.setCursor(j, i);        
        lcd.print((char)0xFF);             
    }
    // Limpia los espacios en blanco y establece forma de flecha
    int x = cols;  // x valor final de columna (cols) 
    // Forma de flecha (borra último caracter en primera y última fila)
    if(i == 0 || i == 3)
      --x; 
    while(x < 20){     
          lcd.setCursor(x, i);
          lcd.print(" ");
          ++x;
      }        
    }
       
    bufferSonido = 0;   // Reinicia conteo de sonido
    mil = 0;            // Reinicia iterador
   }
   ++mil;
}
