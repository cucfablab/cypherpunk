// Brute force
// This guesses passwords semi-randomly

// this one works! 
// It chooses numbers to guess semi-randomly, which takes a little longer per step, 
// It times in proportion to how long a brute force method would take

  long password8;
  long password16; 
  long password32; 


  int the8bitTime = 0;
  int the16bitTime = 0;
  int the32bitTime = 0;

void setup() {
  // put your setup code here, to run once:
  // resets when you press the reset button
  
  // starts communication between the Arduino and the computer over serial (USB)
  Serial.begin(115200);
  
  // these variables will store a (semi)randomly picked password this many digits long
  password8 = pickPassword(8);
  password16 = pickPassword(16);
  password32 = pickPassword(32);
  

  // for each password, 
  // start a timer, crack the password, 
  // then stop the timer, and say how long it took
  
  int timer = millis();
  long solution8 = bruteForce(password8, 8);
  the8bitTime = millis() - timer;


  timer = millis();
  long solution16 = bruteForce(password16, 16);
  the16bitTime = millis() - timer;

  timer = millis();
  long solution32 = bruteForce(password32, 32);
  the32bitTime = millis() - timer;
  
  if(the8bitTime > 0) Serial.print("8 bits took " + String(the8bitTime) + " milliseconds. ");
  if(the16bitTime > 0) Serial.print("16 bits took " + String(the16bitTime) + " milliseconds. ");
  if(the32bitTime > 0) Serial.print("32 bits took " + String(the32bitTime) + " milliseconds. ");

}

void loop() {
}

//pickPassword takes the numbers of bits as an argument. Pass 8 and it will return an 8 bit password. 

long pickPassword(int passwordLength) {
    randomSeed(analogRead(A3));
    // picks a (semi) random number that 
    // is between 0 and the power of 2 ^ (the length of the password in bits) 
    // e.g. for 4 bits, between 0 and 2*2*2*2. 
    long password = random(pow(2, passwordLength));
    return password;
}

long bruteForce(long password, int power) {
  long guess = 0;
  randomSeed(analogRead(A3));

  while(guess != password){
    guess = random(pow(2, power));
    if(the8bitTime == 0) Serial.println("This guess: " + String(guess));
    if(millis() % 100 == 0){
      if(the8bitTime > 0) Serial.print("8 bits took " + String(the8bitTime) + " milliseconds. ");
      if(the16bitTime > 0) Serial.print("16 bits took " + String(the16bitTime) + " milliseconds. ");
      Serial.println("This guess: " + String(guess));
      delay(1);
    }
  //  guess++;
  // note, when we guess in order… the compiler is toooo clever by half and 
  // it does not go through all the steps because it already knows the answer, so the timing is off.
  }
  return guess;
}



