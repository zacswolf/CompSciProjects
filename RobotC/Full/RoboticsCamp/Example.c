#pragma config(Motor,  port1,  rightIntake,  tmotorVex393, openLoop)
#pragma config(Motor,  port2,  leftFront,    tmotorVex393, openLoop)
#pragma config(Motor,  port3,  leftBack,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,  rightBack,    tmotorVex393, openLoop)
#pragma config(Motor,  port8,  rightFront,   tmotorVex393, openLoop)
#pragma config(Motor,  port9,  botleftLift,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,  botrightLift,    tmotorVex393, openLoop)
#pragma config(Motor,  port5,  topleftLift,  tmotorVex393, openLoop)
#pragma config(Motor,  port6,  toprightLift,   tmotorVex393, openLoop)
#pragma config(Motor,  port10, leftIntake, tmotorVex393, openLoop)


#pragma platform(VEX)

//Competition Control and Duration Settings (You dont need to worry about this!
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!



























/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
    // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
    // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
    bStopTasksBetweenModes=true;
    
    
    // All activities that occur before the competition starts
    // Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a Competition.
// You must modify the code to add your own robot specific commands here. I want pancake.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()                   //AUTONOMOUS
{
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a Competition.
// You must modify the code to add your own robot specific commands here. It's 5:12 AM.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol() {                //USERCONTROL
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
