// Brute force
// This guesses passwords semi-randomly

// this one works! 
// It chooses numbers to guess semi-randomly, which takes a little longer per step, 
// It times in proportion to how long a brute force method would take

  long password8;
  long password16; 
  long password32; 
  long password128a; 
  long password128b;
  long password128c;
  long password128d;

void setup() {
  // put your setup code here, to run once:
  // resets when you press the reset button
  
  // starts communication between the Arduino and the computer over serial (USB)
  Serial.begin(115200);
  
  // these variables will store a (semi)randomly picked password this many digits long
  password8 = pickPassword(8);
  password16 = pickPassword(16);
  password32 = pickPassword(32);
  password128a = pickPassword(8);
  password128b = pickPassword(8);
  password128c = pickPassword(8);
  password128d = pickPassword(8);

  // for each password, 
  // start a timer, crack the password, 
  // then stop the timer, and say how long it took
  int timer = millis();
  long solution8 = bruteForce(password8, 8);
  timer = millis() - timer;

  Serial.println("The password is 8 bits long.");
  Serial.println("The password was " + String(solution8) + ", it took " + String(timer) + " milliseconds. " +  String(password8) + " \n");
  delay(4000);

  timer = millis();
  long solution16 = bruteForce(password16, 16);
  timer = millis() - timer;
  Serial.println("The password is 16 bits long.");
  Serial.println("The password was " + String(solution16) + ", it took " + String(timer) + " milliseconds." +  String(password16) + " \n");
  delay(4000);

  timer = millis();
  long solution32 = bruteForce(password32, 32);
  timer = millis() - timer;
  Serial.println("The password is 32 bits long.");
  Serial.println("The password was " + String(password32) + ", it took " + String(timer) + " milliseconds. " +  String(password32) + "\n");
   
}

void loop() {
/*  
  long guessA = 0;
  long guessB = 0;
  long guessC = 0;
  long guessD = 0;

  int timer = millis();
  for(int i = 0; i < pow(2, 8); i++){
    for(int j = 0; j < pow(2, 8); j++){
      for(int k = 0; k < pow(2, 8); k++){
        for(int l = 0; l < pow(2, 8); l++){
          if(millis() % 1000 == 0) Serial.println(String(i) + String(j) + String(k) + String(l));
          if(i == password128a && j == password128b && k == password128c && l == password128d){
              timer = millis() - timer;
              Serial.println("The password was " + String(i) + String(j) + String(k) + String(l) + ", it took " + String(timer) + " milliseconds. \n");

          }
        }
      }
    }
  }
*/

}

//pickPassword takes the numbers of bits as an argument. Pass 8 and it will return an 8 bit password. 

long pickPassword(int passwordLength) {
    randomSeed(analogRead(0));
    // picks a (semi) random number that 
    // is between 0 and the power of 2 ^ (the length of the password in bits) 
    // e.g. for 4 bits, between 0 and 2*2*2*2. 
    long password = random(pow(2, passwordLength));
    return password;
}

long bruteForce(long password, int power) {
  long guess = 0;
  randomSeed(analogRead(0));

  while(guess != password){
    guess = random(pow(2, power));
    Serial.println(guess);
  //  guess++;
  // note, when we guess in order… the compiler is toooo clever by half and 
  // it does not go through all the steps because it already knows the answer, so the timing is off.
  }
  return guess;
}

