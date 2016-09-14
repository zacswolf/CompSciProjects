
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)//
//  quadrature_encoder.c
//  
//
//  Created by Zac Schulwolf on 7/29/14.
//
//
task main()
{
    wait1Msec(2000);  // 2 Second Delay
    
    //Clear Encoders
    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
    
    while(SensorValue[leftEncoder] < 1800)  // While less than 5 rotations on the leftEncoder...
    {
        //...Move Forward
        motor[rightMotor] = 63;
        motor[leftMotor] = 63;
    }
    
}