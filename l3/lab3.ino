const int armButton = 2;      
const int sensorButton = 3;  
const int potPin = A0;       
const int redLED = 12;       
const int buzzer = 10;       

bool armed = false;           
bool alarmActive = false;     
unsigned long alarmStart = 0; 
unsigned long alarmDuration = 0; 

void setup() {
  pinMode(armButton, INPUT_PULLUP);
  pinMode(sensorButton, INPUT_PULLUP);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
  Serial.println("Сигнализация готова.");
}

void loop() {
  if (digitalRead(armButton) == LOW) {
    delay(200); 
    armed = !armed;
    Serial.print("Система охраны: ");
    Serial.println(armed ? "ВКЛЮЧЕНА" : "ВЫКЛЮЧЕНА");
    while (digitalRead(armButton) == LOW); 
  }

  if (armed && !alarmActive && digitalRead(sensorButton) == LOW) {
    delay(50); 
    if (digitalRead(sensorButton) == LOW) {
      int potValue = analogRead(potPin); 
      int seconds = map(potValue, 0, 1023, 1, 20); 
      alarmDuration = (unsigned long)seconds * 1000;
      alarmStart = millis();
      alarmActive = true;

      Serial.print("Тревога! Время: ");
      Serial.print(seconds);
      Serial.println(" сек.");
    }
  }

  if (alarmActive) {
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100); 
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
    delay(100);

    if (millis() - alarmStart >= alarmDuration) {
      alarmActive = false;
      digitalWrite(redLED, LOW);
      digitalWrite(buzzer, LOW);
      Serial.println("Тревога окончена.");
    }
  }
}
