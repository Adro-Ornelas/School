// 4_PuenteHRele

// Teclado 4x4
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// Base de transistor para motor en D10 (PWM)
#define P_MOTOR 10
// Pin a relé (se activa con cero lógico, LOW)
#define P_RELAY 11

// Estados del motor
enum SENTIDO {
  HORARIO = 0,
  ANTIHORARIO = 1,
  JOYSTICK
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
byte pedirSentido(void);
byte pedirPotencia(void);
void girarMotor(enum SENTIDO, byte);
void girarJoystick();

void setup() {

  // Pin a relé como salida  
  pinMode(P_RELAY, OUTPUT);
  pinMode(A0, INPUT);
  // Relay empieza activado (se activa con LOW)
  // En sentido horario
  digitalWrite(P_RELAY, LOW);

  // Incio LCD
  lcd.init();
  // Luz de fondo LCD
  lcd.backlight();
  // No mostrar cursor
  lcd.noCursor();

}

void loop() {


  // Inicio con animacion
  lcd.noBlink();
  animacion();
  mensajeInicio();
  delay(900);
  animacion();
  lcd.blink();

  // Obtiene sentido horairo o antiorario o si se usará joystick
  enum SENTIDO sentido = (enum SENTIDO)pedirSentido();
  animacion();

  if(sentido == JOYSTICK) {

    lcd.print("MODO JOYSTICK");
    lcd.setCursor(0, 1);
    lcd.print("Potencia: ");

    // TDP
    int lect;
    byte pot;

    while(1) {
      
      // Realiza 10 lecturas
      for(int i = 0; i < 10; ++i)
        lect += analogRead(A0);
      lect /= 10; // Consigue promedio de 10

      // Limpia campo de potencia
      lcd.setCursor(11, 1);
      lcd.print("       ");
      lcd.setCursor(11, 1);
      //lcd.print(lect);

      if(lect > 820) {  // Giro horario

        digitalWrite(P_RELAY, LOW);

        pot = map(lect, 1070, 800, 255, 100);
        analogWrite(P_MOTOR, pot);        
        lcd.print(pot * 100 / 255);
        

      } else if (lect < 600) {  // Giro antihorario

        digitalWrite(P_RELAY, HIGH);

        pot = map(lect, 600, 490, 100, 255);
        analogWrite(P_MOTOR, pot);        
        lcd.print(pot * 100 / 255);

      } else {  // No giro

        lcd.print("No move");
        digitalWrite(P_RELAY, HIGH);
        digitalWrite(P_MOTOR, LOW);
      }

      delay(30);
    }

  } else {

    // Imprime el sentido de giro
    lcd.print("Sentido ");
    if(sentido == ANTIHORARIO)
      lcd.print("anti");
    lcd.print("horario");

    // Pide potencia
    byte potencia = pedirPotencia();
    animacion();

    // Gira el motor por 5 segundos
    girarMotor(sentido, potencia);
  }
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
  lcd.setCursor(0, 0);
}
void mensajeInicio(void) {
  
  lcd.setCursor(5, 0);
  lcd.print("CONTROLAR");
  lcd.setCursor(5, 1);
  lcd.print("VELOCIDAD");
  lcd.setCursor(5, 2);
  lcd.print("Y SENTIDO");
  lcd.setCursor(5, 3);
  lcd.print("DE MOTOR");

}
byte pedirPotencia(void) {
  
  byte potencia;
  char k;
  lcd.setCursor(0, 0);
  lcd.print("Define la potencia");
  lcd.setCursor(0, 1);
  lcd.print("( 0 - 100 ) %");
  lcd.setCursor(0, 2);
  lcd.print("(=) para terminar:");
  
  do {
    // Limpia campo por si viene de una ejecución inválida
    potencia = 0;
    lcd.setCursor(0, 3);
    lcd.print("     ");
    lcd.setCursor(0, 3);
    // Máximo 3 dígitos
    for(byte i = 0; i < 3; ++i) {

      // Hasta obtener una selección
      while( ((k = kbd.getKey()) == '\0') );
      // Si es un número
      if('0' <= k && k <='9') {

        // Para sumar unidades
        potencia *= 10;
        // Suma valor seleccionado
        potencia += k - '0';
        lcd.print(k);

      } else if ('=' == k){
        // Termina ciclo
        break;

      } else {
        // Opción inválida
        i = 0;
      }
    }
  } while(potencia > 100); // Valida que sea una potencia 0-100
  
  // Delay para visualizar
  delay(100);

  return potencia;
}

byte pedirSentido(void) {
  char k;
  lcd.setCursor(0, 0);
  lcd.print("Selecciona: ");
  lcd.setCursor(0, 1);
  lcd.print("1 - S. Horario");
  lcd.setCursor(0, 2);
  lcd.print("2 - S. Antihorario");
  lcd.setCursor(0, 3);
  lcd.print("3 - Modo Joystick");
  lcd.setCursor(12, 0);

  // Hasta obtener una selección válida
  
  while( ((k = kbd.getKey()) == '\0') || ('1' > k || k > '3'));
  
  // Muestra opción seleccionada y espera
  lcd.print(k);
  delay(100);

  // Como la opción 1 es la cero, resto '1'
  return (k - '1'); 
}

// Mueve el motor en el sentido seleccionado a la potencia
void girarMotor(enum SENTIDO sentido, byte potencia) {

  // Imprime acció
  lcd.print("Sentido  ");
  if(sentido == ANTIHORARIO)
    lcd.print("anti");
  lcd.print("horario");
  lcd.setCursor(0, 2);
  lcd.print("Potencia: ");
  lcd.print(potencia);
  lcd.print(" %");

  // El relay se encuentra activado en BAJO (sentido horario)
  if(sentido == ANTIHORARIO)
    digitalWrite(P_RELAY, HIGH);
  else
    digitalWrite(P_RELAY, LOW);
  
  /*
    Gira el motor por 5 segundos
    Potencia es un valor entre 0-100, regla de tres para ser 0-255
  */
  analogWrite(P_MOTOR, (potencia * 255 / 100));
  delay(5000);
  // Desactiva motor
  digitalWrite(P_MOTOR, LOW);
}
void girarJoystick();