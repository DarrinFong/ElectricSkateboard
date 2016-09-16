#include <Servo.h>
Servo MOTOR;

const int pwmOutPin = 3; // PWM output
const int value = A0;
int motorValue = 0;
int pinValue;

void setup()
{
  Serial.begin(9600);
  Serial.println("Demo on");

  pinMode(value, INPUT);
  pinMode(pwmOutPin, OUTPUT);
  MOTOR.attach(pwmOutPin);
}
 
void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  pinValue = analogRead(A0);
  motorValue = map(pinValue, 0, 1023, 0, 180);
  MOTOR.write(motorValue);
  Serial.println(motorValue);
}
