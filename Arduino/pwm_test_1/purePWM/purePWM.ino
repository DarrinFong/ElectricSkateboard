int pwmPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pwmPin, 100);
}
