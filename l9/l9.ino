const int trigPin = 5;
const int echoPin = 4;

const int redPin = 10;
const int greenPin = 9;
const int bluePin = 8;
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

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(blueValue, blueValue);
}

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.println("RGB Distance Indicator Starting...");
  delay(1000);
}

void loop() {
  distanceCm = readUltrasonicDistance(trigPin, echoPin) * 0.01723;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  if (distanceCm < 30) {
    setColor(255, 0, 0);       
    tone(buzzer, 600, 400);
    delay(400);
  }
  else if (distanceCm < 100) {
    setColor(255, 80, 0);      
    tone(buzzer, 500, 200);
    delay(800);
  }
  
  else {
    setColor(0, 255, 0);      
    noTone(buzzer);
    delay(300);
  }
}
