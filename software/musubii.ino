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
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
