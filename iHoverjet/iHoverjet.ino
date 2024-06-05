#include <SoftwareSerial.h>

char Incoming_value;

/* Pinout Definition */
#define RightMotorSpeed 3
#define FrontRightMotorDirection  4
#define LeftMotorSpeed  5
#define RearLeftMotorDirection 6
#define FrontLeftMotorDirection 7
#define RearRightMotorDirection A1
#define bluetoothTx 8
#define bluetoothRx 9

/*bluetooth*/
SoftwareSerial mySerial(bluetoothRx,bluetoothTx); // RX, TX

void setup (){
  Serial.begin(115200);      //Start the serial connetion @ 115200bps
  Serial.write("Hello World\n");
  mySerial.begin(9600);
  Serial.write("Hello World\n");
  pinMode(LeftMotorSpeed,OUTPUT);
  pinMode(RightMotorSpeed,OUTPUT);
  digitalWrite(RearLeftMotorDirection,HIGH) ;   
  digitalWrite(FrontLeftMotorDirection,HIGH) ;
  analogWrite(LeftMotorSpeed,255) ;
  digitalWrite(RearRightMotorDirection,HIGH) ;  
  digitalWrite(FrontRightMotorDirection,HIGH) ; 
  analogWrite(RightMotorSpeed,255) ; 
}

void loop ()
{
  while (Serial.available ()>0) 
  {
     Incoming_value = Serial.read();
  }
  while (mySerial.available ()>0) 
  {
      Incoming_value = mySerial.read();
      Serial.println(Incoming_value);
  }
  if (Incoming_value == '1')
  {
    digitalWrite(RearLeftMotorDirection,HIGH) ;   
    digitalWrite(FrontLeftMotorDirection,HIGH) ;
    analogWrite(LeftMotorSpeed,0) ;
    digitalWrite(RearRightMotorDirection,HIGH) ;  
    digitalWrite(FrontRightMotorDirection,HIGH) ; 
    analogWrite(RightMotorSpeed,0) ; 
  }
  else if (Incoming_value == '2')
  {
    digitalWrite(RearLeftMotorDirection,LOW) ;   
    digitalWrite(FrontLeftMotorDirection,LOW) ;
    analogWrite(LeftMotorSpeed,255) ;
    digitalWrite(RearRightMotorDirection,HIGH) ;  
    digitalWrite(FrontRightMotorDirection,HIGH) ; 
    analogWrite(RightMotorSpeed,0) ; 
  }

  else if (Incoming_value == '3')
  {
    digitalWrite(RearLeftMotorDirection,HIGH) ;   
    digitalWrite(FrontLeftMotorDirection,HIGH) ;
    analogWrite(LeftMotorSpeed,0) ;
    digitalWrite(RearRightMotorDirection,LOW) ;  
    digitalWrite(FrontRightMotorDirection,LOW) ; 
    analogWrite(RightMotorSpeed,255) ; 
  }
  else if (Incoming_value == '4')
  {
    digitalWrite(RearLeftMotorDirection,LOW) ;   
    digitalWrite(FrontLeftMotorDirection,LOW) ;
    analogWrite(LeftMotorSpeed,255) ;
    digitalWrite(RearRightMotorDirection,LOW) ;  
    digitalWrite(FrontRightMotorDirection,LOW) ; 
    analogWrite(RightMotorSpeed,255) ; 
  }
  else if (Incoming_value == '0')
  {
      digitalWrite(RearLeftMotorDirection,HIGH) ;   
      digitalWrite(FrontLeftMotorDirection,HIGH) ;
      analogWrite(LeftMotorSpeed,255) ;
      digitalWrite(RearRightMotorDirection,HIGH) ;  
      digitalWrite(FrontRightMotorDirection,HIGH) ; 
      analogWrite(RightMotorSpeed,255) ; 
  }
}
