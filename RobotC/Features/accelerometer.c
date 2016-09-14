#pragma config(Sensor, in1,    xAxis,          sensorAccelerometer)
#pragma config(Sensor, in2,    yAxis,          sensorAccelerometer)
#pragma config(Sensor, in3,    zAxis,          sensorAccelerometer)
//
//  accelerometer.c
//  
//
//  Created by Zac Schulwolf on 7/29/14.
//
//
task main()
{
    int nBiasValues[3];
    
    int X_Accel;
    int Y_Accel;
    int Z_Accel;
    
    wait1Msec(500); // bias values are being calculated
    
    /* store the bias values in an array so that they can be
     * displayed in the ROBOTC global variables debug window */
    nBiasValues[0] = SensorBias[xAxis];
    nBiasValues[1] = SensorBias[yAxis];
    nBiasValues[2] = SensorBias[zAxis];
    
    while(true)
    {
        /* also store the actual sensor values so that they can be
         * easily displayed in the ROBOTC global variables debug window */
        X_Accel = SensorValue[xAxis];
        Y_Accel = SensorValue[yAxis];
        Z_Accel = SensorValue[zAxis];
        
        wait1Msec(100);
    }
}