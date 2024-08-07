#include "LEDControl.cpp"



 int redPin = 5;
 int greenPin = 9;



void redColor() {
    digitalWrite(redPin, HIGH); 
    digitalWrite(greenPin, LOW); 
}

void greenColor() {
    digitalWrite(redPin, LOW);   
    digitalWrite(greenPin, HIGH); 
}

void yellowColor() {
    digitalWrite(redPin, HIGH); 
    digitalWrite(greenPin, HIGH); 
}