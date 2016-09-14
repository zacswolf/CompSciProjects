//create pragmas
/*
port1,           topliftleft
port2,           leftfront,
port3,           leftback,
port4,           rightback,
port5,           rightfront,
port6,           leftlift,
port7,           rightlift,
port8,           rightintake,
port9,           leftintake,
port10,          topliftright,
*/

//
//  RoboticsCampLesson1.c
//  
//
//  Created by Zac Schulwolf on 7/19/15.
//
//



#pragma platform(VEX)


//Competition Control and Duration Settings     (only needed if your in a real compitition)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)



//function for the left drive
void left(int x)            //you use (int x) so you can control the speed
{
    motor[leftfront] = x;
    motor[leftback] = x;
}
//function for the right drive
void right(int x)            //you use (int x) so you can control the speed
{
    motor[rightback] = x;
    motor[rightfront] = x;
}
//function to move forward at the higest speed
void forward()              //This is only used in Autonomous
{
    motor[leftfront] = 127;
    motor[leftback] = 127;
    motor[rightback] = 127;
    motor[rightfront] = 127;
}
//function to move backward at the higest speed
void backward()              //This is only used in Autonomous
{
    motor[leftfront] = -127;
    motor[leftback] = -127;
    motor[rightback] = -127;
    motor[rightfront] = -127;
}
//function to lift the arms
void lift(int x)            //you use (int x) so you can control the speed
{
    motor[topliftleft] = x;
    motor[leftlift] = x;
    motor[topliftright] = x;
    motor[leftlift] = x;
}
//function to move the intake
void intake(int x)            //you use (int x) so you can control the speed
{
    
    motor[leftintake] = x;
    motor[rightintake] = x;
}


//good debugging tool
void allStop()                    //the reason the motor is [port1] and not a name is because I use this on
{                                 //all my programs and I dont want to change it everytime
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
// following function. I like the concept of a woman. Red bucky box? Ball? Relativity.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
    // THIS IS WHERE YOU CAN CHECK, AND FIX THE SENSORS AND MOTORS...

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
    wait1Msec(1000); // waits 1 sec
    
    forward();
    wait1Msec(2000);
    lift(127);
    wait1Msec(2000);
    intake(127);
    wait1Msec(2000);
    lift(-127);
    wait1Msec(2000);
    backward()
    wait1Msec(2000);
    intake(127);
    wait1Msec(2000);
    //a basic program to drive forward, lift, intake, move lift down, back up, and outtake
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
    /*The treshold is makes it so small movement are ignored, which makes it easier to drive. The higher you make the threshold makes the ignored area is bigger. If your threshold is too big, then your controller movements need to be more powerful, so I recogmend a 10 to 20 treshold.*/
    
    
    
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
                    //if this button is pressed then lift goes up
            lift(127);
        }
        else if(vexRT[Btn6D]) {
                    //if this button is pressed then lift goes down
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
