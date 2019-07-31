/*
  BlinkTone
  
  Modified from Arduino Blink Example
  
  Once you've changed the frequency for blinking an LED, drop a speaker in instead.
  Modify the delay to hear different tones. Then, write a function to make it easier to call for different tones.
*/
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(A0) == LOW){
    tone(13, 400);
    Serial.println(1);
  } else {
    noTone(13);
    Serial.println(0);
  }
}
