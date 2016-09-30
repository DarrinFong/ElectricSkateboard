#include <SoftwareSerial.h>
#include <Servo.h>
Servo MOTOR;
SoftwareSerial BTSerial(2, 3); // RX | TX
const int pwmOutPin = 7; // PWM output
int speedPercentage = 40; //range from 0 to 100
int motorValue;
char masterValue; // value from remote

char state = ' ';
void setup() 
{ 
  // HC-06 default baud rate is 9600
  BTSerial.begin(9600);

  pinMode(pwmOutPin, OUTPUT);
  MOTOR.attach(pwmOutPin);
}
 
void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTSerial.available()){
    masterValue = BTSerial.read();
    
    switch(masterValue){
    case 'b':
      speedPercentage = 40; //hard break
      break;
    case 'c':
      // cruise
      break;
    case 'a':
      if(speedPercentage < 100){
        speedPercentage++; //accelerate
      }
      break;
    case 'n':
      if(speedPercentage > 40){
        speedPercentage--; //softbreak
      }
      break;
    }
  }
  
  motorValue = map(speedPercentage,0,100,0,180);
  MOTOR.write(motorValue);
}
