// Integrador.ino

#include <Keypad.h>
// Para configurar I2C con PCF8574 como extensor de 8 terminales digitales:
#include <PCF8574.h>
//#include <Wire.h>
// Para LCD con I2C
#include <LiquidCrystal_I2C.h>
#include <PWMServo.h>
//#include <Servo.h>

// Para teclado
const byte nrows = 4;
const byte ncols = 4;
const byte rows[nrows] = {9, 8, 7, 6};
const byte cols[ncols] = {5, 4, 3, 2};
char keys[nrows][ncols] = 
{ {'1', '2', '3', 'C'},
  {'4', '5', '6', '+'},
  {'7', '8', '9', '-'},
  {'*', '0', '/', '='}};

//Objeto servo
PWMServo servo;

// Objeto Keypad
//Keypad kbd = Keypad(makeKeymap(keys), rows, cols, nrows, ncols);
 
// HEX address
PCF8574 pcf8574(0x20);
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// Terminales
#define t_IRVaso A3  // Sensor IR
#define t_ColorEN A0
#define t_ColorS3 11
#define t_ColorS2 12
#define t_ColorOUT 13

#define t_Sab1 3 
#define t_Sab2 4
#define t_foco 5
// Terminales de PCF8574
/*
  P0 - Bomba1
  P1 - Bomba2
  P2 - Hielo
  P3 - Foco1
  P4 - Foco2
  P5 - Ventilador
  P6
  P7


*/

// Dirección de PCF8564
#define PCF_ADDR = 0x20;

// VARIABLES GLOBALES
// (Flag) usado en el T1 para servir por 4 segundos mientras el vaso se detecta
volatile bool sirviendo1 = false;
volatile int cuatroT2;   
byte rgb[3];    // Utilizadas por el sensor de coor mediante la función getColors()

void setup() {

  // Definición de terminales
  pinMode(t_IRVaso, INPUT);
  pinMode(t_ColorEN, OUTPUT);
  pinMode(t_ColorS3, OUTPUT);
  pinMode(t_ColorS2, OUTPUT);
  pinMode(t_ColorOUT, INPUT);
  pinMode(t_Sab1, OUTPUT);
  pinMode(t_Sab2, OUTPUT);  
  pinMode(t_foco, OUTPUT);
  
  digitalWrite(t_Sab1, 1);
  digitalWrite(t_Sab2, 1);
  digitalWrite(t_foco, 0);

  lcd.init();         // Inicializa LCD
  lcd.backlight();    // Enciende LED de LCD
  
  lcd.print("Automatic mode");
  lcd.setCursor(0, 1);
  lcd.print("Blanco - Hielos");
  lcd.setCursor(0, 2);
  lcd.print("Verde - Sabor 1");
  lcd.setCursor(0, 3);
  lcd.print("Naranja - Sabor 2");
  

  servo.attach(10); // Inicia servo en pin 10
  servo.write(0); // Regresa servo a posición inicial
  // Terminales de PCF8574
  pcf8574.begin(0);  // Iniciar en ceros

  // SI no está conectada la extensión
  if(!pcf8574.isConnected()){
   // lcd.print("NOT 8574");
    //while(1);
  } 

  // ESTADO INICIAL DE TERMINALES
  // Todo 8574 inicia en cero
  //pcf8574.write8(0, 1);



  // Timer 2 para contar 4 segundos de llenado de vaso mientras el vaso se detecta
  TCCR2A = 0;
  TCCR2B = 0; // Timer 1 desactivado inicialmente
  // TCCR1B |= (1 << CS10) | (1 << CS12);  // Preescalador 1024 ()
  
  TIMSK2 |= (1 << TOIE2);   // Interrupcion por comparación
  // Contará 244 interrupciones del timer 2; 4* (256 * 1024 / 16Mhz) = 3.997 s


  Serial.begin(9600);

    // Desactiva bombas: (RELE ACTIVA CON CERO)
  pcf8574.write(0, 1);
  pcf8574.write(1, 1);
  
  // Deshabilita sensor de color
  digitalWrite(t_ColorEN, 0);
  digitalWrite(t_ColorS3, 1);
  digitalWrite(t_ColorS2, 1);
  
  Serial.println("Bienvenido!");
  Serial.println("Presiona 1 para servir un hielo");
}

void loop() {
  //lcd.setCursor(0, 1);
  //lcd.print("Manual (Teclado)");
/*
  getColors();
  for(int i=0; i < 3; ++i){
    Serial.print(rgb[i]);
    //lcd.setCursor(0, i);
    Serial.print("\t");
  }
  Serial.println("");
*/
/*  TECLADO
char k;
  lcd.cursor();
  while((k = kbd.getKey()) == '\0');  // Hasta obtener seleccion
  lcd.print(k); // Imprime seleccion
  lcd.noCursor();
*/
  
  if(Serial.available() > 0){

    char c = Serial.read();
    if(c == '1')
      servirHielo();
    Serial.println("Hielo servido");
  }


  int objeto = analogRead(t_IRVaso);  // Revisa si hay vaso (menor de 400)
  //Serial.println(objeto);
  
  if(objeto <= 400){     // Vref de 1.6617 V1
    // Si se detecta vaso
    lcd.clear();
    lcd.print("Sirviendo.");
    
    // AQUI VA LA ELECCION DE SABOR // Activa bomba o motor según color
    getColors();

     for(int i = 0; i < 3; ++i){
        Serial.print(rgb[i]);
        Serial.print("\t");
    }

    Serial.println("");

    bool hielo = false;
    if(rgb[0] < 70 && rgb[1] < 35 && rgb[2] < 45){  // Blanco hielos
      lcd.print("Blanco Servo");
      servirHielo();
      hielo = true;
      
      delay(200);
      //pcf8574.write(2, 0);
    } else if(rgb[0] > 70 && rgb[1] < 75 && rgb[2] > 40){

      lcd.print("Verde");   // Bebida 1
      Serial.println("Sirviendo verde");
      pcf8574.write(0, 0);
      digitalWrite(t_Sab1, 0);
    
    } else //if(rgb[0] < 20 && rgb[1] > 50 && rgb[2] > 50){
  {
      lcd.print("Naranja"); // Bebida 2
      Serial.println("Sirviendo naranja");
      pcf8574.write(1, 0);
      digitalWrite(t_Sab2, 0);
    }

    digitalWrite(t_foco, 1);
    delay(1000);
    // Si no es hielo, sirve
    if(!hielo){
      // Empieza a servir
      sirviendo1 = true;
      // Mientras el vaso se detecte y el timer no haya finalizado
      // Si alguna de las dos no se cumple, termina
      // Inicia T2 (casi 4 seg)
      TCCR2B |= (1 << CS20) | (1 << CS22);  // Preescalador 1024
      TCNT2 = 0;
      cuatroT2 = 0;
      
      while(objeto <= 400 && sirviendo1 == true) {
        // Revisa el vaso
        objeto = analogRead(t_IRVaso);
        //Serial.println(objeto);
      }
      // Apaga toda bomba y motor a posición original
      pcf8574.write(0, 1);
      pcf8574.write(1, 1);
      pcf8574.write(2, 1);
      digitalWrite(t_Sab1, 1);
      digitalWrite(t_Sab2, 1);
      // Desactivar T2
      TCCR2B = 0;
    }
    // Da oportunidad a quitar el vaso
    
    digitalWrite(t_foco, 0);
    lcd.clear();
    lcd.setCursor(3, 1);
    lcd.print("Remover vaso");
    lcd.setCursor(3, 2);
    lcd.print("para continuar");
    
    
    do{
      objeto = analogRead(t_IRVaso);
    }while(objeto <= 400); // NO continua hasta quitar vaso
    lcd.clear();
    lcd.print("Automatic mode");
    lcd.setCursor(0, 1);
    lcd.print("Blanco - Hielos");
    lcd.setCursor(0, 2);
    lcd.print("Verde - Sabor 1");
    lcd.setCursor(0, 3);
    lcd.print("Naranja - Sabor 2");
  }
}

// Timer 2 cada 4 segundos
ISR(TIMER2_OVF_vect) {
  // Reinicia flag para terminar de servir
  cuatroT2++;
  if(cuatroT2 > 300){
    sirviendo1 = false;
    // DEsactiva timer
    TCCR2B = 0;
  }
  TCNT2 = 0;
}

void getColors(){ // Sobreescribe las variables red, green y blue

  // Habilita sensor
  digitalWrite(t_ColorEN, 1);
  
  // Mide con filtro rojo:
  digitalWrite(t_ColorS2, 0);
  digitalWrite(t_ColorS3, 0);
  rgb[0] = pulseIn(t_ColorOUT, 0);  // Mide el pulso bajo
  delay(200); // Estabiliza sensor
  
  // Mide con filtro verde:
  digitalWrite(t_ColorS2, 1);
  digitalWrite(t_ColorS3, 1);
  rgb[1] = pulseIn(t_ColorOUT, 0);  // Mide el pulso bajo
  delay(200); // Estabiliza sensor
  
  // Mide con filtro azul:
  digitalWrite(t_ColorS2, 0);
  digitalWrite(t_ColorS3, 1);
  rgb[2] = pulseIn(t_ColorOUT, 0);  // Mide el pulso bajo
  delay(200); // Estabiliza sensor
  
  // Deshabilita sensor de color
  digitalWrite(t_ColorEN, 0);
  digitalWrite(t_ColorS3, 1);
  digitalWrite(t_ColorS2, 1);
}

void servirHielo(){
  for(int i = 0; i < 90; ++i){
    servo.write(i);
    delay(15);
  }
  servo.write(0);
}