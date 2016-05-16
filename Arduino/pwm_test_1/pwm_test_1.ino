const int potPin = A0;//potentiometer
const int but1 = 3, but2 = 4, but3 = 5; //button
const int led1 = 11, led2 = 10, led3 = 9; //led
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  pinMode(potPin, INPUT);

  Serial.begin(9600); // Serial Monitor Ctrl + Shift + m
}

void loop() {
  // put your main code here, to run repeatedly:
  int but3_read = digitalRead(but3);
  int but2_read = digitalRead(but2);
  int but1_read = digitalRead(but1);  
  
  if(but3_read == HIGH){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    Serial.println("Brake");
  }
  else if(but2_read == HIGH){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(sqrt(potValue*25));
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(sqrt(potValue*25));
    Serial.println("Cruise");
  }
  else if(but1_read == HIGH){
    potValue = analogRead(potPin);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(sqrt(potValue*25));
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(sqrt(potValue*25));
    Serial.println("Accelerate");
  }
}
