/*
  Para configurar HC05, correr un programa vacío:
  
  void setup(){}
  void loop(){}

// HC05 MAC: 0023:09:01CAC6
  Ir al monitor serial , 38400 baudios y Both NL & CR
  Correr comandos AT.

*/

#include <SoftwareSerial.h>   // Incluimos la libreria SoftwareSerial
#include <LiquidCrystal_I2C.h>

// Notas musicales para buzzer
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0


// Numero de canciones
#define MAX_S_ARRAY 4

/*
  Macros para aumentar y decrementar indexArray
  Aumentar sin pasarse de MAX_S_ARRAY
  Decrementar sin pasarse de 0 (cero)
*/ 
#define inc_IND_ARRAY(X) ((X+1)%MAX_S_ARRAY)
#define dec_IND_ARRAY(X) ((X+MAX_S_ARRAY-1)%MAX_S_ARRAY)

// Controlar bombilla
#define LIGHT_PIN 9

// Para BTSerial
#define S_RX 10
#define S_TX 11

//------------------- VARIABLES GLOBALES-----------------
byte linea = 1; // Para imprimir correctamente en LCD

// Estado de la bombilla, inicia apagada
bool blighOn = false;
char charBT;    // Guarda cada caractér recibido en Serial
String stringBT;// Guardad toda la cadena de caracteres recibidos

// Para LCD
const byte lcdrows = 4;
const byte lcdcols = 20;

LiquidCrystal_I2C lcd(0x27, lcdrows, lcdcols);  
SoftwareSerial BTSerial(S_RX, S_TX);

// change this to make the song slower or faster
int tempo=144; 

// change this to whichever pin you want to use
const int buzzer = 8;
// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

//--------------------PROTOTIPOS DE FUNCIONES--------------------------
void lighTurnOn(void);
void lighTurnOff(void);
bool pollingStopTrack(void);

//-------------------------FUNCIONES---------------------------
int playSong(int melody[], int notes)
{
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
    // stop the waveform generation before the next note.
    noTone(buzzer);
    if(pollingStopTrack())
      return;
  }
}
//---------------------SONGS---------------
//--------------------PACMAN----------------

int melody_pacman[] = {

  // Pacman
  // Score available at https://musescore.com/user/85429/scores/107109
  NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, //1
  NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
  NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8,

  NOTE_B4, 16,  NOTE_B5, 16,  NOTE_FS5, 16,   NOTE_DS5, 16,  NOTE_B5, 32,  //2
  NOTE_FS5, -16, NOTE_DS5, 8,  NOTE_DS5, 32, NOTE_E5, 32,  NOTE_F5, 32,
  NOTE_F5, 32,  NOTE_FS5, 32,  NOTE_G5, 32,  NOTE_G5, 32, NOTE_GS5, 32,  NOTE_A5, 16, NOTE_B5, 8
};
int notes_pacman = sizeof(melody_pacman) / sizeof(melody_pacman[0]) / 2;

void PacmanSong(void)
{
  playSong(melody_pacman, notes_pacman);
}

//---------------TETRIS---------------------

int melody_tetris[] = {

  //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192
  
  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST,4,

  REST,8, NOTE_D5, 4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

  NOTE_E5,2, NOTE_C5,2,
  NOTE_D5,2, NOTE_B4,2,
  NOTE_C5,2, NOTE_A4,2,
  NOTE_B4,1,

  NOTE_E5,2, NOTE_C5,2,
  NOTE_D5,2, NOTE_B4,2,
  NOTE_C5,4, NOTE_E5,4, NOTE_A5,2,
  NOTE_GS5,1,

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST,4,

  REST,8, NOTE_D5, 4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  REST,8, NOTE_E5, 4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  REST,8, NOTE_B4, 4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  REST,8, NOTE_C5, 4,  NOTE_A4,8,  NOTE_A4,4, REST, 4,

};

int notes_tetris=sizeof(melody_tetris)/sizeof(melody_tetris[0])/2; 

void TetrisSong(void)
{
  playSong(melody_tetris, notes_tetris);
}

//---------------ODE TO JOY----------------------
int melody_odetojoy[] = {

  
  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//1
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_E4,-4, NOTE_D4,8,  NOTE_D4,2,

  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//4
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2,

  NOTE_D4,4,  NOTE_D4,4,  NOTE_E4,4,  NOTE_C4,4,//8
  NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_C4,4,
  NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_D4,4,
  NOTE_C4,4,  NOTE_D4,4,  NOTE_G3,2,

  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//12
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2
  
};

int notes_odetojoy=sizeof(melody_odetojoy)/sizeof(melody_odetojoy[0])/2; 

void OdeToJoySong(void)
{
  playSong(melody_odetojoy, notes_odetojoy);
}

//------------------SUPER MARIO BROS--------------
int melody_smario[] = {

  // Super Mario Bros theme
  // Score available at https://musescore.com/user/2123/scores/2145
  // Theme by Koji Kondo
  
  
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,

  //game over sound
  NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
  NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
  NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,  

};

int notes_smario = sizeof(melody_smario) / sizeof(melody_smario[0]) / 2;

void MarioBrosSong(void)
{
  playSong(melody_smario, notes_smario);
}

/*
  Array de canciones, es un array de apuntadores a funciones,
  donde cada función reproduce una canción, este es el esquema:
  Espacio en memoria - Canción
  0 - PacmanSong()
  1 - TetrisSong()
  2 - OdeToJoySong()
  3 - MarioBrosSong()
*/
void (*songsArray[4])(void) =
{
  &PacmanSong, &TetrisSong, &OdeToJoySong, &MarioBrosSong
};

// Índice para saber qué canción tocar
volatile int indexSong = 0;

void setup() {

  Serial.begin(9600);
  BTSerial.begin(9600); // Default HC-05 baud rate

  pinMode(LIGHT_PIN, OUTPUT);

  // Incio LCD
  lcd.init();
  // Luz de fondo LCD
  lcd.backlight();
  // No mostrar curso
  lcd.print("Arduino HC-05 ready!");

  // Espera a que el móduglo HC-05 se inicie
  delay(1000);
  
}

void loop() {
  
  // Read from Master device connected
  if (BTSerial.available() > 0) {

    // Vacía cadena para recibir nuevo mensaje
    stringBT = "";
    
    while(BTSerial.available() > 0) {

      charBT = BTSerial.read();

      if(charBT == ':')
        break;
      else
        stringBT += charBT; // Concatena carácter

      delay(1);
    }

    if(stringBT.equals("?TO")) {     // Turn On Light
      
      lighTurnOn();

    } else if (stringBT.equals("?TF")) { // Turn Off light
      
      lighTurnOff();

    } else if(stringBT.equals("?PM")) {  // Play Music (>)
      
      // Ejecuta la función de la canción corresponediente al índice actual
      songsArray[indexSong]();

    } else if(stringBT.equals("?NT")) {  // Next Track (->)
      
      // Aumenta índice de canción
      indexSong = inc_IND_ARRAY(indexSong);

    } else if(stringBT.equals("?PT")) {  // Previous Track <-)


      // Decrementa índice de canción
      indexSong = dec_IND_ARRAY(indexSong);

    } else {  // Si no era un comando, imprime en panttalla
    
      if(linea == lcdrows){  // Sólo hay 4 líneas, si se pasa, regresa a primera y limpia
          linea = 1;
          lcd.clear();
        }
      // Para que cada mensaje se imprima en una nueva línea
      lcd.setCursor(0, linea++);
      lcd.print(stringBT);
    }

  /*
  // Send something back
  if (Serial.available()) {
    char c = Serial.read();
    BTSerial.write(c);
  }
  */
  }
}

void lighTurnOn(void)
{
  digitalWrite(LIGHT_PIN, 0);
  blighOn = true;
}

void lighTurnOff(void)
{
  digitalWrite(LIGHT_PIN, 1);
  blighOn = false;
}

/*
  Función que se ejecuta por cada nota en cada canción para
  verificar si se recibió la solicitud de pausar la canción
*/
bool pollingStopTrack(void)
{
  // IF IT WAS PAUSED
  if(BTSerial.available() > 0) {
    stringBT = "";
    while(BTSerial.available() > 0) {
      
      charBT = BTSerial.read();

      if(charBT == ':')
        break;
      else
        stringBT += charBT; // Concatena carácter
    }
    if(stringBT.equals("?ST"))
      return true;
  }
  return false;
}
