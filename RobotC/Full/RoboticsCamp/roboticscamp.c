 #pragma config(Motor,  port1,           botliftleft,   tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftfront,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftback,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightback,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightfront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftarmlift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightarmlift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           topliftleft,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           topliftright,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          botliftright,  tmotorVex393_HBridge, openLoop)


//
//  roboticscamp.c
//  
//
//  Created by Zac Schulwolf on 7/30/14.
//
//
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


//function for the left drive
void left(int x)
{
    motor[leftfront] = x;
    motor[leftback] = x;
}

//function for the right drive
void right(int x)
{
    motor[rightback] = x;
    motor[rightfront] = x;
}

//function to move forward at the higest speed
void forward()
{
    motor[leftfront] = 127;
    motor[leftback] = 127;
    motor[rightback] = 127;
    motor[rightfront] = 127;
}

//function to move backward at the higest speed
void backward()
{
    motor[leftfront] = -127;
    motor[leftback] = -127;
    motor[rightback] = -127;
    motor[rightfront] = -127;
}

//function to lift the arms
void lift(int x)
{
    motor[topliftleft] = x;
    motor[botliftleft] = x;
    motor[topliftright] = x;
    motor[botliftright] = x;
    
    motor[rightarmlift] = x;
    motor[leftarmlift] = x;
}

//function to move the intake
void intake(int x)
{
    
    motor[leftintake] = x;
    motor[rightintake] = x;
}

//good debugging tool
void allStop()
{
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
	motor[port9] = 0;
	motor[port10] = 0;
}


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
    // THIS IS WHERE YOU CAN CHECK, AND FIX THE SENSORS AND MOTORS...
    
    // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
    // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
    bStopTasksBetweenModes=true;
    allStop();
    
	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}


/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
    wait1Msec(25);
    
    forward();
    wait1Msec(2000);
    lift(127);
    wait1Msec(2000);
    intake(127);
    wait1Msec(2000);
    lift(-127);
    wait1Msec(2000);
    backward();
    wait1Msec(2000);
    intake(-127);
    wait1Msec(2000);
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol() {
    
	int threshold = 10;
    while(true) {
        
        //left drive
        if(abs(vexRT[Ch3]) > threshold) {
            left(vexRT[Ch3]);
        } 
        else
        {
            left(0);
        }
        
        //right drive
        if(abs(vexRT[Ch2]) > threshold) {
            right(vexRT[Ch2]);
        }
        else
        {
            right(0);
        }
        
        
        //lift
        if(vexRT[Btn6U]) {
            lift(127);
        }
        else if(vexRT[Btn6D]) {
            lift(-127);
        }
        else
        {
            lift(0);
        }
        
        
        
        //intake
        if(vexRT[Btn5D]) {
            intake(127);
            
        }
        else if(vexRT[Btn5U]) {
            intake(-127);
        }
        else
        {
            intake(0);
        }
    }
}

