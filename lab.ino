int led_red = 10;
int pot = A1;

void setup() {
   pinMode(10, OUTPUT);
   pinMode(A1, INPUT);  
}

void loop() {
   int val = analogRead(A1);
   val = val / 4;                    
   analogWrite(10, val);       
}