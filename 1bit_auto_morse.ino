
int beat = 100;

String Input_msg = "Brandon Is Awesome";
const int pin = 9;

const String alphabet[] = {
  ".-",
  "-...",
  "-.-.",
  "-..",
  ".",
  "..-.",
  "--.",
  "....",
  "..",
  ".---",
  "-.-",
  ".-..",
  "--",
  "-.",
  "---",
  ".--.",
  "--.-",
  ".-.",
  "...",
  "-",
  "..-",
  "...-",
  ".--",
  "-..-",
  "-.--",
  "--.."
};

const String numbers[] = {
  "-----",
  ".----",
  "..---",
  "...--",
  "....",
  ".....",
  "-....",
  "--...",
  "---..",
  "----."
};
  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  sayCode( decodeCode( Input_msg ) ) ;

}

void loop() {
  // put your main code here, to run repeatedly:

}

String decodeCode(String code){
  String decodedMsg = ""; // fully decoded message
  code.toLowerCase();
  for (int i = 0; i < code.length(); i ++){
    if ( isAlpha( code[ i ] ) ){ // if is a letter
      decodedMsg += alphabet[ int( code[ i ] ) - 97 ];
      continue;
    }
    if (isAlphaNumeric( code[ i ] ) ){ // if is a number
      decodedMsg += numbers[ int( code[ i ] ) ];
    }
  }
  Serial.println( decodedMsg );
  return decodedMsg;
}

void sayCode(String decoded_code){
  for (int i = 0; i < decoded_code.length(); i ++){
    //Serial.println(int(decoded_code[i]));
    if (int(decoded_code[i]) == 46){ // if is .
      Serial.println("LO ");
      tone(pin, 660);
      delay(beat);
      noTone(pin);
    }
    if (int(decoded_code[i]) == 45){ // if is -
      Serial.println("HI ");
      tone(pin, 660);
      delay(beat*3);
      noTone(pin);
    }
    delay(beat);
  }
}
