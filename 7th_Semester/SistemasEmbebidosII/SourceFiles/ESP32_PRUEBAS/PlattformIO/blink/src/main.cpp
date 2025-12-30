// main.cpp

#include <Arduino.h>
#include "DHT.h"

void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT); // On most DevKit v1 boards, GPIO2 has the onboard LED
}

void loop() {
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);
    Serial.print("oasodnaos");
}
