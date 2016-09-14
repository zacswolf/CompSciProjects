#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
//
//  linefollower.c
//  
//
//  Created by Zac Schulwolf on 7/29/14.
//
//
task main()
{
    wait1Msec(2000);                // wait 2 seconds before exectuing following code
    bMotorReflected[port2] = true;  // reflects direction of motor on port 2
    
    while(true)                     // infinite loop:
    {
        if(SensorValue(lineFollower) < 950) // if the lineFollower sensor reads a value less than 950:
        {
            // turn left:
            motor[port2] = 50;  // motor on port 2 is run at power level 50
            motor[port3] = 0;   // motor on port 3 is stopped at power level 0
        }
        else  // lineFollower sensor reads a value greater than or equal to 950:
        {
            motor[port2] = 0;   // motor on port 2 is stopped at power level 0
            motor[port3] = 50;  // motor on port 3 is run at power level 50
        }
    }
}