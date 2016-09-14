#pragma config(Sensor, dgtl6,  touchSensor,         sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//
//  touch.c
//  
//
//  Created by Zac Schulwolf on 7/29/14.
//
//
task main()
{
    wait1Msec(2000);  // Robot waits for 2000 milliseconds before executing program
    
    while(SensorValue(touchSensor) == 0)  // Loop while robot's bumper/touch sensor isn't pressed in
    {
        motor[rightMotor] = 63;	 // Motor on port2 is run at half (63) power forward
        motor[leftMotor]  = 63;	 // Motor on port3 is run at half (63) power forward
    }
}