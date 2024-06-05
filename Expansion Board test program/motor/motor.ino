/* Pinout Definition */
#define RightMotorSpeed 3
#define FrontRightMotorDirection  4
#define LeftMotorSpeed  5
#define RearLeftMotorDirection 6
#define FrontLeftMotorDirection 7
#define RearRightMotorDirection A1

/* motor */
int motorState = 0;
int motorTimout = 0 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.write("Hello World\n");
  pinMode(LeftMotorSpeed,OUTPUT);
  pinMode(RightMotorSpeed,OUTPUT);
  digitalWrite(RearLeftMotorDirection,HIGH) ;   
  digitalWrite(FrontLeftMotorDirection,HIGH) ;
  analogWrite(LeftMotorSpeed,0) ;
  digitalWrite(RearRightMotorDirection,HIGH) ;  
  digitalWrite(FrontRightMotorDirection,HIGH) ; 
  analogWrite(RightMotorSpeed,0) ; 
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1);
  motor();
}

void motor()
{

  if( 0 != motorTimout)
    {
      motorTimout--;
    }
    else
    {
      motorTimout = 2000;
      switch(motorState)
      {
        case 0:
        {
          Serial.println("Motor Left : Forward Right: Forward");
          digitalWrite(RearLeftMotorDirection,HIGH) ;   
          digitalWrite(FrontLeftMotorDirection,HIGH) ;
          analogWrite(LeftMotorSpeed,0) ;
          digitalWrite(RearRightMotorDirection,HIGH) ;  
          digitalWrite(FrontRightMotorDirection,HIGH) ; 
          analogWrite(RightMotorSpeed,0) ; 
          motorState++;
          break;
        }
        case 1:
        {
          Serial.println("Motor Left : Reverse Right: Forward");
          digitalWrite(RearLeftMotorDirection,LOW) ;   
          digitalWrite(FrontLeftMotorDirection,LOW) ;
          analogWrite(LeftMotorSpeed,255) ;
          digitalWrite(RearRightMotorDirection,HIGH) ;  
          digitalWrite(FrontRightMotorDirection,HIGH) ; 
          analogWrite(RightMotorSpeed,0) ; 
          motorState++;
          break;
        }
        case 2:
        {
          Serial.println("Motor Left : Forward Right: Reverse");
          digitalWrite(RearLeftMotorDirection,HIGH) ;   
          digitalWrite(FrontLeftMotorDirection,HIGH) ;
          analogWrite(LeftMotorSpeed,0) ;
          delay(5);
          digitalWrite(RearRightMotorDirection,LOW) ;  
          digitalWrite(FrontRightMotorDirection,LOW) ; 
          analogWrite(RightMotorSpeed,255) ;
          motorState++;
          break;
        }
        case 3:
        {
          Serial.println("Motor Left : Reverse Right: Reverse");
          digitalWrite(RearLeftMotorDirection,LOW) ;   
          digitalWrite(FrontLeftMotorDirection,LOW) ;
          analogWrite(LeftMotorSpeed,255) ;
          digitalWrite(RearRightMotorDirection,LOW) ;  
          digitalWrite(FrontRightMotorDirection,LOW) ; 
          analogWrite(RightMotorSpeed,255) ;
          motorState++;
          break;
        }
        case 4:
        {
          Serial.println("Motor Left : Reverse Right: Stop");
          digitalWrite(RearLeftMotorDirection,LOW) ;   
          digitalWrite(FrontLeftMotorDirection,LOW) ;
          analogWrite(LeftMotorSpeed,255) ;
          digitalWrite(RearRightMotorDirection,LOW) ;  
          digitalWrite(FrontRightMotorDirection,LOW) ; 
          analogWrite(RightMotorSpeed,0) ;
          motorState++;
          break;
        }
        case 5:
        {
          Serial.println("Motor Left : Stop Right: Reverse");
          digitalWrite(RearLeftMotorDirection,LOW) ;   
          digitalWrite(FrontLeftMotorDirection,LOW) ;
          analogWrite(LeftMotorSpeed,0) ;
          digitalWrite(RearRightMotorDirection,LOW) ;  
          digitalWrite(FrontRightMotorDirection,LOW) ; 
          analogWrite(RightMotorSpeed,255) ;         
          motorState++;
          break;
        }
        case 6:
        {
          Serial.println("Motor Left : Forward Right: Stop");
          digitalWrite(RearLeftMotorDirection,HIGH) ;   
          digitalWrite(FrontLeftMotorDirection,HIGH) ;
          analogWrite(LeftMotorSpeed,0) ;
          digitalWrite(RearRightMotorDirection,LOW) ;  
          digitalWrite(FrontRightMotorDirection,LOW) ; 
          analogWrite(RightMotorSpeed,0) ;         
          motorState++;
          break;
        }
        case 7:
        {
          Serial.println("Motor Left : Stop Right: Forward");
          digitalWrite(RearLeftMotorDirection,HIGH) ;   
          digitalWrite(FrontLeftMotorDirection,HIGH) ;
          analogWrite(LeftMotorSpeed,255) ;
          digitalWrite(RearRightMotorDirection,HIGH) ;  
          digitalWrite(FrontRightMotorDirection,HIGH) ; 
          analogWrite(RightMotorSpeed,0) ;         
          motorState++;
          break;
        }
        default:
        {
          motorTimout = 0;
          motorState  = 0;
          break;
        }
      }
    }
}
