#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial BTSerial(2, 3); // RX | TX
Servo MOTOR;
const int potPin = A0; // potentiometer
const int pwmOutPin = 3; // PWM output
int potentiometerValue; //range from 0 to 1023
int pwmValue; //range from 0 to 255
int speedPercentage; //range from 0 to 100
int motorValue; 
int speedVal;
char masterValue; // value from remote

char state = ' ';
void setup() 
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
 
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
    state = BTSerial.read();
    Serial.println(state);
  }  
  potentiometerValue = analogRead(potPin);

  pwmValue = map(potentiometerValue, 0,1023, 0, 255);
  speedPercentage = (int) (potentiometerValue/1023.0*100);
  motorValue = map(pwmValue,0,255,0,180);
  
  MOTOR.write(motorValue);

  if(masterValue == 'b'){ //hard break
    motorValue = 0;
  }
  else if(masterValue == 'c'){ //cruise, constant speed
  }
  else if(masterValue == 'a'){ //accelerate
    motorValue += 10 ;
  }
  else if(masterValue == 'n'){ //normal state, softbreak (regeneration to be implemented)
    
  }
}
