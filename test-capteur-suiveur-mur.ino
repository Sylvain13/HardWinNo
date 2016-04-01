#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <Servo.h>

Servo Right;
Servo Left;

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

char auth[] = "81ecfffa0d1f463994e82155129f64b1";

bool TurnLeft = true;

// Your WiFi credentials
char ssid[] = "topkek";
char pass[] = "123soleil3";        // Set to "" for open networks

int FRONT_CAPTEUR = 0;
int LEFT_CAPTEUR = 6;
int RIGHT_CAPTEUR = 1;

void initializeMotors() {
  Left.attach(6);
  Right.attach(5);
  Left.write(93);
  Right.write(93);  
}
void initializeBlynk() {
  Blynk.begin(auth, ssid, pass);
}
void stopMotors() {
  Left.write(93);
  Right.write(93);
}
void continueMotors() {
  Left.write(180);
  Right.write(0);
}
void rotate(bool left) {
  if (left) {
    Left.write(180);
    Right.write(180);  
  }
  else {
    Left.write(0);
    Right.write(0);
  }
  delay(500);
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED_13, OUTPUT);
  initializeBlynk();
  initializeMotors();
  analogReadResolution(8);
}

/////// Bouton d'arrêt d'urgence ///////////
BLYNK_WRITE(V8)
{
  Right.detach();
  Left.detach();
}

void loop() {

  Blynk.run();
  int valFront = analogRead(FRONT_CAPTEUR);
  int valLeft = analogRead(LEFT_CAPTEUR);
  int valRight = analogRead(RIGHT_CAPTEUR);

  Serial.print(valFront); 
  Serial.print(" / ");
  Serial.print(valLeft);
  Serial.print(" / ");
  Serial.println(valRight);
  /*
  int valFront = analogRead(FRONT_CAPTEUR);
  if(val > 180) {
    int valSide = analogRead(RIGHT_CAPTEUR);    
    if (valSide > 180){
      rotate(true);
    }
    else {
      rotate(false);
    }
  }
  else {
    continueMotors();
  }
  */
}//loop()
