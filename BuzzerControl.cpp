#include <Arduino.h>   // Ensure you include Arduino core library
#include "BuzzerControl.h"



void playBuzzer(int buzzerPin, int frequency, int duration) {
    tone(buzzerPin, frequency, duration);
}

void stopBuzzer(int buzzerPin) {
    noTone(buzzerPin);
}
