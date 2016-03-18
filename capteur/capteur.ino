int analogPin = 3;     // potentiometer wiper (middle terminal) connected to analog pin 3

int val = 0;           // variable to store the value read

void setup(){

  Serial.begin(9600);          //  setup serial

}



void loop(){

  val = analogRead(analogPin);    // read the input pin

  Serial.println(val);             // debug value

  distance = map(val,0,1023,10,80);

  if(distance < 15){
    //todo DoTheThing 
  }


}
