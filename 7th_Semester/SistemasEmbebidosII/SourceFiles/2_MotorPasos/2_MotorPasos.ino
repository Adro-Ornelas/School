// 2_MotorPasos.ino


// Teclado 4x4
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

#define unoMas(I) ((I+1)%4)
#define unoMenos(I) ((4+I-1)%4)

enum PASOS {
  COMPLETOS = 0,
  MEDIOS = 1,
  JOYSTICK = 2
};

enum SENTIDO {
  HORARIO = 0,
  ANTIHORARIO = 1
};

// Pines de pasos (IN1, IN2, IN3, IN4) respectivamente
const byte pasosPIN[4] = {10, 11, 12, 13};
// Tiempo para procesar cada paso
const byte period = 5; // 10 ms

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

// Objeto Keypad
Keypad kbd = Keypad(makeKeymap(keys), rows, cols, nrows, ncols);

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, lcdrows, lcdcols);  

// Prototipos de funciones
void mensajeInicio(void);
void animacion(void);
void vueltaHoraria(enum PASOS);
void vueltaAntihoraria(enum PASOS);
byte pedirModo(void);
byte pedirSentido(void);

void setup() {

  // Start LCD
  lcd.init();

  // Backlight
  lcd.backlight();

  // Que no parpadee cursor
  lcd.noBlink();

  // Todo pin es de salida
  for(int i = 0; i < 4; ++i)
    pinMode(pasosPIN[i], OUTPUT);

  // Todos inician en BAJO
  for(int i = 0; i < 4; ++i)
    digitalWrite(pasosPIN[i], LOW);

}

void loop() {

  animacion();
  mensajeInicio();
  delay(500);
  animacion();

  lcd.blink();
  
  enum PASOS pasos = (enum PASOS)pedirModo();
  
  animacion();

  if(pasos == JOYSTICK) {

    //lcd.print("Modo joystick");

  } else {

    if(pasos == COMPLETOS)
      lcd.print("Pasos completos");
    else if (pasos == MEDIOS)
      lcd.print("Pasos medios");

    enum SENTIDO sentido = (enum SENTIDO)pedirSentido();

    if(sentido == HORARIO)
      vueltaHoraria(pasos);
    else if(sentido == ANTIHORARIO)
      vueltaAntihoraria(pasos);
  }
  
  // delay(500);

}


void mensajeInicio(void) {
  
  lcd.setCursor(5, 0);
  lcd.print("CONTROLAR");
  lcd.setCursor(7, 1);
  lcd.print("MOTOR");
  lcd.setCursor(9, 2);
  lcd.print("A");
  lcd.setCursor(7, 3);
  lcd.print("PASOS");
}


void animacion(void){

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
}

byte pedirModo(void) {

  char k;
  lcd.setCursor(0, 0);
  lcd.print("Selecciona: ");
  lcd.setCursor(0, 1);
  lcd.print("1 - Pasos completos");
  lcd.setCursor(0, 2);
  lcd.print("2 - Medios pasos");
  lcd.setCursor(0, 3);
  //lcd.print("3 - Modo joystick");
  lcd.setCursor(12, 0);

  // Hasta obtener una selección válida
  
  while( ((k = kbd.getKey()) == '\0') || ('1' > k || k > '3'));
  
  // Muestra opción seleccionada y espera
  lcd.print(k);
  delay(1000);

  // Como la opción 1 es la cero, resto '1'
  return (k - '1');
}


void vueltaHoraria(enum PASOS pasos) {
  
  if(pasos == COMPLETOS){

    // Vuelta en sentido horario
    for(int i = 0; i < 512; ++i) {    // 512 ciclos, pues 5.625 * 4 / 32 = 512
      // Cada paso:
      for(int j = 0; j < 4; ++j){
        digitalWrite(pasosPIN[j] , HIGH);
        delay(period);
        digitalWrite(pasosPIN[j], LOW);    
        delay(period);
      }
    }

  } else {  // Medios Pasos

    for(int h = 0; h < 512; ++h) {
      //Cada ciclo:
      for(int i = 0; i < 4; ++i) {
        // Cada dos pasos:
        digitalWrite(pasosPIN[i], HIGH);
        delay(period);
        digitalWrite(pasosPIN[unoMas(i)], HIGH);
        delay(period);
        digitalWrite(pasosPIN[i], LOW);
      }      
    }
    // Quedo prendido A, se apaga
    digitalWrite(pasosPIN[0], LOW);

  }

  delay(1000);    // delay de espera

  // Al final pongo todo en BAJO
  for(int j = 0; j < 4; ++j)
    digitalWrite(pasosPIN[j], LOW);
}
void vueltaAntihoraria(enum PASOS pasos) {

  if(pasos == COMPLETOS){

    // Vuelta en sentido antihorario
    for(int i = 0; i < 512; ++i) { // 512 ciclos, pues 5.625 * 4 / 32 = 512
      // Cada paso:
      for(int j = 3; j >= 0; --j){
        digitalWrite(pasosPIN[j], HIGH);
        delay(period);
        digitalWrite(pasosPIN[j], LOW);    
        delay(period);
      }
    }

  } else {  // Medios Pasos

    for(int h = 0; h < 512; ++h) {
      //Cada ciclo:
      for(int i = 3; i >= 0; --i) {
        // Cada dos pasos:
        digitalWrite(pasosPIN[i], HIGH);
        delay(period);
        digitalWrite(pasosPIN[unoMenos(i)], HIGH);
        delay(period);
        digitalWrite(pasosPIN[i], LOW);
      }      
    }
    // Quedo prendido D, se apaga
    digitalWrite(pasosPIN[3], LOW);

  }

  delay(1000);    // delay de espera

  // Al final pongo todo en BAJO
  for(int j = 0; j < 4; ++j)
    digitalWrite(pasosPIN[j], LOW);

}

byte pedirSentido(void) {
 
  char k;
  lcd.setCursor(0, 1);
  lcd.print("Selecciona: ");
  lcd.setCursor(0, 2);
  lcd.print("1 - S. Horario");
  lcd.setCursor(0, 3);
  lcd.print("2 - S. Antihorario");
  lcd.setCursor(12, 1);

  // Hasta obtener una selección válida
  
  while( ((k = kbd.getKey()) == '\0') || ('1' > k || k > '2'));
  
  // Muestra opción seleccionada y espera
  lcd.print(k);
  delay(1000);

  // Como la opción 1 es la cero, resto '1'
  return (k - '1'); 
}