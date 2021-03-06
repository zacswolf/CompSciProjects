#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    potRightSensor, sensorPotentiometer)
#pragma config(Sensor, in2,    potLeftSensor,  sensorPotentiometer)
#pragma config(Sensor, in3,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  hook,           sensorDigitalOut)
#pragma config(Sensor, dgtl2,  bottomLift,     sensorDigitalOut)
#pragma config(Sensor, dgtl3,  topPull,        sensorDigitalOut)
#pragma config(Sensor, dgtl4,  topPull2,       sensorDigitalOut)
#pragma config(Sensor, dgtl6,  button,         sensorNone)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightBack,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port3,           intakeRight,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           liftRight,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftFront,     tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port6,           rightMid,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           leftMid,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           intakeLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           liftLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftBack,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#define MAX 1700
#define Goal 1650
#define Barrier 1050
#define Bump 225
#define Bucky 50


//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


const short leftButton = 1;//LCD stuff
const short centerButton = 2;// ||
const short rightButton = 4;//	||
int choice = 0;//used in selecting autonomous routines
int threshold = 20;//prevents joystick noise
int potLeftTemp;
int potRightTemp;
int potLeft;
int potRight;
float pK = .3;
float iK = 0.001;
float dK = 0.1;
int error;
int errorSum;
int prevError;
int derivative;
int currentPosition;
int acceptableError = 100;
int motorOutput;
int potPosition;
bool robotIsThere = false;
bool hookToggle = false;
bool liftToggle = false;
bool timerStart = false;
//int setPosition;
int potDifference;
int gyroDifference;


void waitForPress();
void waitForRelease();

//RESET FUNCTIONS////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void allStop()//good debugging tool
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

//LCD FUNCTIONS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}

void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//DRIVE FUNCTIONS////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//maps the joystick values to the cubic function for driver control
/*int cubicMap(int x)//x is joystick value
{
	return ((((x*3)/25)*((x*3)/25)*((x*3)/25)/27 + x/2)*2)/3;
}
*/

void driveRight(int speed)
{
	motor[rightBack] = speed;
	motor[rightMid] = speed;
	motor[rightFront] = speed;
}

void driveLeft(int speed)
{
	motor[leftBack] = speed;
	motor[leftMid] = speed;
	motor[leftFront] = speed;
}

//set encoders to 0
//clear timer

void encoderReset(){
	robotIsThere = false;
	nMotorEncoder(leftFront) = 0;
	nMotorEncoder(rightFront) = 0;
	ClearTimer(T1);
}

void drivePID(int destination)
{
	errorSum = 0;

	currentPosition = (nMotorEncoder(leftFront) + nMotorEncoder(rightFront))/2;

	//driving forward
	if(destination > 0)
	{
		error = destination - currentPosition;
		prevError = error;

		if(error > acceptableError)
		{
			error = destination - currentPosition;
			errorSum += error;

			//calculates the derivative of error vs. time every .1 seconds
			if(time1[T1] > 100)
			{
				derivative = error - prevError;
				prevError = error;
				clearTimer(T1);
			}

			motorOutput = (error * pK) /* + (errorSum * iK) + (derivative * dK) */;
			motor[leftFront] = motorOutput;
      motor[leftMid] = motorOutput;
      motor[leftBack] = motorOutput;
      motor[rightFront] = motorOutput;
      motor[rightMid] = motorOutput;
      motor[rightBack] = motorOutput;


		}
	}

	//driving backwards
	if(destination < 0)
	{
		destination = abs(destination);
		error = destination - currentPosition;
		prevError = error;

		if(error > acceptableError)
		{
			error = destination - currentPosition;
			errorSum += error;

			//calculates the derivative of error vs. time every .1 seconds
			if(time1[T1] > 100)
			{
				derivative = error - prevError;
				prevError = error;
				ClearTimer(T1);
			}

			motorOutput = -((error * pK) /*+ (errorSum * iK) + (derivative * dK)*/);
            motor[leftFront] = motorOutput;
            motor[leftMid] = motorOutput;
            motor[leftBack] = motorOutput;
            motor[rightFront] = motorOutput;
            motor[rightMid] = motorOutput;
            motor[rightBack] = motorOutput;
		}
	}

	if(error < acceptableError)
		robotIsThere = true;

}

void turn(int degrees){

		gyroDifference = abs(degrees - SensorValue[gyro]);

		int speed = 0.4 * gyroDifference;

		if (speed > 50)
			speed = 50;

		if (SensorValue[gyro] > degrees){
			driveLeft(speed);
			driveRight(-speed);
		}

		else if (SensorValue[gyro] < degrees){
			driveLeft(-speed);
			driveRight(speed);
		}

		else{

				driveLeft(0);
				driveRight(0);
}
}

int inchesToTicks(int distance){
	int ticks = distance * 27.780;
	return ticks;
}

int degreesToGyro(int degrees){
	int ticks = degrees * 10;
	return ticks;
}



//accelerates the robot linearly between the current speed and the target speed; used in auton and driver control
//for driver control: motor[] = accelControlLeft(cubicMap(joystickValue));
/*int accelControlLeft(int targetSpeed)
{
	int output = 0;
	int difference = targetSpeed - motorSpeedLeft;
	if(difference > 30)
	{
		output = motorSpeedLeft + 1;
	}
	return output;
}
*/

//LIFT FUNCTIONS////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int potAverage() //returns average of potLeft and potRight
{
	return (potLeft + potRight) / 2;
}

void liftOff(){
	motor[liftLeft] = 0;
	motor[liftRight] = 0;
}

void lift(int height){
		potLeft = abs(SensorValue[potLeftSensor] - potLeftTemp);
  	potRight = abs(SensorValue[potRightSensor] - potRightTemp);

  	if(potAverage() < (height - 100)){
  		if(abs(potLeft - potRight) < 100)
			{
				motor[liftLeft] = 127;
				motor[liftRight] = 127;
			}
			else if(potLeft > potRight)
			{
				motor[liftLeft] = 90;
				motor[liftRight] = 127;
			}
			else if(potLeft < potRight)
			{
				motor[liftLeft] = 127;
				motor[liftRight] = 90;
			}
		}

		else if(potAverage() > (height + 100)){
			if(abs(potLeft - potRight) < 100)
			{
				motor[liftLeft] = -70;
				motor[liftRight] = -70;
			}
			else if(potLeft > potRight)
			{
				motor[liftLeft] = -70;
				motor[liftRight] = -40;
			}
			else if(potLeft < potRight)
			{
				motor[liftLeft] = -40;
				motor[liftRight] = -70;
			}
		}

			else
		{
				potDifference = height - potAverage();
				int speed = 0;
				if(potDifference > 30)
					speed = 0.1 * potDifference;

				else
					speed = 0;

				motor[liftLeft] = speed;
				motor[liftRight] = speed;
			}


}
//INTAKE FUNCTIONS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void intake(int speed){
	motor[intakeLeft] = speed;
	motor[intakeRight] = speed;
}

void flipDown(){
	ClearTimer(T4);
	while(time1[T4] < 500){
		SensorValue[hook] = 1;
		intake(127);
		}

	SensorValue[hook] = 0;
	intake(0);
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
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
  bLCDBacklight = true;
  clearLCDLine(0);
  clearLCDLine(1);


  potLeftTemp = SensorValue[potLeftSensor];
  potRightTemp = SensorValue[potRightSensor]; //make sure LIFT IS DOWN!

  //user interface loop runs until valid choice is selected
  while(nLCDButtons != centerButton)
	{

		//0 = main menu
		//1 = left side
		//2 = right side

		switch(choice)//controls menu options
		{
			case 0:	 displayLCDCenteredString(0, "Middle Zone");
								displayLCDCenteredString(1, "1: Barrier Blitz");

							waitForPress();

							if(nLCDButtons == leftButton)
							{
								waitForRelease();
								choice = 3;
							}

							else if(nLCDButtons == rightButton)
							{
								waitForRelease();
								choice = 1;
							}
							break;

			case 1:	  	displayLCDCenteredString(0, "Red Hanging Zone");
				displayLCDCenteredString(1, "2: Bump Blitz");
							waitForPress();

							if(nLCDButtons == leftButton)
							{
								waitForRelease();
								choice = 0;
							}

							else if(nLCDButtons == rightButton)
							{
								waitForRelease();
								choice = 2;
							}
							break;

			case 2:		 		displayLCDCenteredString(0, "Blue Hanging Zone");
				displayLCDCenteredString(1, "3: Bump Blitz ");
							waitForPress();

							if(nLCDButtons == leftButton)
							{
								waitForRelease();
								choice = 1;
							}

							else if(nLCDButtons == rightButton)
							{
								waitForRelease();
								choice = 3;
							}
							break;



				case 3:	displayLCDCenteredString(0, "Hanging Zone");
				displayLCDCenteredString(1, "4: Handoff");
							waitForPress();

							if(nLCDButtons == leftButton)
							{
								waitForRelease();
								choice = 2;
							}

							else if(nLCDButtons == rightButton)
							{
								waitForRelease();
								choice = 0;
							}
							break;



			default:choice = 0;
							break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

  switch(choice){
  	case 0:

  	  	 displayLCDCenteredString(0, "Middle Zones");
				displayLCDCenteredString(1, "1: Barrier Blitz");

				flipDown();

				driveLeft(115);
				driveRight(115);

				ClearTimer(T1);
				while(time1[T1] < 750)
					lift(Barrier);


				liftOff();
				driveLeft(0);
				driveRight(0);

				ClearTimer(T1);
				while(time1[T1] < 200)
				{
				}

				driveLeft(-100);
				driveRight(-100);

				ClearTimer(T2);
				while(time1[T2] < 750){
				}

				liftOff();
				driveLeft(0);
				driveRight(0);

				while(SensorValue[button] == 0){

				}

				driveLeft(100);
				driveRight(100);

				ClearTimer(T1);
				while(time1[T1] < 1100){
					lift(Barrier);
				}


				liftOff();
				driveLeft(0);
				driveRight(0);

				wait1Msec(200);

				ClearTimer(T1);
				while(time1[T1] < 800){
					lift(Barrier);
					driveLeft(-100);
					driveRight(-100);
				}

				driveLeft(0);
				driveRight(0);

				while(SensorValue[button] == 0){
					lift(Bucky);
				}

				encoderReset();
				while(robotIsThere == false){
					drivePID(inchesToTicks(40));
					lift(Bucky);
			}

				encoderReset();
				while(robotIsThere == false){
					drivePID(inchesToTicks(30));
					lift(Goal);
				}

				ClearTimer(T1);
				while(time1[T1] < 500){
					lift(Goal);
				driveLeft(0);
				driveRight(0);
				}

				intake(-127);
				liftOff();

				wait1Msec(800);
				intake(0);

				int state = 1;
				while (state == 1){
					state = 1;
				}

				//Face large balls on barrier
				//Start and flipdown intake rollers (make sure to get preload)
				//Drive forward using time, while lifting at least 12"
				//Hit Large Ball off of barrier
				//Outtake preload into middle zone
				//Keep driving
				//Robot stops after certain time



		case 1:
	   		displayLCDCenteredString(0, "Red Hanging Zone");
				displayLCDCenteredString(1, "2: Bump Blitz");

				flipDown();

				intake(127);

				//while(SensorValue[sonar] > 14)
				{
					driveLeft(50);
					driveRight(55);
				}

				driveLeft(0);
				driveRight(0);

				wait1Msec(1500);
				intake(0);

				//while(SensorValue[sonar] < 24)
				{
					driveLeft(-50);
					driveRight(-50);
				}

				driveLeft(0);
				driveRight(0);


				while(SensorValue[button] == 0){
					lift(Barrier);
				}

				encoderReset();
				while((nMotorEncoder(leftFront)) < (inchesToTicks(16))){
					driveRight(70);
					driveLeft(70);
					lift(Barrier);
				}

				encoderReset();
				while((nMotorEncoder(leftFront)) < (inchesToTicks(25))){
					driveRight(0);
					driveLeft(105);
					lift(Barrier);
				}

				ClearTimer(T2);
				while(time1[T2] < 1500){
					driveLeft(90);
					driveRight(90);
					lift(Barrier);
				}

				intake(-127);
				driveRight(0);
				driveLeft(0);
				liftOff();

				wait1Msec(2000);

				state = 0;
				while(state == 0)
					state = 0;

  	case 2:

  	   	displayLCDCenteredString(0, "Blue Hanging Zone");
				displayLCDCenteredString(1, "3: Bump Blitz");

				flipDown();

				intake(127);

				//while(SensorValue[sonar] > 14)
				{
					driveLeft(55);
					driveRight(50);
				}

				driveLeft(0);
				driveRight(0);

				wait1Msec(1500);
				intake(0);

				//while(SensorValue[sonar] < 24)
				{
					driveLeft(-50);
					driveRight(-50);
				}

				driveLeft(0);
				driveRight(0);


				while(SensorValue[button] == 0){
					lift(Barrier);
				}

				encoderReset();
				while((nMotorEncoder(rightFront)) < (inchesToTicks(16))){
					driveRight(70);
					driveLeft(70);
					lift(Barrier);
				}

				encoderReset();
				while((nMotorEncoder(rightFront)) < (inchesToTicks(20))){
					driveRight(90);
					driveLeft(0);
					lift(Barrier);
				}

				ClearTimer(T2);
				while(time1[T2] < 1500){
					driveLeft(90);
					driveRight(90);
					lift(Barrier);
				}

				intake(-127);
				driveRight(0);
				driveLeft(0);
				liftOff();

				wait1Msec(2000);

				state = 0;
				while(state == 0)
					state = 0;


				//Face robot towards buckyballs next to perimeter
				//Flip down intake rollers (make sure to get preload!)
				//Drive forward, pick up the 2 buckyballs
				//Drive backwards with IMEs
				//Rotate towards bump buckyballs
				//Drive with one side and knock buckyballs off bump by pushing large ball into them
			  //Drive straight and outtake
				//Freeze


  	 case 3:
  	   	displayLCDCenteredString(0, "Hanging Zone");
				displayLCDCenteredString(1, "4: Handoff");

			SensorValue[gyro] = 0;
			ClearTimer(T1);

			while(time1[T1] < 5000)
				turn(degreesToGyro(90));

				driveLeft(0);
				driveRight(0);
}

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	while(true)
	{
		potLeft = abs(SensorValue[potLeftSensor] - potLeftTemp);
  	potRight = abs(SensorValue[potRightSensor] - potRightTemp);

  	if(abs(vexRT[Ch3]) > threshold)
		{
			driveLeft(vexRT[Ch3]);
		}
		else
		{
			driveLeft(0);
		}

    
    
		if(abs(vexRT[Ch2]) > threshold)
		{
			driveRight(vexRT[Ch2]);
		}
		else
		{
			driveRight(0);
		}

		if(!(vexRT[Btn7U] || vexRT[Btn7L]))
		{
		if(vexRT[Btn5U])
		{
			SensorValue[bottomLift] = 1;
			if(abs(potLeft - potRight) < 10)
			{
				motor[liftLeft] = 127;
				motor[liftRight] = 127;
			}
			else if(potLeft > potRight)
			{
				motor[liftLeft] = 112;
				motor[liftRight] = 127;
			}
			else if(potLeft < potRight)
			{
				motor[liftLeft] = 127;
				motor[liftRight] = 112;
			}
			potPosition = potAverage();
		}
		else if(vexRT[Btn5D])
		{
			SensorValue[bottomLift] = 0;

			if(abs(potLeft - potRight) < 20)
			{
				motor[liftLeft] = -30;
				motor[liftRight] = -30;
			}
			else if(potLeft > potRight)
			{
				motor[liftLeft] = -40;
				motor[liftRight] = -20;
			}
			else if(potLeft < potRight)
			{
				motor[liftLeft] = -20;
				motor[liftRight] = -40;
			}
			potPosition = potAverage();
		}
		else {
				potDifference = potPosition - potAverage();
				int speed = 0;
				if(potDifference > 10) {
					speed = potDifference;
					if(speed > 25) { speed = 25; }
				  }
				  else {
				    motor[liftLeft] = 0;
				    motor[liftRight] = 0;
          }
		}

		if(vexRT[Btn6U])
		{
			motor[intakeLeft] = 127;
			motor[intakeRight] = 127;
		}
		else if(vexRT[Btn6D])
		{
			motor[intakeLeft] = -127;
			motor[intakeRight] = -127;
		}
		else
		{
			motor[intakeLeft] = 0;
			motor[intakeRight] = 0;
		}

		if(vexRT[Btn7U]){ //hanging function
			//depressurize lift
			//pressurize all 4
			//run motors

			/*timerStart = true;
			clearTimer(T1);
			if(time1(T1) < 200){
				SensorValue[bottomLift] = 0;
				SensorValue[hook] = 1;
			}
			else{*/
				SensorValue[topPull] = 1;
				SensorValue[topPull2] = 1;

				if(potAverage() > 100){
					motor[liftLeft] = -127;
					motor[liftRight] = -127;
				}
			}
			else if(vexRT[Btn7L])
			{
				SensorValue[topPull] = 0;
				SensorValue[topPull2] = 0;
			}
		}

		//if(timerStart == true)
		//	ClearTimer(T2);

		if(vexRT[Btn8R])
			SensorValue[hook] = 1;

		else if(vexRT[Btn8D])
			SensorValue[hook] = 0;
	}
