/* Pinout Definition */
#define batteryVoltagePin A0

/* adcVoltage*/
int adcTimeout = 3000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.write("Hello World\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1);
  adcVoltage();
}

void adcVoltage(){
  if( 0 != adcTimeout)
  {
    adcTimeout--;
  }
  else
  {
    adcTimeout = 3000;
    float voltage = analogRead(batteryVoltagePin);
    Serial.print("voltage : ");
    Serial.print((voltage/100));     
    Serial.println("v");
  }
}
