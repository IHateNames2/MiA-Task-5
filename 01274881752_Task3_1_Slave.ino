#include <Wire.h>
#define LED 7

// Slave code

void setup()
{
  Wire.begin(1); //argument defines this arduino as Slave #1
  Wire.onReceive(receiveEvent);
  
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  delay(500);
}

void receiveEvent(int howMany) {
  int B1_State = Wire.read(); //reads the value of B1_State from the Master
  int B2_State = Wire.read(); //reads the value of B2_State from the Master
  
  if (B1_State == LOW && B2_State == LOW) {
    analogWrite(LED, 0);
    Serial.println("");
  } else if (B1_State == HIGH && B2_State == LOW) {
    analogWrite(LED, 127);
    Serial.println("Vector focused");
  } else if (B1_State == LOW && B2_State == HIGH) {
    analogWrite(LED, 191);
    Serial.println("Vector distracted");
  } else if (B1_State == HIGH && B2_State == HIGH) {
    analogWrite(LED, 255);
    Serial.println("Glitch");
  }
}