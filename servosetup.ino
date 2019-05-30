/* Sweep -- 
 *  Setup code Use this to setup servos in cryptology exploration
 *  CUCFabLab
 *  Virginia McCreary, with Colten, Claire, and all the wonderful folk 2016
 *  
 from BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position

void setup() {
  myservo.attach(A0);  // attaches the servo on pin 9 to the servo object
}

void loop() {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
}
