#ifndef AUTON_C
#define AUTON_C

/*
  AUTON.C
  Holds the code for all the autonomous modes
  Jeffrey Shen
*/

void autoB(){ //Just fire it
  //Deploy Lift
	moveLift(UP);
	wait1Msec(300);
	moveFlipper(UP);
	moveLift(DOWN);
	wait1Msec(300);
	moveFlipper(STOP);
	wait1Msec(200);
	moveLift(STOP);
	moveFlipper(DOWN);
	wait1Msec(300);
	moveFlipper(-20);

	CATAPULT_COMMAND = MANUAL;
	lowerCatapultToIntake();
  fireCatapult();
  CATAPULT_COMMAND = STOP;
}

void autoA(){ //Fire it and move forward
	CATAPULT_COMMAND = MANUAL;
	lowerCatapultToIntake();
  fireCatapult();
  CATAPULT_COMMAND = STOP;

  moveFwd();
  wait1Msec(2000);
  moveStop();
}

void autoC(){
}

void prgSkills(){

}


#endif
