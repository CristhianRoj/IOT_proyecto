#include <Arduino.h>

const int pines[12] = {19, 18, 5, 17, 16, 4}; 

int TRIG = 14; 
int ECHO = 12;
int inches = 0;
int cm = 0;
int limite;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH); //esta es una funcin propia de arduino que retorna el pulso de noe que cosa
  
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600); 
  for(int i=0; i<10; i++){
    pinMode(pines[i], OUTPUT); 
  }
  Serial.println("joselito"); 
}

// the loop function runs over and over again forever
void loop() {

  cm = 0.01723 * readUltrasonicDistance(TRIG, ECHO); 


  // for(int i=0; i<10; i++){
  //     digitalWrite(pines[i], HIGH); 
  //     delay(500); 
  //     digitalWrite(pines[i], LOW); 
  //     delay(500); 
  // }        
    for(int i = 0; i<6; i++) digitalWrite(pines[i], LOW); 
    if(cm>=20) limite = 6; 
    else if(cm>=16) limite = 5; 
    else if(cm >= 12) limite = 4;
    else if(cm>=8) limite = 3; 
    else if(cm >= 4) limite = 2; 
    else limite = 1; 

    
    for(int i=0; i<limite; i++){
      digitalWrite(pines[i], HIGH); 
    }


    inches = (cm / 2.54);
    Serial.println(inches);
    
    Serial.println("in, ");
    Serial.println(cm);
    Serial.println("cm");
    delay(100); // Wait for 100 millisecond(s)

             // wait for a second
}