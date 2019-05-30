// outstanding issues!
// 1. Toggle switches are upside down (turn box upside down and they are in order)
// 2. Toggles are inverted 1/0
// 3. Keys are inverted. Which is fine, really.
// Don’t load code on an arduino if it has pins grounded or if 

int keycode;
int bitLength;
int binaryKeycode[8]; //8 bits max, lowest 3 positions used for 3 bit code
int offset; //will be 11 for 3 bit code, 2 for 8 bit code
int listOfKeys[] = {12,4,13,8}; //change these decimal values to whatever the physical keys translate to.
int openPosition = 90;
int closedPosition = 10;

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {

    Serial.begin(9600);
    Serial.println("Hello!");
    myservo.attach(A0);
    randomSeed(analogRead(A1));
    for(int i = 2; i <= 13; i++) pinMode(i, INPUT_PULLUP);
    
    //Check pin A5 for jumper to ground
    pinMode(A5, INPUT_PULLUP);
   
    if(digitalRead(A5)){
        //if pin is ungrounded, High, then we're on step two
        offset = 2; //pin 2 is the first pin to check for the physical keys.
        bitLength = 8;
        decToBin(listOfKeys[random(4)]); //passes one of four decimal keys into all 8 positions of binaryKeycode[8]
    }
    else {
        //else we're on step one
        offset = 11; //pin 11 is the first pin to check for the group of 3 switches, plugged into the ICSP header.
        bitLength = 3;
        decToBin(random(8)); //passes a random number 0 - 7 to populate lowest 3 positions of binaryKeycode[8]
    }
}



void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("The key inserted is: ");
    printKeytest();   // prints 1s and 0s straight to the console from the pins
    Serial.print(", which in decimal is " + String(binToDecFromInput())); // prints sum of digital pins.
    if(isaMatch()){ //if digital pins match keyCode array
      Serial.println(" It's a match!");
      myservo.write(openPosition); 
    } else {
      Serial.println(" which is not the keycode.");
      myservo.write(closedPosition); 

    }
    

}

void decToBin(int thedecimal){
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


float binToDecFromInput(){
  // "Binary to Decimal from Input" start an accumulator at 0, 
  // read each pin (starting at offset pin number), 
  // and if LOW (grounded), add pow(2, pin#) to accumulator
  float sum = 0;
  for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
    if(digitalRead(whichBit + offset)) sum = sum + pow(2, whichBit);
  }
  return sum; // return result, representing which key combination has been tried. 
}



bool isaMatch(){
  // steps through digital pins and keycode array simultaneously, return whether they're identical or not
  for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
    if(digitalRead(whichBit + offset) != binaryKeycode[whichBit]) return false; //if something doesn't match, immediately return false
  }
  return true; //if it checks each bit, and none of them were wrong, return true
}

void printKeytest(){
  // prints 1s and 0s straight to the console from the pins
  for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
    Serial.print(digitalRead(whichBit + offset));
    delay(1);
  }
}



void printKeycode(){
  //DEBUG CODE - not used in this version
  //prints keycode and prints out the array
  Serial.print("The key in decimal is " + String(keycode) + ", the key in binary is ");
  for(int whichBit = bitLength - 1; whichBit >= 0; whichBit--){
    Serial.print(binaryKeycode[whichBit]);

    delay(1);
  }
  Serial.print("\n");
}


