#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include<Servo.h>

Servo Right;
Servo Left;

#include <Ethernet.h>

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

char auth[] = "81ecfffa0d1f463994e82155129f64b1";

// Your WiFi credentials
char ssid[] = "topkek";
char pass[] = "123soleil3";        // Set to "" for open networks

void setup()
{
  Right.attach(6);
  Left.attach(5);

  //Arrêt par défaut
  Right.write(93);
  Left.write(90); 

  //Sortie console 9600
  Serial.begin(9600);

  //Initialisation de la led
  pinMode(PIN_LED_13, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

////////////////////////////////LED////////////////////////////

////////////////////////ON LED
BLYNK_WRITE(V2)
{
   Serial.println("allume");
  digitalWrite(PIN_LED_13, LOW);
}

////////////////////////OFF LED
BLYNK_WRITE(V3)
{
  Serial.println("eteind");
  digitalWrite(PIN_LED_13, HIGH);
}

////////////////////////Arret Urgence
BLYNK_WRITE(V8)
{
  
  Right.detach();
  Left.detach(); 
}

////////////////////////JoystickController
BLYNK_WRITE(V9){
    
    int x = param[0].asInt();
    int  y = param[1].asInt();
  
       
      if (  65 < x && x < 195 && 127 < y){
        Right.write(180);
        Left.write(0);
      } else if( 65 < x && x < 195 && y < 127 ){
        Right.write(0);
        Left.write(180);
      } else if( 65 < y && y < 195 && x < 127 ){
        Right.write(180);
        Left.write(180);
      } else if( 65 < x && x < 195 && 127 < y ){
        Right.write(0);
        Left.write(0); 
      }
    
}

void loop()
{
  
  Blynk.run();
  Serial.println(V8);

}





