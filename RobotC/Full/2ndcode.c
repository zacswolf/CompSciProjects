#pragma config(Motor,  port1,           topliftleft,   tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftfront,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftback,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightback,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightfront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftlift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightlift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightintake,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           leftintake,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          topliftright,  tmotorVex393_HBridge, openLoop)
#pragma config(Sensor, dgtl1,  					pneumaticsOne,  sensorDigitalOut)
#pragma config(Sensor, dgtl2,  					pneumaticsTwo,  sensorDigitalOut)
#pragma config(Sensor, dgtl3,  underbutton,         sensorTouch)
#pragma config(Sensor, dgtl4,  leftarmbutton,         sensorTouch)
#pragma config(Sensor, dgtl5,  rightarmbutton,         sensorTouch)
#pragma config(Sensor, dgtl6,  rightencoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  leftencoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  frontsonar,         sensorSONAR_cm)
#pragma config(Sensor, in1,    leftpot,  sensorPotentiometer)
#pragma config(Sensor, in2,    rightpot,  sensorPotentiometer)

//
//  2ndcode.c
//  
//
//  Created by Zac Schulwolf on 7/29/14.
//
//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
//function for turning pneumatics on
void pneumaticsOn() {
	SensorValue[pneumaticsOne] = 1;
	SensorValue[pneumaticsTwo] = 1;
}
//function for turning pneumatics off
void pneumaticsOff() {
	SensorValue[pneumaticsOne] = 0;
	SensorValue[pneumaticsTwo] = 0;
}
//function to toggle pheumatics (turning off and on)
void togglePneumatics() {
	if (SensorValue[pneumaticsOne] == 0) {
		pneumaticsOn();
	}
	else {
		pneumaticsOff();
	}
}

//function to turn
void turn(char dir)
{
    if (dir = 'l')
    {
        left(-127);
        right(127);
    }
    
    if (dir = 'r')
    {
        left(127);
        right(-127);
    }
}

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
    motor[leftlift] = x;
    motor[topliftright] = x;
    motor[leftlift] = x;
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
    SensorValue[rightencoder] = 0;
    SensorValue[leftencoder] = 0;
}

//function for outtakecheck on sonar
void sonarcheck(int distance, int speedifauto)//speedifauto should be negitive
{
    if (SensorValue[frontsonar] < distance)
    {
        if (vexRT[Btn5U])
        {
            intake(-10)
            wait1Msec(1000)
        }
        else
        {
            intake(speedifauto)
        }
    }
}

//encoder stuff
void encdrive(int inch, char motion)
{
    int circumference = 12.5;
    int inchespertick = circumference / 360;
    int ticks = inch/inchespertick
    SensorValue[rightencoder] = 0;
    SensorValue[leftencoder] = 0;
    
    //drives foreward until encoder value is greater then tics
    if (motion = 'f'){
        while (abs(SensorValue[leftencoder]) < ticks || abs(SensorValue[rightencoder]) < ticks)
        {
            forward()
        }
        SensorValue[rightencoder] = 0;
        SensorValue[leftencoder] = 0;
    }
    //drives backward until encoder value is
    if (motion = 'b'){
        while (abs(SensorValue[leftencoder]) < ticks || abs(SensorValue[rightencoder]) < ticks)
        {
            backward()
        }
        SensorValue[rightencoder] = 0;
        SensorValue[leftencoder] = 0;
    }
}
//function for turning 90 degrees
void ninetyturn(char motion)
{
    SensorValue[rightencoder] = 0;
    SensorValue[leftencoder] = 0;
    if (motion = 'l')
    {
        int circumference = 12.56; //this is the circumference of the wheels that you are using
        
        int distance = ?;//this is the distance of the arch (turn the robot 90 degrees but make sure you keep the center point of the robot still and measure the wheel movement)in between the frontright and the backright or the frontleft and the backleft.
        int ticks = distance / (circumference / 360);
        while (abs(SensorValue[leftencoder]) < ticks || abs(SensorValue[rightencoder]) < ticks)
        {
            turn(l);
        }
        SensorValue[rightencoder] = 0;
        SensorValue[leftencoder] = 0;
    }
    
    if (motion = 'r')
    {
        int circumference = 12.56; //this is the circumference of the wheels that you are using
        
        int distance = ?;//this is the distance of the arch (turn the robot 90 degrees but make sure you keep the center point of the robot still and measure the wheel movement)in between the frontright and the backright or the frontleft and the backleft.
        int ticks = distance / (circumference / 360);
        while (abs(SensorValue[leftencoder]) < ticks || abs(SensorValue[rightencoder]) < ticks)
        {
            turn(r);
        }
        SensorValue[rightencoder] = 0;
        SensorValue[leftencoder] = 0;
    }
}

//potentiometer stuff
void potup(int x);
{
    if(SensorValue[leftpot] < 900) //If the Potentiometer has not reached its maximum point...
    {
        lift(x)
    }
}
void potdown(int x);
{
    if(SensorValue[leftpot] > 550) //If the Potentiometer has not reached its maximum point...
    {
        lift(x)
    }
}
//potentiometer down



/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function. I like the concept of a woman. Red bucky box? Ball? Relativity.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
    // THIS IS WHERE YOU CAN CHECK, AND FIX THE SENSORS AND MOTORS...
    
    // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
    // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
    bStopTasksBetweenModes=true;
    allStop();
    pneumaticsOff();
    
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
    wait1Msec(500);
    encdrive(6, f);
    potup(127);
    
    
    //wait1Msec(500);
    //
    //forward();
    //wait1Msec(2000);
    //lift(127);
    //wait1Msec(2000);
    
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
        if (abs(vexRT[Ch3]) > threshold) {
            left(vexRT[Ch3]/1.5);
        }
        else
        {
            left(0);
        }
        
        //right drive
        if (abs(vexRT[Ch2]) > threshold) {
            right(vexRT[Ch2]/1.5);
        }
        else
        {
            right(0);
        }
        
        
        //lift
        if (vexRT[Btn6U]) {
            lift(127);
        }
        else if (vexRT[Btn6D]) {
            lift(-127);
        }
        else
        {
            lift(0);
        }
        //pneumatics
        if (vexRT[Btn8U] == 1) {
            togglePneumatics();
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
        
        //touch sensors
        if (SensorValue(underbutton) == 1)
        {
            backward();
            wait1Msec(2000);
        }
        
        if (SensorValue(leftarmbutton) == 1 || SensorValue(rightarmbutton) == 1)
        {
            lift(127);
            wait1Msec(500);
        }
        
        //90 degree turn right
        if (vexRT[Btn8R] = 1) {
            ninetyturn(r);
        }
        
        // 90 degree turn left
        if (vexRT[Btn8L] = 1) {
            ninetyturn(l);
        }
        
    }
}









