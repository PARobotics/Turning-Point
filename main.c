#pragma config(Sensor, dgtl1,  S_WHEEL_L,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  S_WHEEL_R,      sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  S_TOP_SONAR,    sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  S_LOW_SONAR,    sensorSONAR_cm)
#pragma config(Motor,  port1,           M_INTAKE,      tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           M_CATAPULT_1,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           M_WHEEL_R2,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           M_WHEEL_R1,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           M_WHEEL_L1,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           M_WHEEL_L2,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           M_CATAPULT_2,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           M_LIFT_1,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           M_LIFT_2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          M_FLIPPER,     tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
#include "arm.c"

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
		H = -vexRT[Ch1];

		/*if(sensorValue(S_LOW_SONAR)<6) //edit later: needs overall update-LOW SONAR X USED
		{
			bool initiateLift = true;
			while(initiateLift){
				if(sensorValue(S_TOP_SONAR) <10 || vexRT[BAILOUT_BUTTON]){

					break;
				}
			intakeUp();
			}
		}
		else */if(vexRT[Btn8U]) intakeUp();

		else if(vexRT[Btn8D]) intakeDown();

		else intakeStop();

		if(vexRT[Btn8R]) moveCatapult(DOWN);
		else if(vexRT[Btn8L]) moveCatapult(UP);
		else moveCatapult(STOP);

		if(getPrButton(BTN_7L)) {
			PlaySoundFile("highground.wav");
			resetPrButton(BTN_7L);
		}

		if(vexRT[Btn6U]) moveLift(UP);
		else if(vexRT[Btn6D]) moveLift(DOWN);
		else moveLift(STOP);

		if(vexRT[Btn5U]) moveFlipper(UP);
		else if(vexRT[Btn5D]) moveFlipper(DOWN);
		else if(FLIPPER_COMMAND == HOLD_UP) moveFlipper(20);
		else if(FLIPPER_COMMAND == HOLD_DOWN) moveFlipper(-20);
		else moveFlipper(STOP);

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
