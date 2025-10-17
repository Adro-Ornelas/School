// 3_Servomotor 

// Para servo
#include <PWMServo.h>

// Teclado 4x4
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// Base de transistor para motor en D10
#define P_SERVO 10

// Para LCD
const byte lcdrows = 4;
const byte lcdcols = 20;

// Para teclado (pines 2 - 9)
const byte nrows = 4;
const byte ncols = 4;
const byte rows[nrows] = {2, 3, 4, 5};
const byte cols[ncols] = {6, 7, 8, 9};
char keys[nrows][ncols] = 
{ {'1', '2', '3', 'C'},
  {'4', '5', '6', '+'},
  {'7', '8', '9', '-'},
  {'*', '0', '/', '='}};

// VARIABLES-------------------------------------------------

// Objeto Keypad
Keypad kbd = Keypad(makeKeymap(keys), rows, cols, nrows, ncols);

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, lcdrows, lcdcols);  

PWMServo servo;

void animacion(void);
void mensajeInicio(void);
byte leerAngulos(byte*, byte);
void escribirAngulos(byte*, byte);

// Para leer teclado
char k;

void setup() {

  // Incio LCD
  lcd.init();
  // Luz de fondo LCD
  lcd.backlight();
  // No mostrar cursor
  lcd.noCursor();
  
  servo.attach(P_SERVO); // Inicia servo en pin 10
  // Servo a cero grados
  servo.write(0);
  
}

void loop() {
  

  byte angulos[9];
  byte cuantos;

  // Inicio con animación
  animacion();
  mensajeInicio();
  delay(500);
  animacion();

  lcd.print("Ingresa 1-9 angulos,");
  lcd.setCursor(0, 1);
  lcd.print("(=) para siguiente,");
  lcd.setCursor(0, 2);
  lcd.print("(*) para finalizar:");
  lcd.setCursor(0, 3);

  lcd.blink();
  
  cuantos = leerAngulos(angulos);
  escribirAngulos(angulos, cuantos);

}

void animacion(void){

  // Que no parpadee el cursor
  lcd.noBlink();

  for(byte i = 0; i < lcdcols; ++i){
    for(byte j = 0; j < lcdrows; ++j) {
      lcd.setCursor(i, j);
      lcd.print((char)0xFF);
    }
    delay(7);
  }
  for(byte i = 0; i < lcdcols; ++i){
    for(byte j = 0; j < lcdrows; ++j) {
      lcd.setCursor(i, j);
      lcd.print(" ");
    }
    delay(6);
  }
  lcd.setCursor(0, 0);
  // Que parpadee el cursor
  lcd.blink();
}

void mensajeInicio(void) {
  
  lcd.setCursor(5, 0);
  lcd.print("CONTROLAR");
  lcd.setCursor(4, 1);
  lcd.print("SERVOMOTOR");
  lcd.setCursor(8, 2);
  lcd.print("CON");
  lcd.setCursor(6, 3);
  lcd.print("ANGULOS");
}
// Lee angulos y retorna cuantos hubo
byte leerAngulos(byte* angulos){
  
  byte cuantos = 0;
  
  // Valor por defecto, inválido, debe ser 0-180
  byte ang = 255;  

  // Mientras halla menos de 10 ángulos
  do {

    // Hasta obtener tecla
    while((k = kbd.getKey()) == '\0');
    
    // Si hay al menos uno, puede terminar
    if(k == '*' && cuantos > 0) {

      return cuantos;

    } else if(k == '=' && ang <= 180) { // Si va por siguiente y hay angulo guardado

      // Guarda actual y va por siguiente
      angulos[cuantos++] = ang;

      // Reinicio angulo
      ang = 0;

      // Escribe cuantos llevo y vacia espacio
      lcd.setCursor(19, 3);
      lcd.print(cuantos);
      lcd.setCursor(0, 3);
      lcd.print("    ");
      lcd.setCursor(0, 3);

    } else if('0' <= k && k <= '9' && ang <= 180){

      // Para sumar unidades
      ang *= 10;

      // Imrpimo
      lcd.print(k);

      // Sumo
      ang += (k - '0');
      
    } else {  // Si nada de lo anterior se cumple, el usuario realizó acción inválida


      ang = 0;
      lcd.setCursor(0, 3);
      lcd.print("Opcion invalida");
      delay(1000);
      lcd.setCursor(0, 3);
      for(byte i = 0; i < 15; ++i)
        lcd.print(" ");
      lcd.setCursor(0, 3);
    }

  } while(cuantos < 9);
  
  // Si el programa llegó a aquí el array está lleno
  return cuantos;
}

void escribirAngulos(byte* angulos, byte cuantos) {

  // Para cada ángulo
  for(byte i = 0; i < cuantos; ++i) {

    // Notifica al usuario de la operación
    animacion();
    lcd.print("Angulo ");
    lcd.print(i + 1);
    lcd.print(": ");
    lcd.print(angulos[i]);
    lcd.print(" ");
    lcd.print((char)0xDF);


    // Mueve motor a ángulo
    servo.write(angulos[i]);

    // Espera
    delay(2000);

  }
}