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
	return SensorValue(S_TOP_SONAR) < 8;
}

void moveCatapult(int CMD){
	motorReq[M_CATAPULT_1] = CMD * 127;
	motorReq[M_CATAPULT_2] = CMD * 127;
}

void lowerCatapultToIntake(){ //Lower lift to ball loading
	int t0 = time1[T1];
	moveCatapult(DOWN);
	while(!catapultInPosition() && !isTimedOut(t0 + 2000) && !isBailedOut()){
		moveCatapult(DOWN);
		wait1Msec(10);
	}
	wait1Msec(200);
	moveCatapult(STOP);
}

void fireCatapult(){
	int t0 = time1[T1];
	moveCatapult(DOWN);
	while(SensorValue(S_CATAPULT_LIM) == 0 && !isTimedOut(t0 + 3000) && !isBailedOut()){
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
		else if(CATAPULT_COMMAND == SHOOT) fireCatapult();
		else if(CATAPULT_COMMAND == RESET) {
			lowerCatapultToIntake();
			CATAPULT_COMMAND = HOLD;
		}
		else if(CATAPULT_COMMAND == HOLD){
			if(SensorValue(S_LOW_SONAR) <= 6){ //if there's a ball in
				moveCatapult(DOWN);
				wait1Msec(300);
				moveCatapult(STOP);
				wait1Msec(300);
				moveCatapult(DOWN);
				wait1Msec(700);
				moveCatapult(STOP);
				CATAPULT_COMMAND = STOP;
			}
		}
		else if(CATAPULT_COMMAND != MANUAL) moveCatapult(STOP);

		wait1Msec(50);
	}
}

#endif
