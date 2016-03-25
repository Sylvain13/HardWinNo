#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <Servo.h>

#include <Ethernet.h>

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

char auth[] = "81ecfffa0d1f463994e82155129f64b1";

// Your WiFi credentials
char ssid[] = "topkek";
char pass[] = "123soleil3";        // Set to "" for open networks

int analogPin = 0; 
int val = 0;    

Servo Right;
Servo Left;
int distance;



void initializeMotors() {
  Left.attach(6);
  Right.attach(5);
  Left.write(93);
  Right.write(93);  
} // initializeMotors()

void initializeBlynk() {
  Blynk.begin(auth, ssid, pass);
}

void stopMotors() {
  Left.write(93);
  Right.write(93);
} // stopMotors()

void continueMotors() {
  Left.write(180);
  Right.write(0);
}

void setup() {

  //initialize serial
  Serial.begin(9600);

  //function for motos
  initializeMotors();

  //Blynk
  initializeBlynk();

  analogReadResolution(8);

} // setup()


BLYNK_WRITE(V8)
{
  Right.detach();
  Left.detach(); 
}

void loop(){

  //Reading input
  Blynk.run();
  Serial.println(val);
   val = analogRead(analogPin);
   if(val > 180){
      stopMotors();      
   } 
   else { 
      continueMotors();
   }
} // loop()



