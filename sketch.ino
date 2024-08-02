int buzzerPin = 8; 
const int inputPin = 10; 
int pirState = LOW; // C
int val = 0; 
const int buttonPin = 6;


//Distance sensor code
#define PIN_TRIG 3
#define PIN_ECHO 2

#define buttonPin 6

const int redPin = 5;
const int greenPin =  9;
const int bluePin;



//Push button code
int oldButtonValue = LOW; 
bool turnOffBeep = false;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(inputPin, INPUT);

    pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

//buttn
  //pinMode(BUTTON_PIN, INPUT);
pinMode(buttonPin, INPUT_PULLUP);


  Serial.begin(9600);
}

void loop() {
  int buttonValue = digitalRead(buttonPin);


  if(buttonValue != oldButtonValue)
  {
    delay(50);
   buttonValue = digitalRead(buttonPin);
    if(buttonValue == LOW)
    { 
      turnOffBeep = !turnOffBeep; 
      Serial.println(turnOffBeep ? "Beep is turned off" : "Beep is turned on");

        

      Serial.println("The button is pressed.");
    }
  
    // Remember the value for the next time.
    oldButtonValue = buttonValue;
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
if(!turnOffBeep ) {

Serial.println("Beep is turned off"); 


   if (distanceCm < 500) {

   // tone(buzzerPin, 450);
    delay(500);
    noTone(buzzerPin);
    delay(beepInterval);
  }

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
