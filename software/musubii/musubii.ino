#include <Arduino.h>

// Definitions!
#define Line_B 22
#define Line_F 9
#define Dist_F 5
#define Dist_B 10 
#define Dist_L 11
#define Dist_R 8
#define MotorDriver_L1 12
#define MotorDriver_L2 13
#define MotorDriver_R1 24
#define MotorDriver_R2 23
#define StartModule 21

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Line_B, INPUT);
pinMode(Line_F, INPUT);
pinMode(Dist_F, INPUT);
pinMode(Dist_B, INPUT);
pinMode(Dist_L, INPUT);
pinMode(Dist_R, INPUT);
pinMode(MotorDriver_L1, OUTPUT);
pinMode(MotorDriver_L2, OUTPUT);
pinMode(MotorDriver_R1, OUTPUT);
pinMode(MotorDriver_R2, OUTPUT);
pinMode(StartModule, INPUT);
} // setup

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(Dist_L));
} // loop

// Movement functions!
// 01 -> forward
// 10 -> backwards
// 00 -> no movement
// 11 -> brake
// This is ignoring rotation. I (Kyle) will wire it so these combinations actually work like the guide above says.
void hoe_to_the_left() {
  // turn left
  digitalWrite(MotorDriver_L1, 0);
  digitalWrite(MotorDriver_L2, 1);
  digitalWrite(MotorDriver_R1, 1);
  digitalWrite(MotorDriver_R2, 0);
} // hoe_to_the_left

void hoe_to_the_right() {
  // turn right
  digitalWrite(MotorDriver_L1, 1);
  digitalWrite(MotorDriver_L2, 0);
  digitalWrite(MotorDriver_R1, 0);
  digitalWrite(MotorDriver_R2, 1);
} // hoe_to_the_right

void hoe_move_forward() {
  // move forward
  digitalWrite(MotorDriver_L1, 0);
  digitalWrite(MotorDriver_L2, 1);
  digitalWrite(MotorDriver_R1, 0);
  digitalWrite(MotorDriver_R2, 1);
} // hoe_move_forward

void hoe_move_backwards() {
  // move backwards
  digitalWrite(MotorDriver_L1, 1);
  digitalWrite(MotorDriver_L2, 0);
  digitalWrite(MotorDriver_R1, 1);
  digitalWrite(MotorDriver_R2, 0);
} // hoe_move_backwards

void hoe_stop() {
  // brake
  digitalWrite(MotorDriver_L1, 1);
  digitalWrite(MotorDriver_L2, 1);
  digitalWrite(MotorDriver_R1, 1);
  digitalWrite(MotorDriver_R2, 1);
} // hoe_stop
