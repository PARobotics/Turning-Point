/*
  MAIN.C
  Primary file: Holds the entire competition sequence. You compile and flash THIS file.
  Jeffrey Shen
*/

#pragma DebuggerWindows("debugStream") //Include when debugging (automatically enables debug window)

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(1200)

#include "Vex_Competition_Includes.c"
#include "main.h"
#include "parallax-library/bin/constants.h"
#include "auton.c"
#include "parallax-library/main.c"
#include "bat.c"

void pre_auton(){
	bStopTasksBetweenModes = false; //Make sure all tasks we create actually execute in user control
	initialize();
}

task autonomous(){
	stopTask(usercontrol);
	autonProcedure();
}

/*
	USER CONTROL
*/

task usercontrol(){
  int V, H, X;

  stopTask(autonomous);

	if(MODE == RBT_SKILL){ //Disable slew for the drive during robot skills
		// MOTOR_SLEW[1] = 255;
		// MOTOR_SLEW[2] = 255;
		// MOTOR_SLEW[3] = 255;
		// MOTOR_SLEW[4] = 255;
		// MOTOR_SLEW[5] = 255;
		// MOTOR_SLEW[6] = 255;
	}

  while(true){

  	V = vexRT[Ch3];
  	X = vexRT[Ch4];
		H = vexRT[Ch1];

		//Robot skills controls
		if(MODE == RBT_SKILL){
			move(V, H, X);
		}
		else{
			move(V, H * 0.75, X);
		}

		userControlUpdate();
	}
}
