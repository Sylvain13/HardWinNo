#include <Servo.h>


Servo RoueDroit;
Servo RoueGauche;

void setup() {
  RoueDroit.attach(6);
  RoueGauche.attach(5);	
  int i =;
}

void loop{

	Avancer();
	i++;
	delay(1000);
if( i == 30000){
		Stop(){
	}
}

	
}


void Avancer(){
	

  RoueDroit.write(180);
  RoueGauche.write(-180);

	
}

void Stop(){


  RoueDroit.write(93);
  RoueGauche.write(90);
	
}