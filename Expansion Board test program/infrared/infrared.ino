#include <IRremote.h>

/* Pinout Definition */
#define irRxPin 2

/* Infrared */
IRrecv irrecv(irRxPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.write("Hello World\n");
  
  /* Infrared */
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  irReceive();
  delay(1);
}

void irReceive()
{
    if (irrecv.decode()) {
        Serial.print(F("Decoded protocol: "));
        Serial.print(getProtocolString(irrecv.decodedIRData.protocol));
        Serial.print(F("Decoded raw data: "));
        Serial.print(irrecv.decodedIRData.decodedRawData, HEX);
        Serial.print(F(", decoded address: "));
        Serial.print(irrecv.decodedIRData.address, HEX);
        Serial.print(F(", decoded command: "));
        Serial.println(irrecv.decodedIRData.command, HEX);
        IrReceiver.resume();   
    }
}
