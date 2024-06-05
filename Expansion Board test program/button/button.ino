/* Pinout Definition */
#define btnPin A2

/* button */
bool bButton = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(btnPin, INPUT);
  Serial.begin(9600);

  bButton = digitalRead(btnPin);
  if (0 == bButton) {
    Serial.println("Button is pressed");
  } else {
    Serial.println("Button is released");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 delay(1);
 button();
}

void button(){
  if (bButton != digitalRead(btnPin)) {
    bButton = digitalRead(btnPin);
    if (0 == bButton) {
      Serial.println("Button is pressed");
    } else {
      Serial.println("Button is released");
    }
  }
}