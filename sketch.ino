int buzzerPin = 8; 
const int inputPin = 10; 
int pirState = LOW; // C
int val = 0; 

#define PIN_TRIG 3
#define PIN_ECHO 2

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(inputPin, INPUT);

    pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);


  Serial.begin(9600);
}

void loop() {


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

  // Check if distance is less than 100 cm and trigger the buzzer
  if (distanceCm < 100) {

    tone(buzzerPin, 1000);
    delay(500);
    noTone(buzzerPin);
//For now a delay of 5 secs i am later gonna redo it with better interval
    delay(5000);
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
