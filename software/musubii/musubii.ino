#include <Arduino.h>

// Definitions!
#define Line_B 17
#define Line_F 6
#define Dist_L 8
#define Dist_FL 7 
#define Dist_FR 2
#define Dist_R 5
#define MotorDriver_L1 9
#define MotorDriver_L2 10
#define MotorDriver_R1 18
#define MotorDriver_R2 19
#define StartModule 16
int leftLine;
int rightLine;
void hoe_move_forward();
unsigned long startTime = 0;
unsigned long runTime = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Line_B, OUTPUT);
pinMode(Line_F, INPUT);
pinMode(Dist_FR, INPUT);
pinMode(Dist_FL, INPUT);
pinMode(Dist_L, INPUT);
pinMode(Dist_R, INPUT);
pinMode(MotorDriver_L1, OUTPUT);
pinMode(MotorDriver_L2, OUTPUT);
pinMode(MotorDriver_R1, OUTPUT);
pinMode(MotorDriver_R2, OUTPUT);
pinMode(StartModule, INPUT);
} // setup

void loop() {
  leftLine= digitalRead(Line_F);
  rightLine= digitalRead(Line_B);
// if (digitalRead(StartModule) == 1) {
//   hoe_move_forward();
// } else if (digitalRead(StartModule) == 0) {
//   hoe_stop();
// }
Serial.println("Left Line sensor reads:");
Serial.println(leftLine);
Serial.println("Right Line sensor reads:");
Serial.println(rightLine);
delay(5000);

// r1 useless
//Serial.println("HI Kyle :3");
//delay(5000);
} // loop

// Movement functions!
// 01 -> forward
// 10 -> backwards
// 00 -> no movement
// 11 -> brake
// This is ignoring rotation. I (Kyle) will wire it so these combinations actually work like the guide above says.
void hoe_to_the_left() {
  // turn left
  digitalWrite(MotorDriver_L1, 1);
  digitalWrite(MotorDriver_L2, 0);
  digitalWrite(MotorDriver_R1, 1);
  digitalWrite(MotorDriver_R2, 0);
} // hoe_to_the_left

void hoe_to_the_right() {
  // turn right
  digitalWrite(MotorDriver_L1, 0);
  digitalWrite(MotorDriver_L2, 1);
  digitalWrite(MotorDriver_R1, 0);
  digitalWrite(MotorDriver_R2, 1);
} // hoe_to_the_right

void hoe_move_forward() {
  // move forward
  digitalWrite(MotorDriver_R1,0);
  digitalWrite(MotorDriver_R2,1);
  digitalWrite(MotorDriver_L2,1);
  digitalWrite(MotorDriver_L1,0);
} // hoe_move_forward

void hoe_move_backwards() {
  // move backwards
  digitalWrite(MotorDriver_R1,1);
  digitalWrite(MotorDriver_R2,0);
  digitalWrite(MotorDriver_L2,0);
  digitalWrite(MotorDriver_L1,1);
} // hoe_move_backwards

void hoe_stop() {
  // brake
  digitalWrite(MotorDriver_L1, 1);
  digitalWrite(MotorDriver_L2, 1);
  digitalWrite(MotorDriver_R1, 1);
  digitalWrite(MotorDriver_R2, 1);
} // hoe_stop

/*
Ojousama
It's time to go to bed
Tto haendeupon haneun geoyeyo
Neutge jamyeon
Goun pibu ga da muneojinda guyo
Saigo no keikoku desu
Jigeum jame deulji anmyeon
Urin chum eul chul geoyeyo
Yare, yare
Mot malrineun agassi
Yare, yare
Mot malrineun agassi
Yare, yare
Mot malrineun agassi
Tto-tto-tto-tto-tto-tto-tto
Tto haendeupon haneun geoyeyo
Ti-ti-ti-ti-ti-ti
Time to go to bed
Go, go, go, go, go, go
Goun pibu ga da muneojinda guyo
Ya-ya-ya-ya-ya-ya
Yare yare, mot malrineun agassi
*/
