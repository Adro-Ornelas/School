// main.cpp
// main.cp

/* Comment this out to disable prints and save space */
// #define BLYNK_PRINT Serial
//--------------------BLYNK------------------
#define BLYNK_TEMPLATE_ID "TMPL2txXCtLLH"
#define BLYNK_TEMPLATE_NAME "LDR 1"
#define BLYNK_AUTH_TOKEN "xJgIVl9ClL4F_79UVBRm0tH9syqTmxbn"

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>

#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

#include <DHT.h>

//-----------------------CONSTANTS-----------------------

// Sensores 
#define GPIO_LDR 32
#define GPIO_HUMIDITY 33
#define DHTPIN 25
#define DHTTYPE DHT11

// Actuadores
#define GPIO_PUMP 12
#define GPIO_FAN 27
#define GPIO_LIGHT 14


//------------------------GLOBAL VARIABLES--------------

bool pin_pump_on = false;
bool pin_light_on = false;
bool pin_fan_on = false;


// Para teclado (Pines 2 - 9)
const byte nrows = 4;
const byte ncols = 4;
byte rows[nrows] = {18, 5, 17, 16};
byte cols[ncols] = {4, 0, 2, 15};

char keys[nrows][ncols] =
    {{'1', '2', '3', 'C'},
     {'4', '5', '6', '+'},
     {'7', '8', '9', '-'},
     {'*', '0', '/', '='}};

// Para LCD
const byte lcdrows = 4;
const byte lcdcols = 20;

// Objeto Keypad
// DIYables_Keypad kbd = DIYables_Keypad(makeKeymap(keys), rows, cols, nrows, ncols);
Keypad kbd = Keypad(makeKeymap(keys), rows, cols, nrows, ncols);
char k;

// Objeto LCD
LiquidCrystal_I2C lcd(0x27, lcdrows, lcdcols);



// Replace with your network credentials
const char *ssid = "RealmeGTM";
const char *password = "244466666";

uint8_t level_light = 0;
uint8_t level_humidity = 0;
float level_temperature = 0;


DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;
void blynkPush(void);

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Create a WebSocket object
AsyncWebSocket ws("/ws");

//------------------FUNCIONES FS Y WEB SERVER----------------

// Initialize LittleFS
void initLittleFS()
{
  if (!LittleFS.begin(true))
  {
    Serial.println("An error has occurred while mounting LittleFS");
  }
  else
  {
    Serial.println("LittleFS mounted successfully");
  }
}

// Initialize WiFi
void initWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void notifyClients(String state)
{
  ws.textAll(state);
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
  AwsFrameInfo *info = (AwsFrameInfo *)arg;

  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
  {

    data[len] = 0; // null-terminate
    String msg = (char *)data;

    Serial.print("Received: ");
    Serial.println(msg);

    // --------- Detect message type ---------
    if (msg.startsWith("MOVE:"))
    {
    }

    else if (msg == "STOP")
    {

    } else if (msg.startsWith("LIGHT:TOGGLE")) {

      pin_light_on = !pin_light_on;
      Serial.print("LIGHT: ");
      Serial.println(pin_light_on);
      digitalWrite(GPIO_LIGHT, pin_light_on);

    } else if(msg.startsWith("WATER:TRIGGER")) {


      pin_pump_on = !pin_pump_on;
      Serial.print("PUMP: ");
      Serial.println(pin_pump_on);
      digitalWrite(GPIO_PUMP, pin_pump_on);

    } else if(msg.startsWith("FAN:TOGGLE")){

      pin_fan_on = !pin_fan_on;
      Serial.print("FAN: ");
      Serial.println(pin_fan_on);
      digitalWrite(GPIO_FAN, pin_fan_on);

    }

    else
    {
      Serial.println("Unknown message type.");
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
  switch (type)
  {
  case WS_EVT_CONNECT:
    Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
    break;
  case WS_EVT_DISCONNECT:
    Serial.printf("WebSocket client #%u disconnected\n", client->id());
    break;
  case WS_EVT_DATA:
    handleWebSocketMessage(arg, data, len);
    break;
  case WS_EVT_PONG:
  case WS_EVT_ERROR:
    break;
  }
}

void initWebSocket()
{
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

//----------------------------SETUP-----------------------------

void setup()
{

  //------------ FOR DEBUGGING-----------
  Serial.begin(115200);

  pinMode(GPIO_LIGHT, OUTPUT);
  pinMode(GPIO_PUMP, OUTPUT);
  pinMode(GPIO_FAN, OUTPUT);

  digitalWrite(GPIO_LIGHT, pin_light_on);
  digitalWrite(GPIO_PUMP, pin_pump_on);
  digitalWrite(GPIO_FAN, pin_fan_on);

    // // Incio LCD
  lcd.init();
  // Luz de fondo LCD
  lcd.backlight();
  // No mostrar cursor
  lcd.noCursor();

  // Mensaje inicio
  lcd.print("INVERNADERO (*) ");

  // No inicia hasta presionar una tecla
  lcd.cursor();
  while((k = (kbd.getKey())) == '\0');
  lcd.print(k);
  lcd.noCursor();

  // Inicia Wifi
  initWiFi();
  // Inicia WebSocket
  initWebSocket();
  // Inicia small fs
  initLittleFS();

    // Web Server Root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/index.html", "text/html"); });

  server.serveStatic("/", LittleFS, "/");
  server.begin();


  //============================================BLYNK



  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  
  

  // Setup a function to be called every second
  timer.setInterval(1000L, blynkPush);

  dht.begin();
}

void loop()
{

  Blynk.run();
  timer.run();

  // Nivel de luz. Convertir a valor de 0 a 100
  level_light = 100 - analogRead(GPIO_LDR) / 40.95;
  // Nivel de humedad. Convertir a valor de 0 a 100
  level_humidity = 100 - analogRead(GPIO_HUMIDITY) / 40.95;

  float h = dht.readHumidity();
  level_temperature = dht.readTemperature();

  if (isnan(h) || isnan(level_temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  lcd.setCursor(0, 1);
  lcd.print("LDR: ");
  lcd.println(String(level_light));

  lcd.setCursor(0, 2);
  lcd.print("HUM: ");
    lcd.println(String(level_humidity));

  lcd.setCursor(0, 3);
    lcd.print("TMP: ");
    lcd.println(String(level_temperature));


//     // LÓGICA DE VIVERO
//   if(level_humidity < 10) {
//     // Activa bomba
//     digitalWrite(GPIO_PUMP, 1);
//   } else {
//     digitalWrite(GPIO_PUMP, 0);
//   }

//   if(level_light < 20) {
//     // Activa foco
//     digitalWrite(GPIO_LIGHT, 1);
//   } else {
//     digitalWrite(GPIO_LIGHT, 0);
//   }

//   if(level_temperature > 30) {
//     // Activa ventilador
//     digitalWrite(GPIO_FAN, 1);
//   } else {
//     digitalWrite(GPIO_FAN, 1);
//   }

  k = (kbd.getKey());
  if(k == '*') {

    lcd.clear();

    lcd.setCursor(0, 1);
    lcd.print("1 -LIGHT");

    lcd.setCursor(0, 2);
    lcd.print("2 - PUMP");

    lcd.setCursor(0, 3);
    lcd.print("3 - FAN");


    lcd.setCursor(0, 0);
    lcd.cursor();
    lcd.print("Selecciona: ");
    
    do{
    while((k = (kbd.getKey())) == '\0');
    } while(k != '1' && k != '2' && k != '3');
    lcd.noCursor();
    delay(500);

    lcd.clear();
    if(k == '1') {
      lcd.print("NUEVO LIGHt");

    } else if (k == '2') {
    lcd.print("NUEVO PUMP");

    } else if (k == '3') {
    lcd.print("NUEVO FAN");

    }

      lcd.setCursor(0, 1);
      lcd.print("ON - 1");
      lcd.setCursor(0, 2);
      lcd.print("OFF - 0");


    char on_off;
    do{
    while((on_off = (kbd.getKey())) == '\0');
    } while(on_off != '1' && on_off != '0');

    bool opt = on_off - '0';
    
    if(k == '1') {
      digitalWrite(GPIO_LIGHT, opt);

    } else if (k == '2') {
    digitalWrite(GPIO_PUMP, opt);

    } else if (k == '3') {
    digitalWrite(GPIO_FAN, opt);

    }
  }

  ws.cleanupClients();
}

void blynkPush(void) {
    Serial.print("LDR: ");
    Serial.println(level_light);
    Blynk.virtualWrite(V0, level_light);

    Serial.print("HUM: ");
    Serial.println(level_humidity);
    Blynk.virtualWrite(V1, level_humidity);

    Serial.print("TMP: ");
    Serial.println(level_temperature);
    Blynk.virtualWrite(V2, level_temperature);

    // Manda info a websocket
    notifyClients(String("TEMP:" + String(level_temperature)));// + (int)level_temperature));
    notifyClients(String("HUM:" + String(level_humidity)));// + level_humidity));
    notifyClients(String("LUX:" + String(level_light)));// + level_light));
}