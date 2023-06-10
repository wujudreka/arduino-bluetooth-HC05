#include <SoftwareSerial.h>

#define rxPin 15
#define txPin 16

// Set up a new SoftwareSerial object
/* 
 *  F - Forward
 *  B - backward
 *  R - right
 *  L - left
 *  w - turn off front lamp
 *  W - tunr on front lamp
 *  u - turn off back lamp
 *  U - turn on back lamp
 *  v - turn off horn
 *  V - turn on horn
 *  x - turn off hazard
 *  X - turn on hazard
 */
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
char inputValue;

void setup()  {
    // Define pin modes for TX and RX
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    Serial.begin(9600);
    // Set the baud rate for the SoftwareSerial object
    mySerial.begin(9600);
}

void loop() {
    if (mySerial.available() > 0) {
      inputValue = mySerial.read();
      if(inputValue == 'F'){
        Serial.println("forward");
      }else if(inputValue == 'B'){
        Serial.println("backward");
      }else if(inputValue == 'R'){
        Serial.println("turnRight");
      }else if(inputValue == 'L'){
        Serial.println("turnLeft");
      }else if(inputValue == 'S'){
        Serial.println("stopMotor");
      }else{
        Serial.println(inputValue);
      }
    }
    if (Serial.available() > 0) {
      mySerial.write(Serial.read());
    }
}
