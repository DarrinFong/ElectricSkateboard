#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BTserial(6, 7); // RX | TX
// Connect the HC-05 TX to Arduino pin 6 RX. 
// Connect the HC-05 RX to Arduino pin 7 TX through a voltage divider.
 
char c = ' ';
const int acc = 8;
const int cru = 10;
const int brk = 12;
int speed = 0;

void setup(){
    Serial.begin(9600);
    pinMode(acc, INPUT);
    pinMode(cru, INPUT);
    pinMode(brk, INPUT);
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    
    // HC-05 default serial speed for AT mode is 38400
    BTserial.begin(9600);
}

void loop(){
    delay(100);
    if (digitalRead(8) == HIGH){
      BTserial.write('a');
      if(speed < 100)
      speed++;
    }
    else if(digitalRead(9) == HIGH){
      BTserial.write('c');
    }
    else if(digitalRead(10) == HIGH){
      BTserial.write('b');
      speed = 0;
    }
    else{
      BTserial.write('n');
      if(speed > 0)
      speed--;
    }
    Serial.println(speed);
}
