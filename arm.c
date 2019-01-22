#ifndef ARM_C
#define ARM_C

/*
  ARM.C
  Controls the arm
  Jeffrey Shen
*/

void moveLift(int CMD){
	if(CMD == UP) LIFT_COMMAND = HOLD_UP;
	else if(CMD == DOWN) LIFT_COMMAND = HOLD_DOWN;

	if(CMD == UP) CMD = CMD * 127;
	else if(CMD == DOWN) CMD = CMD * 70;

	motorReq[M_LIFT] = CMD;
}

void moveFlipper(int CMD){
	if(CMD == UP) FLIPPER_COMMAND = HOLD_UP;
	else if(CMD == DOWN) FLIPPER_COMMAND = HOLD_DOWN;

	if(CMD == UP || CMD == DOWN) CMD = CMD * 127;

	motorReq[M_FLIPPER] = CMD;
}


#endif
