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
// 
 
char c = ' ';
const int accelerate = 8;
const int cruise = 9;
const int brk = 10;

int valAcc = 0;
int valcrz = 0;
int valBrk = 0;

void setup(){
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    Serial.println("Remember to select Both NL & CR in the serial monitor");
 
    // HC-05 default serial speed for AT mode is 38400
    BTserial.begin(9600);
    pinMode(accelerate, INPUT);
    pinMode(cruise, INPUT);
    pinMode(brk, INPUT);
}
 
void loop(){
    valAcc = digitalRead(accelerate);
    valcrz = digitalRead(cruise);
    valBrk = digitalRead(brk);
    
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available()){  
        c = BTserial.read();
        Serial.write(c);
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available()){
        c =  Serial.read();
        BTserial.write(c);
        if (valBrk == "HIGH") BTserial.write('b');  
        else if(valcrz == "HIGH")BTserial.write('c');
        else if(valAcc)BTserial.write('a');
        else BTserial.write('n');
           
        
    }
}
