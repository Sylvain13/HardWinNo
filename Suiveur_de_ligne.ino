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

// Your WiFi credentials
char ssid[] = "topkek";
char pass[] = "123soleil3";        // Set to "" for open networks

int CAPTEUR_pin = 0; 

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_LED_13, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  
  Right.attach(6);
  Left.attach(5);
  
  Right.write(93);
  Left.write(90);
}

///////!\ Bouton d'arrêt d'urgence /!\//////////
BLYNK_WRITE(V8)
{
  Right.detach();
  Left.detach();
}

void loop() 
{
  Blynk.run();
  int val = analogRead(CAPTEUR_pin);
 
// ligne blanche détecté
  if(val < 250) 
  { //Tourne a gauche
      Right.write(180);
      Left.write(90); 
  }
// en dehors de la ligne blanche
  else 
  { //Tourne a droite
      Right.write(93);
      Left.write(0);   
  }
}//loop()
