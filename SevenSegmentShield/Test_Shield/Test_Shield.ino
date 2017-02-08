/*
 Test_WriteDigit
 Test digit write to 7 segment decoder
 
 The circuit:
 L[0:1] => 74LS139 => 74LS04 => LEDs
 D[0:3] => 74LS47  => 7 Segment Display (Common Anode)
 DP     => 74LS04  => 7 Segment Display (Common Anode)
 
 Created by Andres Hernandez - tonejito
 February 2017
 
 This code is licensed under the BSD license
 */

// Digital outputs to select LED lamp
int L0 = A0;
int L1 = A1;
// Digital outputs for BCD decoder
int D0 = 2;
int D1 = 3;
int D2 = 4;
int D3 = 5;
// Decimal point output
int P0 = A2;
// Decimal point value
int DP = LOW;

// Write bits on digital outputs
void selectLamp(int v1,int v0)
{
  digitalWrite(L0,v0);
  digitalWrite(L1,v1);
  delay(10);
}

// Write bits to digital outputs
void writeDigit(int v3,int v2,int v1,int v0)
{

  digitalWrite(D0,v0);
  digitalWrite(D1,v1);
  digitalWrite(D2,v2);
  digitalWrite(D3,v3);
  (DP == LOW) ? DP = HIGH : DP = LOW;
  digitalWrite(P0,DP);
  delay(500);
}

void testDisplay()
{
  writeDigit( LOW, LOW, LOW, LOW); // 0
  writeDigit( LOW, LOW, LOW,HIGH); // 1
  writeDigit( LOW, LOW,HIGH, LOW); // 2
  writeDigit( LOW, LOW,HIGH,HIGH); // 3
  writeDigit( LOW,HIGH, LOW, LOW); // 4
  writeDigit( LOW,HIGH, LOW,HIGH); // 5
  writeDigit( LOW,HIGH,HIGH, LOW); // 6
  writeDigit( LOW,HIGH,HIGH,HIGH); // 7
  writeDigit(HIGH, LOW, LOW, LOW); // 8
  writeDigit(HIGH, LOW, LOW,HIGH); // 9
/* Values outside BCD range */
/*
  writeDigit(HIGH, LOW,HIGH, LOW); // A
  writeDigit(HIGH, LOW,HIGH,HIGH); // B
  writeDigit(HIGH,HIGH, LOW, LOW); // C
  writeDigit(HIGH,HIGH, LOW,HIGH); // D
  writeDigit(HIGH,HIGH,HIGH, LOW); // E
  writeDigit(HIGH,HIGH,HIGH,HIGH); // F
*/
}

void setup()
{
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(P0, OUTPUT);
}

void loop()
{
  selectLamp( LOW, LOW);
  testDisplay();
  selectLamp( LOW,HIGH);
  testDisplay();
  selectLamp(HIGH, LOW);
  testDisplay();
  selectLamp(HIGH,HIGH);
  testDisplay();
}

