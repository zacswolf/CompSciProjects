#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
//
//  light.c
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
        clearLCDLine(0);                                // clear the top VEX LCD line
        clearLCDLine(1);                                // clear the bottom VEX LCD line
        
        setLCDPosition(0,0);                            // set the VEX LCD cursor the first line, first space
        displayNextLCDString("Light Sensor:");          // display "Light Sensor:" on the top line
        
        setLCDPosition(1,0);                            // set the VEX LCD cursor the second line, first space
        displayNextLCDNumber(SensorValue(lightSensor)); // display the reading of the lightSensor sensor
        
        wait1Msec(50);                                  // wait 50 milliseconds to help display properly
    }
}
