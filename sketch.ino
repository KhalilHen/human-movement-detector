#include <Servo.h>
#include <Wire.h>
#include <RTClib.h>
#include "LEDControl.h" 
#include "BuzzerControl.h"
#include "ButtonControl.h"

RTC_DS3231 rtc;


const int pirPin = 10;
int buzzerPin = 8; 
const int inputPin = 10; 
int pirState = LOW; 
int val = 0; 



// Distance sensor code
#define PIN_TRIG 3
#define PIN_ECHO 2



void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

    setupButton();
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);


  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }


  pinMode(pirPin, INPUT);


  Serial.begin(9600);
}

void loop() {

    DateTime now = rtc.now();

 if (digitalRead(pirPin) == HIGH) {
    // Motion detected
    Serial.print("Motion detected at ");
    Serial.print(now.timestamp(DateTime::TIMESTAMP_FULL));
    Serial.println();
    
    // Wait to avoid logging multiple times for the same motion
    delay(2000);
  }

bool turnOffBeep = checkButtonState();


  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  int duration = pulseIn(PIN_ECHO, HIGH);
  int distanceCm = duration / 58; // Calculate distance in centimeters

  Serial.print("Distance in CM: ");
  Serial.println(distanceCm);
  Serial.print("Distance in inches: ");
  Serial.println(duration / 148);

  int beepInterval = map(distanceCm, 0, 100, 200, 1000); 
  beepInterval = constrain(beepInterval, 1000, 3000);

  // Read the slider value from A0
  int sliderValue = analogRead(A0);
  int buzzerFrequency = map(sliderValue, 0, 1023, 100, 1000); // Map the slider value to a frequency range

  if (turnOffBeep) {
    // Set LED to yellow
 yellowColor();
  } else {
    if (distanceCm < 100) {
      // Set LED to red
      
    redColor();

    } else {
      // Set LED to green
   greenColor();
    }

    // Handle buzzer tone
    if (distanceCm < 500) {

            playBuzzer(buzzerPin, buzzerFrequency, 500);

      delay(500);
            stopBuzzer(buzzerPin);

      delay(beepInterval);
    }
  }

  val = digitalRead(inputPin); 

  if (val == HIGH && pirState == LOW && distanceCm < 100) {       
    Serial.println("Motion detected!");
        playBuzzer(buzzerPin, buzzerFrequency, 500);


    delay(500); 
        stopBuzzer(buzzerPin);


    pirState = HIGH; 
  } else if (val == LOW) {
    pirState = LOW; 
  }
}

