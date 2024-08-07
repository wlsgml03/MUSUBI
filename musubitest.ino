// Imports
#include <Arduino.h> // i dont think this is it but erm
// Initializing variables:
//(All of these are taken from jsumo website)

// Line sensors
int lineSensorFront = 16;
int lineSensorBack = 15;  
int sensorValueFront;
int sensorValueBack;

// Distance sensors

int frontDistance = 40; // front sensor conntected to D#
int frontValue;         // storing front sensor output
int leftDistance = 18;  // left sensor connected to D#
int leftValue;          // storing left sensor output
int rightDistance = 17; // right sensor connected to D#
int rightValue;         // storing right sensor output
int backDistance = 41;  // back sensor connected to D#
int backValue;          // storing back sensor output

// Motors "Pin numbers"
int leftMotorPin1 = 22;
int leftMotorPin2 = 21;

int rightMotorPin1 = 20;
int rightMotorPin2 = 19;

// Start Button
int startButton = 38;
bool activated = false;

// threshold (values from testing)
int thresholdBottomVal;
int thresholdTopVal;

/* Setup function that runs when robot first starts up
Setting up pins, is it input or output?*/

void setup()
{
    Serial.begin(9600); // for atual coding, all the serial statements should be taken out
    Serial.println("Beginning testing...");
    pinMode(lineSensorFront, INPUT);
    pinMode(lineSensorBack, INPUT);
    pinMode(frontDistance, INPUT);
    pinMode(leftDistance, INPUT);
    pinMode(backDistance, INPUT);
    pinMode(rightDistance, INPUT);
    pinMode(startButton, INPUT);
    pinMode(leftMotorPin1, OUTPUT);
    pinMode(leftMotorPin2, OUTPUT);
    pinMode(rightMotorPin1, OUTPUT);
    pinMode(rightMotorPin2, OUTPUT);
}
// pin mode , pinMode(pin itself, OUTPUT), --> direction digitalWrite(front pin,)
// MD1MD2 = 00 = stop
// 01 = forward
// 10 = back
// 11 = nothing

void loop() {
  frontValue = digitalRead(frontDistance);
  backValue = digitalRead(backDistance);
  leftValue = digitalRead(leftDistance);
  rightValue = digitalRead(rightDistance);
  sensorValueFront = digitalRead(lineSensorFront);
    Serial.println(sensorValueFront);
    delay(1000);
  Serial.println("Left Motor is turning on!");
  Serial.println("Right motor is turning on!");
  digitalWrite(rightMotorPin1,1);
  digitalWrite(rightMotorPin2,0);
  digitalWrite(leftMotorPin1,0);
  digitalWrite(leftMotorPin2,1);
}
// int leftMotorPin1 = 22;
// int leftMotorPin2 = 21;

// int rightMotorPin1 = 20;
// int rightMotorPin2 = 19;
// int frontDistance = 40; // front sensor conntected to D#
// int frontValue;         // storing front sensor output
// int leftDistance = 18;  // left sensor connected to D#
// int leftValue;          // storing left sensor output
// int rightDistance = 17; // right sensor connected to D#
// int rightValue;         // storing right sensor output
// int backDistance = 41;  // back sensor connected to D#
// int backValue;  
