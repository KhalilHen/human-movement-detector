int buzzerPin = 8; 
const int inputPin = 10; 
int pirState = LOW; // C
int val = 0; 

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin); 

  if (val == HIGH && pirState == LOW) {       
    Serial.println("Motion detected!");
    tone(buzzerPin, 1000); 
    delay(500); 
    noTone(buzzerPin); 
    pirState = HIGH; 
  } else if (val == LOW) {
    pirState = LOW; 
  }
}
