int bitLength = 3;
int keycode = 4;
int binaryKeycode[3];
int offset = 11;


#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Hello!");
    decToBin(keycode);
    printKeycode();
    for(int i = 2; i <= 13; i++){
      pinMode(i, INPUT_PULLUP);
    }
    myservo.attach(A0);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("The key inserted is: ");
    printKeytest();
    Serial.print(", which in decimal is " + String(binToDecFromInput()));
    if(isaMatch()){
      Serial.println(" It's a match!");
      myservo.write(90); 
    } else {
      Serial.println(" which is not the keycode.");
      myservo.write(0); 

    }
    

}

void decToBin(int thedecimal){
   //we're passing the decimal to be converting, and saying which bit we're interested in
     for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
      if(thedecimal - pow(2, whichBit) >= 0){
        binaryKeycode[whichBit] = 1;
        thedecimal = thedecimal - pow(2, whichBit);
      } else {
        binaryKeycode[whichBit] = 0;
      }
    }
}


float binToDecFromInput(){
  float sum = 0;
  for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
    if(digitalRead(whichBit + offset)) sum = sum + pow(2, whichBit);
  
  }

  
  return sum;
}



bool isaMatch(){
  for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
    if(digitalRead(whichBit + offset) != binaryKeycode[whichBit]) return false; //if something doesn't match, immediately return false
  }
  return true; //if it checks each bit, and none of them were wrong, return true
}

void printKeytest(){
  for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
    Serial.print(digitalRead(whichBit + offset));
    delay(1);
  }
}

void printKeycode(){
  
  Serial.print("The key in decimal is " + String(keycode) + ", the key in binary is ");
  for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
    Serial.print(binaryKeycode[whichBit]);
   // Serial.print(whichBit);

    delay(1);
  }
  Serial.print("\n");
}

