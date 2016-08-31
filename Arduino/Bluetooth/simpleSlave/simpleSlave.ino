#include <SoftwareSerial.h>
#include <Servo.h>
Servo MOTOR;
SoftwareSerial BTSerial(2, 3); // RX | TX
const int pwmOutPin = 3; // PWM output
int speedPercentage = 0; //range from 0 to 100
int motorValue;
int speedVal;
char masterValue; // value from remote

char state = ' ';
void setup() 
{
  Serial.begin(9600);
  Serial.println("Slave on");
 
  // HC-06 default baud rate is 9600
  BTSerial.begin(9600);

  pinMode(potPin, INPUT);
  pinMode(pwmOutPin, OUTPUT);
  MOTOR.attach(pwmOutPin);
  speedVal = 0;
}
 
void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTSerial.available()){
    masterValue = BTSerial.read();
    Serial.println(masterValue);
    
    switch(masterValue){
    case 'b':
      speedPercentage = 0; //hard break
      break;
    case 'c':
      // cruise
      break;
    case 'a':
      speedPercentage += 1; //accelerate
      break;
    case 'n':
      speedPercentage -= 1; //softbreak
      break;
    }
  }
  
  motorValue = map(speedPercentage,0,255,0,180);
  MOTOR.write(motorValue);
}
