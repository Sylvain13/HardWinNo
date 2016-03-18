#include<Servo.h>

Servo RoueDroit;
Servo RoueGauche;

void setup() {
  RoueDroit.attach(6);
  RoueGauche.attach(5);
  // put your setup code here, to run once:
}

void loop() {

  RoueDroit.write(180);
  RoueGauche.write(-180);
  // put your main code here, to run repeatedly:

}
