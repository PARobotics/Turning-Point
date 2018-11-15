#ifndef MAIN_H
#define MAIN_H

/*
  MAIN.H
  Holds various variables and wrapper functions
  Jeffrey Shen
*/

int FLIPPER_COMMAND = 0;
#define HOLD_UP 10
#define HOLD_DOWN 11

// ** Wrapper functions **
//Intake
void intakeUp();
void intakeDown();
void intakeStop();

//Catapult
bool catapultInPosition();
void moveCatapult(int CMD);
void lowerCatapultToIntake();
void fireCatapult();

#endif
