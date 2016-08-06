// Basic Bluetooth sketch HC-05_AT_MODE_01
// Connect the HC-05 module and communicate using the serial monitor
//
// The HC-05 defaults to commincation mode when first powered on you will need to manually enter AT mode
// The default baud rate for AT mode is 38400
// See www.martyncurrey.com for details
//
 
#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
 
char c = ' ';
const int acc = 8;
const int cru = 10;
const int brk = 12;

void setup(){
    pinMode(acc, INPUT);
    pinMode(cru, INPUT);
    pinMode(brk, INPUT);
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    
    // HC-05 default serial speed for AT mode is 38400
    BTserial.begin(9600);
}

void loop(){
    delay(100);
    if (digitalRead(8) == HIGH){
      BTserial.write('a');
      Serial.println("accl");
    }
    else if(digitalRead(9) == HIGH){
      BTserial.write('c');
      Serial.println("cruz");
    }
    else if(digitalRead(10) == HIGH){
      BTserial.write('b');
      Serial.println("brke");
    }
    else{
      BTserial.write('n');
      Serial.println("norm");
    }
}
