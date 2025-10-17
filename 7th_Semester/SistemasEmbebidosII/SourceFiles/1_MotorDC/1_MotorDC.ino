// 1_MotorDC

// Teclado 4x4
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// Base de transistor para motor en D10
#define P_MOTOR 10

// Estados del motor, acelera 1, uniforme 2 y mantiene 3
enum Estado {
  ACELERA = 1,
  UNIFORME,
  DESACELERA
};

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

void animacion(void);
void mensajeInicio(void);
byte pedirTiempo(const byte nTiempo);
void acelerarMotor(byte tiempo);
void mantenerMotor(byte tiempo);
void desaceleMotor(byte tiempo);
void imprimirEstado(byte, byte);

void setup() {
    
  // Incio LCD
  lcd.init();
  // Luz de fondo LCD
  lcd.backlight();
  // No mostrar cursor
  lcd.noCursor();

}

// Para selección de cada tecla
char k;
// Tiempos de motor (en decimas de segundos)
byte t_acelera, t_uniforme, t_desacelera;

void loop() {
  

  // Inicio con animacion
  lcd.noBlink();
  animacion();
  mensajeInicio();
  delay(500);
  animacion();
  lcd.blink();

  // Pido tiempos
  t_acelera = pedirTiempo(ACELERA);
  t_uniforme = pedirTiempo(UNIFORME);
  t_desacelera = pedirTiempo(DESACELERA);

  lcd.print("1: ");
  lcd.print(t_acelera);
  lcd.print(" 2: ");
  lcd.print(t_uniforme);
  lcd.print(" 3: ");
  lcd.print(t_desacelera);

  lcd.noBlink();
  acelerarMotor(t_acelera);
  mantenerMotor(t_uniforme);
  desaceleMotor(t_desacelera);
  // Delay
  delay(777);
  
}

// Animación de transición izq a derecha y clear
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
  lcd.clear();
}

void mensajeInicio(void) {
  
  lcd.setCursor(5, 0);
  lcd.print("CONTROLAR");
  lcd.setCursor(5, 1);
  lcd.print("VELOCIDAD");
  lcd.setCursor(8, 2);
  lcd.print("DE");
  lcd.setCursor(7, 3);
  lcd.print("MOTOR");
}

// Pide tiempo de aceleración número (nTiempo)
byte pedirTiempo(const byte nTiempo) {

  lcd.print("Introduce el tiempo");
  lcd.setCursor(0, 1);
  lcd.print("de ");
  
  if(nTiempo == ACELERA)
    lcd.print("aceleracion:");
  else if(nTiempo == UNIFORME)
    lcd.print("uniformidad:");
  else
    lcd.print("desaceleracion:");
  
  lcd.setCursor(0, 2);
  lcd.print("(=) para terminar");
  lcd.setCursor(0, 3);

  byte tiempo = 0;

  for(byte i = 0; i < 2; ++i) {
    
    // Hasta tecla presionada
    while( (k = kbd.getKey()) == '\0' );

    if('0' <= k && k <= '9') {
      
      // Para sumar unidades
      tiempo *= 10;
      // Convierte k a decimal y suma como unidad
      tiempo += k - '0';

      // Imprime tecla
      lcd.print(k);

    } else if('=' == k){
      // Rompe ciclo (intro)
      break;

    } else {
      // Opción inválida
      --i;
    }
    
  }
  delay(200);
  animacion();
  return tiempo;
}

/*
  Imprime porcentaje de carga al motor por PWM y el tiempo indicado
  Si porcentaje y tiempo es cero, deja espacio en blanco
*/
void imprimirEstado(byte porcentaje, byte tiempo){

    if(porcentaje ==0 && tiempo==0){
      lcd.setCursor(0, 1);
      // El nivel de porcentaje se imprime a partir de setCursor(7, 1);
      lcd.print("Nivel:     %");
      lcd.setCursor(0, 2);
      // El porcentaje se imprime a partir de setCursor(8, 2);
      lcd.print("Tiempo:    s");
    }else{
      // Imprime porcentaje
      lcd.setCursor(7, 1);
      lcd.print(porcentaje);
      lcd.print(" ");
      // Imprime Tiempo
      lcd.setCursor(8, 2);
      lcd.print(tiempo);
      lcd.print(" ");
    }
}

void acelerarMotor(byte tiempo){
  // Verifica que tiempo mayor a cero

  if(tiempo > 0){

    lcd.clear();
    lcd.print("Acelerando...");
    imprimirEstado(0, 0);

    // El factor de aceleracion para aumentar velocidad cada ciclo
    // De segundos a decimas de segundo:
    tiempo *= 10; 
    byte factor = 255 / tiempo;

    // Multiplica por 10 pues, hará retardos de 100ms por cada ciclo
    for(byte i = 1; i <= tiempo; ++i){

      // Escribe en pin a transistor
      analogWrite(P_MOTOR, i * factor);
      delay(100);
      imprimirEstado(i * 100 / tiempo, (i/10));
    }
  }
}
  // Mantener tiempo segundos
void mantenerMotor(byte tiempo) {
  if(tiempo > 0){
    lcd.setCursor(0, 0);
    lcd.print("Manteniendo...");
    imprimirEstado(100, 0);

    analogWrite(P_MOTOR, 255);

    for(int i = 1; i <= tiempo; ++i){
      imprimirEstado(100, i);
      delay(1000);
    }
  }  
}
void desaceleMotor(byte tiempo){
  // Verifica que tiempo mayor a cero
  if(tiempo > 0){

    lcd.setCursor(0, 0);
    lcd.print("Desacelerando...");
    imprimirEstado(0, 0);

    // El factor de aceleracion para aumentar velocidad cada ciclo
    // De segundos a decimas de segundo:
    tiempo *= 10; 
    byte factor = 255 / tiempo;

    // Multiplica por 10 pues, hará retardos de 100ms por cada ciclo
    for(byte i = tiempo; i > 0; --i){

      // Escribe en pin a transistor
      analogWrite(P_MOTOR, i * factor);
      delay(100);
      imprimirEstado(i * 100 / tiempo, ((tiempo - i + 1) / 10));
    }
  }
  analogWrite(P_MOTOR, 0);
}


