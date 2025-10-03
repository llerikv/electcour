int ButtonPin = 2;                
int ledPin = 12;       
int buzzerPin = 10; 

void setup() {
  pinMode(ButtonPin, INPUT_PULLUP);   
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(ButtonPin) == LOW) {
   digitalWrite(ledPin,LOW); 
   digitalWrite(buzzerPin,LOW);
  }else{
   digitalWrite(ledPin,HIGH); 
   digitalWrite(buzzerPin,HIGH); 
  }
  }
