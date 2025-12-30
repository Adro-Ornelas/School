/****************************************
 * Include Libraries
 ****************************************/
#include "UbidotsEsp32Mqtt.h"

#include "DHT.h"

/****************************************
 * Define Constants
 ****************************************/

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const char *UBIDOTS_TOKEN = "BBUS-4ksTQChc3OrxC3qzT9CVokBeTMSJAB";  // Put here your Ubidots TOKEN
const char *WIFI_SSID = "RedmiNote8";                               // Put here your Wi-Fi SSID
const char *WIFI_PASS = "12345689";                                 // Put here your Wi-Fi password
const char *DEVICE_LABEL = "esp32";                                 // Put here your Device label to which data  will be published
const char *VARIABLE_LABEL_H = "Humedad";                           // Put here your Variable label to which data  will be published
const char *VARIABLE_LABEL_T = "Temperatura";                       // Put here your Variable label to which data  will be published

Ubidots ubidots(UBIDOTS_TOKEN);

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // ubidots.setDebug(true);  // uncomment this to make debug messages available
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);
  // ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();


  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!ubidots.connected()) {
    ubidots.reconnect();
  }

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("% Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C "));

  ubidots.add(VARIABLE_LABEL_H, h);
  ubidots.add(VARIABLE_LABEL_T, t);
  ubidots.publish(DEVICE_LABEL);

  delay(2000);
}