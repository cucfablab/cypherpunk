# CryptoClass
Physical Analogies for Combinatorics and Brute Force Code Breaking

## How to manufacture the keys

Use `4x6keys_2kinds.png` as a 4" x 6" input file for the modela milling machine. Cut the PCB.

![Black and White cut out file for keys](https://raw.githubusercontent.com/jazzyjackson/CryptoClass/master/4x6keys_2kinds.png)

Use normal, straight on both sides, headers. 
For each key you need a 1x7 and a 1x8 pin strip. The 8 long one goes closer to the head of the key, and the 7 closer to the tip. 
Use pliers to pull out the pins you don’t want grounded. 

Put the jumpers in the arduino as a jig to get the spacing right:
- Set the key in place.
- put a binder clip over the key so it clips to the headers.
- With the binder clip off to one side you start soldering, take the binder clip off after a couple joints.

![A sketch of how to binder clip the key to headers for soldering](https://github.com/jazzyjackson/CryptoClass/blob/master/keybinderclipsketch.PNG)

To finish it, after the key is cool, place a strip of copper tape over all the solder joints. Right up against the header plastic, and wrap any extra around the top. This covers the silver solder (both for looks and for no-poison). Once the tape tarnishes a little it’ll blend in with the rest of the copper PCB really well!

![Finished Keys](https://github.com/jazzyjackson/CryptoClass/blob/master/finishedkeys.PNG)

Now you can swap these keys out of the Arduino to unlock the programs.

![A key in an arduino](https://github.com/jazzyjackson/CryptoClass/blob/master/keyarduino.PNG)
