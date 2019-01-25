#ifndef AUTON_C
#define AUTON_C

/*
  AUTON.C
  Holds the code for all the autonomous modes
  Jeffrey Shen
*/

void autoB(){ //Fire and deploy flippers
	//Fire
	CATAPULT_COMMAND = MANUAL;
	lowerCatapultToIntake();
  fireCatapult();
  CATAPULT_COMMAND = STOP;

  // Release Flippers
  moveBkwd();
  wait1Msec(500);
  moveFwd();
  wait1Msec(500);
  moveStop();
}

void autoA(){ //Fire it and move forward
	/*CATAPULT_COMMAND = MANUAL;
	lowerCatapultToIntake();
  fireCatapult();
  CATAPULT_COMMAND = STOP;*/

  moveFwd();
  wait1Msec(1500);
  moveStop();
}

void autoC(){
	autoA();
	moveBkwd();
	wait1Msec(800);
	moveFlipper(-20);
	moveStop();
	rotate(SIDE * 60);
	wait1Msec(600);
	rotate(STOP);
	moveBkwd();
	wait1Msec(500);
	moveStop();
	wait1Msec(200);
	moveVertical(50);
	wait1Msec(300);
	moveFlipper(UP)
	wait1Msec(700);
	moveFlipper(STOP);
}

void prgSkills(){

}


#endif
