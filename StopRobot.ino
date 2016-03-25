#include <Servo.h>

int analogPin = 3; 
int val = 0;    

Servo RoueDroit;
Servo RoueGauche;

void setup() {
  analogReadResolution(8);
  RoueDroit.attach(6);
  RoueGauche.attach(5);	
  int i =;
}

void loop{

	 val = analogRead(analogPin);
	 distance = map(val,0,1023,10,80);
	 if(distance < 15){

  	} else {

  	}
}


