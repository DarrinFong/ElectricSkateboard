
#include <Servo.h>

const int potPin = A0; // potentiometer
const int pwmOutPin = 3; // PWM output

int potentiometerValue; //range from 0 to 1023
int pwmValue; //range from 0 to 255
int speedPercentage; //range from 0 to 100
int motorValue;

Servo myMotor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Serial Monitor Ctrl + Shift + m

  pinMode(potPin, INPUT);
  pinMode(pwmOutPin, OUTPUT);
  myMotor.attach(pwmOutPin);
}

void loop() {

  
  // put your main code here, to run repeatedly:
  potentiometerValue = analogRead(potPin);

  //pwmValue = (potentiometerValue/4);
  pwmValue = map(potentiometerValue, 0,1023, 0, 255);
  speedPercentage = (int) (potentiometerValue/1023.0*100);
  motorValue = map(pwmValue,0,255,0,180);
  
  //analogWrite(pwmOutPin, pwmValue);
  myMotor.write(motorValue);
  
  Serial.print(potentiometerValue);
  Serial.print("\t");
  Serial.print(pwmValue);
  Serial.print("\t");
  Serial.print(speedPercentage);
  Serial.print("\t");
  Serial.print(motorValue);
  Serial.println();
  
}
