  #include <Keypad.h>
  #include <LiquidCrystal.h>
  
  #define LCD_ROWS 4
  #define LCD_COLS 20
  
  // Para teclado (Pines 2 - 9)
  const byte nrows = 4;
  const byte ncols = 4;
  const byte rows[nrows] = {9, 8, 7, 6};
  const byte cols[ncols] = {5, 4, 3, 2};
  char keys[nrows][ncols] = 
  { {'1', '2', '3', 'C'},
    {'4', '5', '6', '+'},
    {'7', '8', '9', '-'},
    {'*', '0', '/', '='}};
  
  // Objeto Keypad
  Keypad kbd = Keypad(makeKeymap(keys), rows, cols, nrows, ncols);
  
  // Objeto LiquidCrystal (RS, E, D4, D5, D6, D7) son (A0, A1, A2, A3, A4, A5) respectivamente
  LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
  
  void animacion(int = 20);   // Animacion con retardo default de 20 ms
  
  void setup() {
  
    lcd.begin(LCD_COLS, LCD_ROWS);           // 20 columnas, 4 filas
    animacion();    
  }
  
  void loop() {
  
    char k;
  
    // Imprime menu de opciones:
    lcd.setCursor(0, 0);
    lcd.print("1-Caminata 2-Media 3");
    lcd.setCursor(0, 1);
    lcd.print("3-Mayor 3  4-H a IaJ");
    lcd.setCursor(0, 2);
    lcd.print("5-Menor 3  6-Hipoten");
    lcd.setCursor(0, 3);
    lcd.print("Seleccion: ");
    lcd.blink();    // Activa parapedo de cursor
    while((k = kbd.getKey()) == '\0');  // Hasta obtener seleccion
    lcd.print(k); // Imprime seleccion
    
    delay(300);   // Tiempo para visualizar
    
    animacion();  // Animacion de tansicion
    lcd.clear();
    
    float valFloat = 0;   // Para caso 2 (promedio) y caso 6 (ecuacion)
    byte valores[3];      // Para caso 3 (mayor), 5(menor) y 4 donde se necesitan tres valores
    byte tmp;
    switch(k) {
      case '1':
        // Caminata      
        lcd.noBlink();    // Desactivar parpadeo
        // Corrimiento a la derecha
        for(byte i = 0; i < LCD_COLS; ++i) {
          for(byte j = 1; j < 3; ++j) {
            lcd.setCursor(i, j);
            lcd.print((char)0x7E);
          }
          delay(100);
        }
        lcd.clear();
        // Corrimiento a la izquierda
        for(byte i = LCD_COLS - 1; i > 0; --i) {
          for(byte j = 1; j < 3; ++j) {
            lcd.setCursor(i, j);
            lcd.print((char)0x7F);
          }
          delay(100);
        }
        lcd.clear();
        lcd.blink();
      break;
      case '2':
        // Media de tres

        // Suma tres valores de dos digitos a una variable flotante (valFloat)
        for(byte i = 0; i < 3; ++i){
            lcd.setCursor(0, i);
            lcd.print("Ingresa valor ");
            lcd.print(i+1);
            lcd.print(":");        
            valFloat += (float)getTwoDigits();  
        }
        valFloat /= 3;  // Calula promedio
        
        lcd.setCursor(0, 3);
        lcd.print("Resultado ");
        lcd.print(valFloat);
        
      break;
      case '3':
        // Mayor de 3
        // Obtiene 3 valores de dos dígitos, guarda en arreglo valores
        for(byte i = 0; i < 3; ++i){
          lcd.setCursor(0, i);
          lcd.print("Ingresa valor ");
          lcd.print(i+1);
          lcd.print(":");        
          valores[i] = getTwoDigits();  
        }
        // Encuentra mayor, guarda en tmp
        tmp = valores[0];
        if(valores[1] > tmp)
          tmp = valores[1];
        if(valores[2] > tmp)
          tmp = valores[2];         
        
        lcd.setCursor(0, 3);
        lcd.print("Mayor ");
        lcd.print(tmp);
      break;
      
      case '4':
        // Numeros de H a I y de I a J        
        // Obtiene 3 valores de dos dígitos, guarda en arreglo valores [H][I][J]
        for(byte i = 0; i < 3; ++i){
          lcd.setCursor(0, i);
          lcd.print("Ingresa valor ");
          lcd.print(i+1);
          lcd.print(":");        
          valores[i] = getTwoDigits();  
        }
        delay(300);     // Delay para visualizar seleccion
        lcd.clear();    // Limpia display
        lcd.noBlink();  // Desactiva parpadeo
        
        // Itera dos veces, primero de H a I y despues de I a J
        for(byte s = 0; s < 2; ++s) {
          tmp = 0;        // Para cada cinco valores salto de linea (mod 5)
                          // Cuando tmp sea 20, limpia lcd        
          // Cuando H < I o I < J
          while(valores[s] < valores[s+1]){
  
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
            lcd.print(valores[s]++);  // Imprime e incrementa
            lcd.print(", ");        
            delay(200); // Dleay de visualizacion
          }
          // Cuando H > I o I > J
          while(valores[s] > valores[s+1]){
  
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
            lcd.print(valores[s]--);  // Imprime e incrementa
            lcd.print(", ");        
            delay(200); // Dleay de visualizacion
          }
  
          // Imprime I
          // Primero evalua espacion en pantalla
          if((tmp % 5) == 0) {
            if(tmp == 20){
              tmp = 0;
              lcd.clear();
            } else {
              lcd.setCursor(0, tmp / 5);
            }
          }            
          lcd.print(valores[s+1]);
          lcd.print(".");        // Punto final  
          delay(1000); // Dleay de visualizacion
          lcd.clear();
        }
      break;
      
      case '5':
        // Menor de tres
        // Obtiene 3 valores de dos dígitos, guarda en arreglo valores
        for(byte i = 0; i < 3; ++i){
          lcd.setCursor(0, i);
          lcd.print("Ingresa valor ");
          lcd.print(i+1);
          lcd.print(":");        
          valores[i] = getTwoDigits();  
        }
        // Encuentra menor, guarda en tmp
        tmp = valores[0];
        if(valores[1] < tmp)
          tmp = valores[1];
        if(valores[2] < tmp)
          tmp = valores[2];         
        
        lcd.setCursor(0, 3);
        lcd.print("Menor ");
        lcd.print(tmp);
      break;
      
      case '6':
        // Ecuacion de hipotenusa
        // Obtiene 2 valores de dos dígitos, guarda en arreglo valores
        for(byte i = 0; i < 2; ++i){
          lcd.setCursor(0, i);
          lcd.print("Ingresa valor ");
          lcd.print(i+1);
          lcd.print(":");        
          valores[i] = getTwoDigits();  
        }
        // Encuantra hipotenusa
        valFloat = sqrt(pow(valores[0], 2) + pow(valores[1], 2));        
        lcd.setCursor(0, 2);
        lcd.print("Hiptenusa : ");
        lcd.setCursor(0, 3);
        lcd.print(valFloat);
      break;
      
      default:
        lcd.setCursor(3, 1);
        lcd.print("Valor invalido");
      break;
    }
    
    lcd.blink();  // Activa parpadeo
    while((k = kbd.getKey()) == '\0');  // Hasta obtener seleccion        
    animacion(15);
}
void animacion(int retardo){   // Animación barrido de LCD (retardo de 40 predefinido)
  
  for(int i = 0; i < LCD_COLS; ++i){
    for(int j = 0; j < LCD_ROWS; ++j){      
      lcd.setCursor(i, j);
      lcd.print((char)0xFF);      
    }
    delay(retardo);   // Delay para visualizar    
  }
  
  for(int i = 0; i < LCD_COLS; ++i){
    for(int j = 0; j < LCD_ROWS; ++j){      
      lcd.setCursor(i, j);
      lcd.print(" ");      
    }
    delay(retardo);   // Delay para visualizar    
  }
}

byte getTwoDigits(){  // Devuelve el valor de un numero de dos digitos como valor decimal (MAX 99)
  char num1;
  char num2;
  while((num1 = kbd.getKey()) == '\0');     // Hasta recibir tecla
  lcd.print(num1);                          // Imprime numeos
  while((num2 = kbd.getKey()) == '\0');     // Hasta recibir otra tecla
  lcd.print(num2);                          // Imprime numeos
  num1 = (num1 - '0') * 10 + (num2 - '0');  // Calucla valor decimal
  return ((byte) num1);
}
