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
	return SensorValue(S_TOP_SONAR) != -1 && SensorValue(S_TOP_SONAR) <= 7;
}

void moveCatapult(int CMD){
	motorReq[M_CATAPULT] = CMD * 127;
}

void lowerCatapultToIntake(){ //Lower lift to ball loading
	int t0 = time1[T1];
	moveCatapult(DOWN);
	while(!catapultInPosition() && !isTimedOut(t0 + 4000) && !isBailedOut()){
		moveCatapult(DOWN);
		wait1Msec(10);
	}
	wait1Msec(200);
	moveCatapult(STOP);
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
		}
		else if(CATAPULT_COMMAND == SHOOT) {
			fireCatapult();
			wait1Msec(500);
			CATAPULT_COMMAND = RESET;
		}
		else if(CATAPULT_COMMAND == RESET) {
			lowerCatapultToIntake();
			CATAPULT_COMMAND = HOLD;
		}
		else if(CATAPULT_COMMAND != MANUAL) moveCatapult(STOP);

		wait1Msec(50);
	}
}

#endif
