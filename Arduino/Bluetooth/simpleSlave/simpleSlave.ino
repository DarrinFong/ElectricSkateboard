#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX
const int potPin = A0; // potentiometer
const int pwmOutPin = 3; // PWM output

int potentiometerValue; //range from 0 to 1023
int pwmValue; //range from 0 to 255
int speedPercentage; //range from 0 to 100
int motorValue;
char masterValue; // value from remote
int speedVal;

char state = '';
void setup() 
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
 
  // HC-06 default baud rate is 9600
  BTSerial.begin(9600);

  pinMode(potPin, INPUT);
  pinMode(pwmOutPin, OUTPUT);
  myMotor.attach(pwmOutPin);
  speedVal = 0;
}
 
void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTSerial.available()){
    state = BTSerial.read();
    Serial.write(state);
  }
  
 /*
  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available()){
    BTSerial.write(Serial.read());
  }*/
  
  potentiometerValue = analogRead(potPin);

  pwmValue = map(potentiometerValue, 0,1023, 0, 255);
  speedPercentage = (int) (potentiometerValue/1023.0*100);
  motorValue = map(pwmValue,0,255,0,180);
  
  myMotor.write(motorValue);
  
  Serial.print(potentiometerValue);
  Serial.print("\t");
  Serial.print(pwmValue);
  Serial.print("\t");
  Serial.print(speedPercentage);
  Serial.print("\t");
  Serial.print(motorValue);
  Serial.println();

  if(masterValue == 'b') myMotor.write(0);
  else if(masterValue == 'c'); // do nothing, motor value stays the same
  else if(masterValue == 'a'){speedVal += 10 ;myMotor.write(speedVal); }
    else{/* something went very wrong*/}
  }

  
}
