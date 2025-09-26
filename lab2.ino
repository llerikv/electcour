int led_red = 10; 
int pot = A1;       
int button = 6;   

int mode = 0;               
bool lastButtonState = HIGH; 
int brightness = 0;         
int fadeAmount = 5;       

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(button, INPUT_PULLUP); 
  pinMode(A1, INPUT);    
}

void loop() {
  bool buttonState = digitalRead(button);
  if (lastButtonState == HIGH && buttonState == LOW) {
    mode = 1 - mode;
    delay(200); 
  }
  lastButtonState = buttonState;

  if (mode == 0) {
    int val = analogRead(pot); 
    val = val / 4;           
    analogWrite(led_red, val);
  }

  else {
    analogWrite(led_red, brightness);

    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    delay(20);
  }
}