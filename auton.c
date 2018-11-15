#ifndef AUTON_C
#define AUTON_C

/*
  AUTON.C
  Holds the code for all the autonomous modes
  Jeffrey Shen
*/

void autoA(){ //Fire it and move forward
  autoB();
  wait1Msec(1000);
  moveFwd();
  wait1Msec(3000);
  moveStop();
}

void autoB(){ //Just fire it
  //Deploy Lift

  //Fire
  lowerCatapultToIntake();
  wait1Msec(1000);
  fireCatapult();
}

void autoC(){
}

void prgSkills(){

}


#endif
