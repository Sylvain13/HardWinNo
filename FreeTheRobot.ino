#include <Servo.h>

int analogPin = 3; 
int val = 0;    

Servo RoueDroit;
Servo RoueGauche;

void setup() {
  analogReadResolution(8);
  RoueDroit.attach(6);
  RoueGauche.attach(5);	

}


void Avancer(){

	RoueGauche.write(0);
	RoueDroit.write(180);
}
!

void Droite()
{
  Right.write(180);
  Left.write(180);

}

void Gauche();
{
  Right.write(0);
  Left.write(0); 
}

void CheckDistance(){
	while (analogRead(analogPin) < 200){

		int v = random(0,50000);

	 	if( v  % 2){

	 		 Droite();

	 	} if( v % 5) {

	 		Droite();
	 		delay(1000);

	 	}else {

	 		Gauche();
	 	}	
	}
}



void loop{

	 val = analogRead(analogPin);
	 
	 if(distance <  200){

	 	CHekDistance();

  	} else {
  		int v = random(0,50000)
  		if( v  % 2 ){

  			Avancer();
	
  		}else if( v % 3){

  			Droite();
  		}else if(v % 5){

  			Gauche();
  		}
  		
  	}
}


