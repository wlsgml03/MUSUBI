// Imports
#include <Arduino.h> // i dont think this is it but erm

// Initializing variables:
//(All of these are taken from jsumo website)

// Line sensors
int lineSensorFront = 16; // front line sensor pin # ANALOG VALUE
int lineSensorBack = 15;   // back line sensor pin # ANALOG VALUE
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
void setup() {
    Serial.begin(9600); // for atual coding, all the serial statements should be taken out
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

void loop() {
   totalRunTime = millis();
    if (digitalRead(startButton) == 1 && !activated) {
        activated = true;
        startTime = millis();
    } else if (activated && digitalRead(startButton) == 0) {
        // Bot was previously activated but start module reads low (stop button pressed)
        activated = false;
    } else {
        Serial.println("Error in the system");
    }
    if (activated == true) {
        sensorValueBack = digitalRead(lineSensorBack);
        sensoralueFront = digitalRead(lineSensorFront);
        leftValue = digitalRead(leftDistance);
        rightValue = digitalRead(rightDistance);
        frontValue = digitalRead(frontDistance);
        backValue = digitalRead(backDistance);
        // goes backwards if it doesnt detect anything
        if (backValue == 0 && frontValue == 0 && leftValue == 0 && rightValue ==0) {
          digitalWrite(leftMotorPin1,0);
          digitalWrite(leftMotorPin2,1);
          digitalWrite(rightMotorPin1,0);
          digitalWrite(RightMotorPin2,1);
        }
        // if line sensor detects value itll stop, delay for 0.25 seconds and then go forwards
        if (sensorValueBack == 0) {
          digitalWrite(leftMotorPin1,0);
          digitalWrite(leftMotorPin2,0);
          digitalWrite(rightMotorPin1,0);
          digitalWrite(rightMotorPin2,0);
          // If they see something from the front 
          if (frontValue == 1) {
          digitalWrite(leftMotorPin1,1);
          digitalWrite(leftMotorPin2,0);
          digitalWrite(rightMotorPin1,1);
          digitalWrite(rightMotorPin2,0);
          }
        }

    }
}
