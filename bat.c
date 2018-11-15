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
bool catapultInPosition(){ //Is the catapult in the proper position for loading and shooting
	return SensorValue(S_TOP_SONAR) < 5;
}

void moveCatapult(int CMD){
	motor[M_CATAPULT_1] = CMD * 127;
	motor[M_CATAPULT_2] = CMD * 127;
}

void lowerCatapultToIntake(){ //Lower lift to ball loading
	int t0 = time1[T1];
	moveCatapult(DOWN);
	while(!catapultInPosition() && !isTimedOut(t0 + 1000)){
		moveCatapult(DOWN);
		wait1Msec(10);
	}
	moveCatapult(STOP);
}

void fireCatapult(){

}

#endif
