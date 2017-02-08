/*
 LM35DT temperature meter
 Reads temperature from a LM35DT, display output on leds and write the value it via serial
 
 The circuit:
 + LM35DT - OUTPUT on A6
 + LM35DT - GND on A7 (bridged to common GND)
 + LM35DT - INPUT on +5V
 + White LED (+) on D08
 + Blue LED (+) on D09
 + Green LED (+) on D10
 + Yellow LED (+) on D11
 + Red LED (+) on D12
 + All leds connected to GND via a 330 ohm resistor
 * Arduino LED pin 13 is used for heartbeat

 Created by Andres Hernandez - tonejito
 January 2017
 
 This code is licensed under the BSD license
 
 */

int sensorGND = A7; // LM35 GND
int sensorPin = A6; // LM35 OUT
int L = 13;         // Arduino L PIN
int R = 12;         // Red LED
int Y = 11;         // Yellow LED
int G = 10;         // Green LED
int B =  9;         // Blue LED
int W =  8;         // White LED
int ledGND = 7;

float mv = 0.0;     // milliVolts read
float C = 0.0;      // Centigrade degrees

void setup()
{
  // initialize serial communication:
  Serial.begin(115200);
  // Set digital pins as output
  pinMode(sensorGND, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(W, OUTPUT);
  pinMode(ledGND, OUTPUT);
}

void loop()
{
  // Lock the sensor GND pin to ground
  digitalWrite(sensorGND, LOW);
  digitalWrite(ledGND, LOW);
  
  // Read data from the sensor
  mv = ( analogRead(sensorPin) / 1024.0 ) * 5000;
  C = mv / 10;

  // Write the temperature via serial
  Serial.print("C: ");
  Serial.println(C);

  // Give heartbeat feedback
  digitalWrite(L, HIGH);
  delay(mv);
  digitalWrite(L, LOW);
  delay(1000-mv);

  // Display output on the leds
  if (C > 0.0) // Cold
    digitalWrite(W, HIGH);
  else
    digitalWrite(W, LOW);

  if (C > 15.0) // Cool
    digitalWrite(B, HIGH);
  else
    digitalWrite(B, LOW);

  if (C > 25.0) // Normal
    digitalWrite(G, HIGH);
  else
    digitalWrite(G, LOW);
  
  if (C > 27.5) // Warm
    digitalWrite(Y, HIGH);
  else
    digitalWrite(Y, LOW);
  
  if (C > 30.0) // Hot
    digitalWrite(R, HIGH);
  else
    digitalWrite(R, LOW);
}

