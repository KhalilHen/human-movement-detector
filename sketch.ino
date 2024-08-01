int buzzerPin = 8; 
const int inputPin = 10; 
int pirState = LOW; // C
int val = 0; 


//Distance sensor code
#define PIN_TRIG 3
#define PIN_ECHO 2


//Push button code
#define BUTTON_PIN 6
int oldValue = LOW; 
boolean turnOffBeep = false;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(inputPin, INPUT);

    pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

//buttn
  pinMode(BUTTON_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  int buttonValue = digitalRead(
    BUTTON_PIN
  );


  if(buttonValue != oldValue)
  {
    if(buttonValue == HIGH)
    {

        if(turnOffBeep == false)
        {

            turnOffBeep = true;
    else if (turnOffBeep == true) {

      turnOffBeep = false; 
    }
        }

      Serial.println("The button is pressed.");
    }
    else
    {
      Serial.println("The button is released.");
    }
    // Remember the value for the next time.
    oldValue = buttonValue;
  }

digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

 int duration = pulseIn(PIN_ECHO, HIGH);
  int 
 distanceCm = duration / 58; // Calculate distance in centimeters

  Serial.print("Distance in CM: ");
  Serial.println(distanceCm);
  Serial.print("Distance in inches: ");
  Serial.println(duration / 148);


  int beepInterval = map(distanceCm, 0, 100, 200, 1000); 
  beepInterval = constrain(beepInterval, 1000, 3000); 



//Comment out to prevent a headache 
if(turnOffBeep == true) {

Serial.println("Beep is turned off"); 

}
 else  if (distanceCm < 500) {

    //tone(buzzerPin, 0);
    delay(500);
    noTone(buzzerPin);
    delay(beepInterval);
  }

 


  val = digitalRead(inputPin); 

  if (val == HIGH && pirState == LOW  && distanceCm < 100  ) {       
    Serial.println("Motion detected!");
    tone(buzzerPin, 1000); 
    delay(500); 
    noTone(buzzerPin); 
    pirState = HIGH; 
  } else if (val == LOW) {
    pirState = LOW; 
  }
}
