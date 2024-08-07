#ifndef BUZZERCONTROL_H
#define BUZZERCONTROL_H

// Function

void playBuzzer(int buzzerPin, int frequency, int duration) {
    tone(buzzerPin, frequency, duration);
}

void stopBuzzer(int buzzerPin) {
    noTone(buzzerPin);
}
#endif 
