const int trigPin = 5;
const int echoPin = 4;

const int redLed = 10;
const int yellowLed = 9;
const int greenLed = 8;
const int buzzer = 11;

float distanceCm;

long readUltrasonicDistance(int trigPin, int echoPin) {
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.println("Ultrasonic Distance System Starting...");
  delay(1000);
}

void loop() {
  distanceCm = readUltrasonicDistance(trigPin, echoPin) * 0.01723;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  if (distanceCm < 50) {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 523, 500);
    delay(500);
  } 
  else if (distanceCm < 150) {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 523, 500);
    delay(1000);
  } 
  else {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
}
