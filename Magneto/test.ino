#include "Magnetometer.h"

Magnetometer magneto;

void setup() {
  Serial.begin(9600);

  while(!magneto.begin()) {
    Serial.println("Fail");
    delay(1000);
  }
}

void loop() {
  Serial.println(magneto.getX());
  delay(100);
}

