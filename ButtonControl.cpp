#include <Arduino.h>
#include "ButtonControl.h"

const int buttonPin = 6;  // Define the button pin
int oldButtonValue = LOW; 
bool turnOffBeep = false;

void setupButton() {
    pinMode(buttonPin, INPUT_PULLUP);  // Set up the button pin
}

bool checkButtonState() {
    int buttonValue = digitalRead(buttonPin);
    if (buttonValue != oldButtonValue) {
        delay(50);  // Debounce delay
        buttonValue = digitalRead(buttonPin);
        if (buttonValue == LOW) {
            turnOffBeep = !turnOffBeep;  // Toggle beep state
            Serial.println(turnOffBeep ? "Beep is turned off" : "Beep is turned on");
        }
        oldButtonValue = buttonValue;
    }
    return turnOffBeep;
}
