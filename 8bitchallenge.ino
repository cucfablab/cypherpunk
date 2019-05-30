int keycode;
int binaryKeycode[8]; //8 bits max, lowest 3 positions used for 3 bit code
int offset; //will be 11 for 3 bit code, 2 for 8 bit code
int listOfKeys[] = {23,255,36,21};

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {

    Serial.begin(9600);
    Serial.println("Hello!");
    
    //Check pin A0 for jumper to ground
    pinMode(A0, INPUT_PULLUP);
    
    if(digitalRead(A0)){
        //if pin is ungrounded, High, then we're on step two
        offset = 2; //pin 2 is the first pin to check for the physical keys.
        decToBin(listOfKeys[random(4)], 8); //passes a random number 0 - 7 to populate lowest 3 positions of binaryKeycode[8]
    }
    else {
        //else we're on step one
        offset = 11; //pin 11 is the first pin to check for the group of 3 
        decToBin(random(8), 3); //passes a random number 0 - 7 to populate lowest 3 positions of binaryKeycode[8]

    }
    //
    
  
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

void decToBin(int thedecimal, int bitLength){
   //decToBin takes a password in decimal form and 
   // populates the array from high bit (pow(2, password length)) to low bit (pow(2, 0)), 
   // just checking if pow(2,max) fits in the decimal.
   // example, thedecimal = 150, bitLength = 8; for bit number 7 (high bit), 
   // pow(2,7) = 128, 150 - 128 > 0, that's true, so set bit 7 to 1. Pass the result,
   // next bit is pow(2,6), or 64. (150 - 128) - 64 > 0 is false, so that bit is 0, and so on. 
   
     for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
      if(thedecimal - pow(2, whichBit) >= 0){
        binaryKeycode[whichBit] = 1;
        thedecimal = thedecimal - pow(2, whichBit);
      } else {
        binaryKeycode[whichBit] = 0;
      }
    }
}


float binToDecFromInput(int bitLength){
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

void printKeycode(int bitLength){
  
  Serial.print("The key in decimal is " + String(keycode) + ", the key in binary is ");
  for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
    Serial.print(binaryKeycode[whichBit]);
   // Serial.print(whichBit);

    delay(1);
  }
  Serial.print("\n");
}


