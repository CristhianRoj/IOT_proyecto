#include <Arduino.h>

const int pines[12] = {19, 18, 5, 17, 16, 4}; 

const int TRIG = 14; 
const int ECHO = 12;
float inches = 0;
float cm = 0;
int limite;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH); 
  
}

void setup() {
  Serial.begin(9600); 
  for(int i=0; i<10; i++){
    pinMode(pines[i], OUTPUT); 
  } 
}

void loop() {

  cm = 0.01723 * readUltrasonicDistance(TRIG, ECHO); 
     
  for(int i = 0; i<6; i++) digitalWrite(pines[i], LOW); 
    
  if(cm >= 40) limite = 6; 
  else if(cm >= 32) limite = 5; 
  else if(cm >= 24) limite = 4;
  else if(cm >= 16) limite = 3; 
  else if(cm >= 8) limite = 2; 
  else limite = 1; 

  for(int i=0; i<limite; i++){
    digitalWrite(pines[i], HIGH); 
  }

  inches = (cm / 2.54);

  Serial.println(inches);
  Serial.println("in, ");
  Serial.print(cm);
  Serial.println("cm");
  
  delay(300);
}
