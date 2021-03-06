//slave code 
#include <SoftwareSerial.h> //Software Serial Port
#define RxD 6
#define TxD 7
SoftwareSerial blueToothSerial(RxD,TxD);
void setup(){
  Serial.begin(9600);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  setupBlueToothConnection();
}
void loop()
{
  char recvChar;
  while(1){
    if(blueToothSerial.available()){
         //check if there's any
        //data sent from the remote bluetooth shield
        recvChar = blueToothSerial.read();
      Serial.print(recvChar);
    }
    if(Serial.available()){//check if there's any data sent

      recvChar = Serial.read();
      blueToothSerial.print(recvChar);
    }
  }
}
void setupBlueToothConnection(){
  blueToothSerial.begin(38400); //Set BluetoothBee BaudRate to default baud rate 38400
  blueToothSerial.print("\r\n+STWMOD=0\r\n"); //set the bluetooth work in slave mode
  blueToothSerial.print("\r\n+STNA=SeeedBTSlave\r\n"); //set the bluetooth name as "SeeedBTSlave" Future Electronics Egypt Ltd. (Arduino Egypt).
  blueToothSerial.print("\r\n+STPIN=0000\r\n");//Set SLAVE pincode"0000"
  blueToothSerial.print("\r\n+STOAUT=1\r\n"); // Permit Paired device to connect me
  blueToothSerial.print("\r\n+STAUTO=0\r\n"); // Autoconnection
  //should be forbidden here
  delay(2000); // This delay is required.
  blueToothSerial.print("\r\n+INQ=1\r\n"); //make the slave bluetooth inquirable
  Serial.println("The slave bluetooth is inquirable!");
  delay(2000); // This delay is required.
  blueToothSerial.flush();
}
