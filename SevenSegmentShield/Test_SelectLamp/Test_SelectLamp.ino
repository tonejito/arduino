/*
 Test_SelectLamp
 Test lamp select circuit with a binary pattern
 
 The circuit:
 L[0:1] => 74LS139 => 74LS04 => LEDs
 
 Created by Andres Hernandez - tonejito
 February 2017
 
 This code is licensed under the BSD license
 */

// Digital outputs to select LED lamp
int L0 = A0;
int L1 = A1;

// Write bits on digital outputs
void selectLamp(int v1,int v0)
{
  digitalWrite(L0,v0);
  digitalWrite(L1,v1);
  delay(1000);
}

void setup()
{
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
}

void loop()
{
  selectLamp( LOW, LOW);
  selectLamp( LOW,HIGH);
  selectLamp(HIGH, LOW);
  selectLamp(HIGH,HIGH);
}

