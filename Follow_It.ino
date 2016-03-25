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

int CAPTEUR = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED_13, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

/////// Bouton d'arrêt d'urgence ///////////
BLYNK_WRITE(V8)
{
  Right.write(93);
  Left.write(90); 
  delay(1000);
}

void loop() {

   Blynk.run();
  
  int val = analogRead(CAPTEUR);
  Serial.println(val);
   
  bool TurnLeft = true;

  if(val < 170) { 
    
      if(TurnLeft){
          Right.write(180);
          Left.write(93);
   
         TurnLeft = false;
      }
      else{
        Right.write(0);
        Left.write(180);
  
        TurnLeft = true;
      }
  }
  else { 
     ///////////////// LED ON /////////////////
    digitalWrite(PIN_LED_13, LOW);
    ///////////////// Rotation left  /////////////////
    Right.write(0);
    Left.write(0);  
  }
}//loop()
