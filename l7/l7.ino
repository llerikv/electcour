#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int tempPin = A3;
const int lightPin = A1;
const int potPin = A0;
const int ledPin = 2;
const int buzzerPin = 8;

float tempValue;
int lightValue;
float tempThreshold = 30.0; 
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("System Starting...");
  delay(1000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(tempPin);
  tempValue = (sensorValue * 5.0 / 1023.0) * 100.0; 

  lightValue = analogRead(lightPin);

  int potValue = analogRead(potPin);
  tempThreshold = map(potValue, 0, 1023, 20, 50); 

  Serial.print(tempValue);
  Serial.print(",");
  Serial.println(lightValue);

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(tempValue, 1);
  lcd.print("C Th:");
  lcd.print(tempThreshold, 1);

  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(lightValue);
  lcd.print("   "); 

  if (tempValue > tempThreshold || lightValue < 300) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}
