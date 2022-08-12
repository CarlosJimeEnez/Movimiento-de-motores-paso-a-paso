#include <Arduino.h>
#define DIR 12 //Nos indica el sentido del mov. 
#define STEP 13 //Un pulso equivale a un paso.

#define DIR2 33 //Nos indica el sentido del mov. 
#define STEP2 32 //Un pulso equivale a un paso.

// size_t prev = 0; 
// size_t prev2 = 0; 

// bool state = LOW;  
// bool state2 = LOW; 

// bool toggle_button(bool estado){
//   bool state = estado; 
//   if (state == HIGH)
//   {
//     state = LOW; 
//   }
//   else{
//     state = HIGH;
//   }  
//   return state; 
// }

// void setup() {
//   pinMode(DIR, OUTPUT); 
//   pinMode(STEP, OUTPUT);
//   pinMode(DIR2, OUTPUT); 
//   pinMode(STEP2, OUTPUT); 
// }

// void loop() {
//   digitalWrite(DIR, HIGH);
//   digitalWrite(DIR2, HIGH); 

// //MOTOR 1: 
//   size_t actual = millis();   
//   if (actual - prev > 10);  
//   {
//     state = toggle_button(state);
//     digitalWrite(STEP, state);
//     prev = millis();  
//   }

// //MOTOR 2: 
//   if (actual - prev2 > 100);  
//   {
//     state2 = toggle_button(state2); 
//     digitalWrite(STEP, state2);
//     prev2 = millis();  
//   }
// }

#include <AccelStepper.h>

// Define some steppers and the pins the will use
AccelStepper stepper1(1,STEP , DIR); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper stepper2(1, STEP2, DIR2);

void setup()
{  
    stepper1.setMaxSpeed(200.0);
    stepper1.setAcceleration(100.0);
    stepper1.moveTo(24);
    
    stepper2.setMaxSpeed(300.0);
    stepper2.setAcceleration(100.0);
    stepper2.moveTo(1000000);
}

void loop()
{
    // Change direction at the limits
    if (stepper1.distanceToGo() == 0)
	stepper1.moveTo(-stepper1.currentPosition());
    stepper1.run();
    stepper2.run();
}