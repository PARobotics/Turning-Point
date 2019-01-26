#ifndef BAT_C
#define BAT_C

/*
  BAT.C
  Controls the ball-shooting bat
  Jeffrey Shen
*/

//Intake
void intakeUp(){
	motorReq[M_INTAKE] = 127;
}

void intakeDown(){
	motorReq[M_INTAKE] = -127;
}

void intakeStop(){
	motorReq[M_INTAKE] = 0;
}

//Catapult
bool catapultInPosition(){ //Is the catapult in the proper position for loading and shooting
	return SensorValue(S_TOP_SONAR) != -1 && SensorValue(S_TOP_SONAR) <= 80;
}

void moveCatapult(int CMD){
	if(CMD == UP || CMD == DOWN) CMD = CMD * 127;
	motorReq[M_CATAPULT] = CMD;
}

void lowerCatapultToIntake(){ //Lower lift to ball loading
	if(!catapultInPosition()){
		int t0 = time1[T1];
		moveCatapult(DOWN);
		while(!catapultInPosition() && !isTimedOut(t0 + 4000) && !isBailedOut()){
			moveCatapult(DOWN);
			wait1Msec(10);
		}
		moveCatapult(STOP);
	}
}

void fireCatapult(){
	int t0 = time1[T1];
	moveCatapult(DOWN);
	while(catapultInPosition() && !isTimedOut(t0 + 1000) && !isBailedOut()){
		moveCatapult(DOWN);
		wait1Msec(10);
	}
	moveCatapult(STOP);
}

task catapultTask(){
	while(true){
		if(CATAPULT_COMMAND == UP) {
			moveCatapult(UP);
		}
		else if(CATAPULT_COMMAND == DOWN){
			moveCatapult(DOWN);
			///if(vexRT[Btn8R] == 0) CATAPULT_COMMAND = RESET;
		}
		else if(CATAPULT_COMMAND == SHOOT) {
			fireCatapult();
			wait1Msec(200);
			CATAPULT_COMMAND = RESET;
		}
		else if(CATAPULT_COMMAND == RESET) {
			lowerCatapultToIntake();
		}
		else if(CATAPULT_COMMAND != MANUAL) moveCatapult(STOP);

		wait1Msec(50);
	}
}

#endif
