#ifndef BAT_C
#define BAT_C

/*
  BAT.C
  Controls the ball-shooting bat
  Jeffrey Shen
*/

//Intake
void intakeUp(){
	motor[M_INTAKE] = 127;
}

void intakeDown(){
	motor[M_INTAKE] = -127;
}

void intakeStop(){
	motor[M_INTAKE] = 0;
}

//Catapult
void moveCatapult(int CMD){
	motor[M_CATAPULT_1] = CMD * 127;
	motor[M_CATAPULT_2] = CMD * 127;
}


#endif
