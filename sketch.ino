// Now turn this trash into treasure!
int buzzerPin13 = 13;
unsigned long previousMillis = 0;
const long interval = 60000;
// unsigned long previousMillis = 0;
// const long interval = 60000;
int inputPin = 2;               
int pirState = LOW;        
int val = 0;     
void setup() {

  pinMode(buzzerPin13, OUTPUT);
pinMode(inputPin, INPUT);   
  // put your setup code here, to run once:
  Serial.begin(9600);


}
void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);  
    unsigned long currentMillis = millis();


    if(val ==  HIGH) {
 if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    tone(buzzerPin13, 1000); 
    delay(500);
    noTone(buzzerPin13);
  }

  Serial.println("test");

     }

  delay(1); // this speeds up the simulation
}