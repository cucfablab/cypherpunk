// Virginia McCreary
// with colten Jackson
// CUCfablab.org
// open source code, open source curriculum
// use and prosper ;)

// plug in pins 2 through 13 from this arduino to the locked arduino
// This arduino will OUTPUT all possible high and low combinations
// For 8 bits, that's pins 2 through 9

// this is version 1.0 
// It uses recursion because that's what makes most sense to me... :)

int maxPin = 9; 

void setup() {
  // put your setup code here, to run once:

  // initialize all the pins you might use to be OUTPUTs and LOW
  // LOW is the same as ground, or 0 volts. It stands in for that key pin existing.
  // HIGH is the same as 5 volts. It stands in for that key pin NOT existing.
  for(int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  // initialize serial communication at 9600 bits per second:
  // to see output
  //Serial.begin(9600);
  tryBothBits(2);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 

}

void tryBothBits(int pinNumber) {
    if (pinNumber > maxPin) 
      return; 
    // this is to slow down so that the lock can read and print, which is sloooow
    delay(80);  
    
    digitalWrite(pinNumber, HIGH); 


    //Serial.print("1 ");
    //Serial.println(pinNumber);
    //delay(10);
    tryBothBits(pinNumber++);
    
    digitalWrite(pinNumber, LOW);

    //Serial.print("0 ");
    //Serial.println(pinNumber);
    //delay(10);
    tryBothBits(pinNumber++); 
     
    return;  
}
