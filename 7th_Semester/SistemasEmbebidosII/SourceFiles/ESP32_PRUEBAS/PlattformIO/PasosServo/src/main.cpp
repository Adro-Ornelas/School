// main.cpp

#include <Arduino.h>


#define GPIO_SERVO 5

void animacion(void);

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT); // On most DevKit v1 boards, GPIO2 has the onboard LED

    // servo.attach(GPIO_SERVO); // Inicia servo en pin 10
    // Servo a cero grados
    // servo.write(0);
}


void loop() {
    digitalWrite(2, HIGH);

    // servo.write(45);
    delay(500);
    digitalWrite(2, LOW);
    delay(2000);
    // servo.write(90);
    Serial.print("oasodnaos");
}
