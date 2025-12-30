// main.cpp

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP32Servo.h>
#include <LittleFS.h>
// #include <Arduino_JSON.h>

#define GPIO_SERVO 15
#define STEPS 4

//---------------------------MACROS--------------------------

#define unoMas(I) ((I + 1) % 4)
#define unoMenos(I) ((4 + I - 1) % 4)

//-------------------------ENUM----------------------------
enum PASOS
{
  COMPLETOS = 0,
  MEDIOS = 1,
  JOYSTICK = 2
};

enum SENTIDO
{
  HORARIO = 0,
  ANTIHORARIO = 1
};

//-----------------------------CONSTANTES Y VARIABLES GLOBALES----------------------------

// Pines de pasos (IN1, IN2, IN3, IN4) respectivamente
const byte stepsPIN[4] = {21, 19, 18, 5};

// Tiempo para procesar cada paso
const byte period = 5; // 10 ms

// Servomotor
Servo servo;
int grad; // 0 - 180

// Replace with your network credentials
const char *ssid = "RealmeGTM";
const char *password = "244466666";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Create a WebSocket object
AsyncWebSocket ws("/ws");

// Search for parameter in HTTP POST request
const char *PARAM_INPUT_1 = "direction";
const char *PARAM_INPUT_2 = "steps";

String message = "";

// Variables to save values from HTML form
String direction = "STOP";
String velocidad;
String steps;
int velocidad_int = 2; // Default value
bool newRequest = false;

// Para ángulos:
int sizeAng = 0;
int angles[100];

void recorrerAngulos(void);

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

      // Velocidad es 1 para baja y 2 para alta
      // dirc es UP o DW
      // Format: MOVE:dirc&velocidad

      // Obtiene sólo los datos
      String payload = msg.substring(5);

      // Obtiene índice del separador &
      int amp = payload.indexOf("&");

      if (amp > 0)
      {
        // Obtiene dirección
        // UP or DW
        direction = payload.substring(0, amp);
        // 1 or 2
        velocidad = payload.substring(amp + 1);
        velocidad_int = velocidad.toInt();
      }

      Serial.print(direction);
      Serial.println(velocidad_int);

      notifyClients(direction);
      newRequest = true;
    }

    else if (msg == "STOP")
    {
      Serial.println("Stopping motor...");
      notifyClients("STOP");
      // Add your stop logic here
    }
    else if (msg.startsWith("ROT:"))
    {

      // Format: ROT:grad
      String s_grad = msg.substring(4);
      int i_grad = s_grad.toInt();
      Serial.println(i_grad);
      servo.write(i_grad);
    }
    else if (msg.startsWith("ANG:"))
    {

      // El primer dígito es el número de ángulos
      // Formato: ANG:3&90&180&100
      String payload = msg.substring(4);  // Quita inicio
      payload.trim();   // Quita \n final

      int amp = payload.indexOf("&");

      // Obtiene número de ángulos
      sizeAng = payload.substring(0, amp).toInt();

      // Quita el número de ángulos de la cadena
      // payload = payload.substring(amp + 1);

      Serial.print("Size:");
      Serial.println(sizeAng);

      // LLena el arreglo 
      for(int i = 0; i < sizeAng; ++i) {


        payload = payload.substring(amp + 1);

        amp = payload.indexOf("&");
        
        angles[i] = payload.substring(0, amp).toInt();

        Serial.print("[");
        Serial.print(angles[i]);
        Serial.println("]");
      }

      recorrerAngulos();

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
    // Notify client of motor current state when it first connects
    notifyClients(direction);
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

//------------------------------PROTOTIPOS DE FUNCIONES----------------------

void stepperClockwise(int);
void stepperAntiClockWise(int);

//----------------------------SETUP-----------------------------

void setup()
{

  //------------ FOR DEBUGGING-----------

  Serial.begin(115200);

  //-----------NORMAL CODE-----------

  // Inicializa pines
  for (int s = 0; s < STEPS; ++s)
    pinMode(stepsPIN[s], OUTPUT);

  // Inicia servo
  servo.attach(GPIO_SERVO); // Inicia servo en pin 10
  // Servo a cero grados
  // servo.write(0);

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

  /*  WITHOUT WEBSOCKET:
  server.on("/", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    int params = request->params();
    for(int i=0;i<params;i++){
      const AsyncWebParameter* p = request->getParam(i);
      if(p->isPost()){
        // HTTP POST input1 value
        if (p->name() == PARAM_INPUT_1) {
          direction = p->value().c_str();
          Serial.print("Direction set to: ");
          Serial.println(direction);
        }
        // HTTP POST input2 value
        if (p->name() == PARAM_INPUT_2) {
          steps = p->value().c_str();
          Serial.print("Number of steps set to: ");
          Serial.println(steps);
          // Write file to save value
        }
        newRequest = true;
        //Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
      }
    }
    request->send(LittleFS, "/index.html", "text/html"); });
    */

  server.begin();
}

//---------------------------------LOOP---------------------------

void loop()
{

  if (newRequest)
  {
    // CW (clockwise es bajar)
    if (direction == "DW")
    {
      stepperClockwise(velocidad_int);
      Serial.println("DOWN-CW");
    }
    else
    {
      stepperAntiClockWise(velocidad_int);
      Serial.println("UP-ACW");
    }
    newRequest = false;
    notifyClients("stop");
  }

  ws.cleanupClients();

  // stepperAntiClockWise(1);
  // stepperClockwise(1);

  // if (Serial.available())
  // {
  //     char c1;
  //     c1 = Serial.read();

  //     grad = c1 - '0';
  //     grad *= 20;
  //     Serial.println(grad);
  //     servo.write(grad);
  // }
}

//---------------------DEFINICIÓN DE FUNCIONES---------------------------

void stepperClockwise(int ms)
{
  int period = ms;

  for (int h = 0; h < 512; ++h)
  {
    // Cada ciclo:
    for (int i = 0; i < 4; ++i)
    {
      // Cada dos pasos:
      digitalWrite(stepsPIN[i], HIGH);
      delay(period);
      digitalWrite(stepsPIN[unoMas(i)], HIGH);
      delay(period);
      digitalWrite(stepsPIN[i], LOW);
    }
  }
  // Quedo prendido A, se apaga
  digitalWrite(stepsPIN[0], LOW);
}

void stepperAntiClockWise(int ms)
{
  int period = ms;

  for (int h = 0; h < 512; ++h)
  {
    // Cada ciclo:
    for (int i = 3; i >= 0; --i)
    {
      // Cada dos pasos:
      digitalWrite(stepsPIN[i], HIGH);
      delay(period);
      digitalWrite(stepsPIN[unoMenos(i)], HIGH);
      delay(period);
      digitalWrite(stepsPIN[i], LOW);
    }
  }
  // Quedo prendido D, se apaga
  digitalWrite(stepsPIN[3], LOW);
}

void recorrerAngulos(void)
{

  for (int i = 0; i < sizeAng; ++i)
  {
    servo.write(angles[i]);
    delay(1500);
  }

  sizeAng = 0;
}