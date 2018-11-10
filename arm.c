#ifndef ARM_C
#define ARM_C

/*
  ARM.C
  Controls the arm
  Jeffrey Shen
*/

void moveLift(int CMD){
	motor[M_LIFT_1] = CMD * 127;
	motor[M_LIFT_2] = CMD * 127;
}

void moveFlipper(int CMD){
	if(CMD == UP) FLIPPER_COMMAND = HOLD_UP;
	else if(CMD == DOWN) FLIPPER_COMMAND = HOLD_DOWN;

	if(CMD == UP || CMD == DOWN) CMD = CMD * 127;

	motor[M_FLIPPER] = CMD;
}


#endif
