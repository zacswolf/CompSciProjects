#pragma config(Sensor, dgtl1,  pneumaticsOne,  sensorDigitalOut)
#pragma config(Sensor, dgtl2,  pneumaticsTwo,  sensorDigitalOut)
//*!!Code automatically generated by a gay wizard               !!*//

void pneumaticsOn() {
	SensorValue[pneumaticsOne] = 1;
	SensorValue[pneumaticsTwo] = 1;
}

void pneumaticsOff() {
	SensorValue[pneumaticsOne] = 0;
	SensorValue[pneumaticsTwo] = 0;
}

void togglePneumatics() {
	if (SensorValue[pneumaticsOne] == 0) {
		pneumaticsOn();
	}
	else {
		pneumaticsOff();
	}
}

task main()
{
	if (vexRT[Btn8U] == 1) {
		togglePneumatics();
	}
}
