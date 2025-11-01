const int buttonPin = 2;
const int ledPin = 12;
const int buzzerPin = 10;
const int potPin = A3;

bool ringing = false;
unsigned long ringStartTime = 0;
unsigned long lastBlinkTime = 0;
bool ledState = false;
int ringDuration = 0;  

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();


  if (!ringing && digitalRead(buttonPin) == LOW) {
    ringing = true;
    ringStartTime = now;
    lastBlinkTime = now;

    
    int potValue = analogRead(potPin);
    ringDuration = map(potValue, 0, 1023, 1000, 10000); 

    Serial.print("Звонок начался на ");
    Serial.print(ringDuration / 1000.0);
    Serial.println(" секунд");
  }


  if (ringing) {
    if (now - lastBlinkTime >= 200) {
      lastBlinkTime = now;
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      digitalWrite(buzzerPin, ledState);
    }

    if (now - ringStartTime >= ringDuration) {
      ringing = false;
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      Serial.println("Звонок окончен");
    }
  }
}
