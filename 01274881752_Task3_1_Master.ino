#include <Wire.h>
#define B1 A0
#define B2 A1

//Master code

void setup()
{
  Wire.begin(); //empty argument defines this arduino as the Master
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
}

void loop()
{
  int B1_State = digitalRead(B1);
  int B2_State = digitalRead(B2);
  
  Wire.beginTransmission(1); //sends code to slave arduino defined with Wire.begin(1)
  Wire.write(B1_State);
  Wire.write(B2_State);
  Wire.endTransmission(); //ends code transmission
}