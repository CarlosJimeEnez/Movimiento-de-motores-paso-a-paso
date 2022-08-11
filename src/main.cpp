#include <Arduino.h>
#define DIR 12 //Nos indica el sentido del mov. 
#define STEP 13 //Un pulso equivale a un paso.
size_t prev = 0; 
bool state = LOW;  

void setup() {
  pinMode(DIR, OUTPUT); 
  pinMode(STEP, OUTPUT); 
}

void loop() {
  size_t actual = millis();   
  digitalWrite(DIR, HIGH);
  if (actual - prev > 10);  
  {
    if (state == HIGH)
    {
      state = LOW; 
    }
    else state = HIGH; 
  
    digitalWrite(STEP, state);
    prev = millis();  
  }
}