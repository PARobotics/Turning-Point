#ifndef CONFIG_C
#define CONFIG_C

/*
  CONFIG.C
  Configuration variables for the parallax library
  Jeffrey Shen
*/

//Configure preauton
void preAutonProcedure(){
  //This code runs during preauton
}

void userControlProcedure(){
  //This code executes inside the user control while loop
}

//Set up push release buttons
#define USE_PR_BUTTON  1
#define NUM_PR_BUTTONS  1
#define BTN_7L 0

void setUpButtons(){ //Only include if using remote
	addPrButton(BTN_7L, Btn7L);
}

//Configure Sensors
#define USE_SECOND_BATTERY 1
#define USE_LCD 1

void lcdGenerateMessage(){
  sprintf(lcdStr1, "8900 %4.1fV %4.1fV", getMainBatteryVoltage() / 1000.0, getSecondBatteryVoltage() / 1000.0);
  sprintf(lcdStr2, "%d %d", SensorValue(S_TOP_SONAR), SensorValue(S_LOW_SONAR));
}

/*
  MOTOR CONTROL
*/

//Slew Rate
#define USE_SLEW  1 //Disable if slew interferes with move functions or slows robot down
int MOTOR_SLEW[MOTOR_NUM] = {255, 255, 40, 40, 40, 40, 255, 255, 255, 255};

#define USE_MOVE 1

/*
  DEBUGGING TOGGLES
*/

#define DEBUG_SLEW  0
#define DEBUG_MOVE 0
#define DEBUG_REMOTE 0

#define BAILOUT_BUTTON Btn7R
void bailOut(){
	FLIPPER_COMMAND = STOP;
	CATAPULT_COMMAND = STOP;
	LIFT_COMMAND = STOP;
}

void move(int V, int H, int X){
  motorReq[M_WHEEL_L1] = BOUND(V + H, -127, 127);
  motorReq[M_WHEEL_L2] = BOUND(V + H, -127, 127);
  motorReq[M_WHEEL_L3] = BOUND(V + H, -127, 127);
  motorReq[M_WHEEL_R1] = BOUND(V - H, -127, 127);
  motorReq[M_WHEEL_R2] = BOUND(V - H, -127, 127);
  motorReq[M_WHEEL_R3] = BOUND(V - H, -127, 127);
}

#endif
