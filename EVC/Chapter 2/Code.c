#pragma config(Sensor, S1,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     nxtcolor,       sensorLightActive)
#pragma config(Sensor, S3,     ev3color,       sensorEV3_Color)
#pragma config(Sensor, S4,     sonic,          sensorEV3_Ultrasonic)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define MOTOR_STOP 0
#define POINT_TURN_RIGHT 1
#define POINT_TURN_LEFT 2
#define GO_STRAIGHT 3
#define GO_BACK 4

void MotorControl(int control, int time = 0);
bool isLine(int threshold = 30);
bool isTouched();

task main()
{
	/*
	TouchSensor
	while (SensorValue(touch) == 0) {
		MotorControl(GO_STRAIGHT);
	}
	*/

	/*
	ColorSensor
	//Should be Optimized By Environment
	int threshold = 40;
	while (SensorValue(ev3color) > threshold) {
		MotorControl(GO_STRAIGHT);
	}
	*/

	/*
	SonicSensor
	//Distance in cm
	int distance = 10;
	while(SensorValue(sonic) >= 10) {
		MotorControl(GO_STRAIGHT);
	}
	*/

	while (isTouched()) {
		MotorControl(GO_STRAIGHT);
	}
	MotorControl(MOTOR_STOP, 500);
	MotorControl(GO_BACK, 150);
	MotorControl(MOTOR_STOP, 500);
	MotorControl(POINT_TURN_RIGHT);
	MotorControl(MOTOR_STOP, 500);

	while (isTouched()) {
		MotorControl(GO_STRAIGHT);
	}
	MotorControl(MOTOR_STOP, 500);
	MotorControl(GO_BACK, 150);
	MotorControl(POINT_TURN_RIGHT);
	MotorControl(MOTOR_STOP, 500);
	MotorControl(MOTOR_STOP, 500);

	while (isTouched()) {
		MotorControl(GO_STRAIGHT);
	}
	MotorControl(MOTOR_STOP, 500);
	MotorControl(GO_BACK, 400);
	MotorControl(POINT_TURN_LEFT);
	MotorControl(MOTOR_STOP, 500);
	MotorControl(MOTOR_STOP, 500);

	while (!isLine()) {
		MotorControl(GO_STRAIGHT);
	}

		MotorControl(MOTOR_STOP);

	while(SensorValue(sonic) > 30) {
		MotorControl(MOTOR_STOP);
	}

	delay(1000);

	while (isTouched()) {
		MotorControl(GO_STRAIGHT);
	}
	MotorControl(MOTOR_STOP, 500);
	MotorControl(GO_BACK, 400);
	MotorControl(MOTOR_STOP, 500);
	MotorControl(POINT_TURN_RIGHT);
	MotorControl(MOTOR_STOP, 500);

	while (isTouched()){
		MotorControl(GO_STRAIGHT);
	}

	while (!isLine()){
		MotorControl(GO_BACK);
	}

	MotorControl(MOTOR_STOP);

}

void MotorControl(int control, int time) {
	switch(control) {
		case MOTOR_STOP:
			motor[motorA] = 0;
			motor[motorD] = 0;
			delay(time);
			break;
		case POINT_TURN_LEFT:
			motor[motorA] = -50;
			motor[motorD] = 50;
			delay(400);
			break;
		case POINT_TURN_RIGHT:
			motor[motorA] = 50;
			motor[motorD] = -50;
			delay(400);
			break;
		case GO_STRAIGHT:
			motor[motorA] = 50;
			motor[motorD] = 50;
			delay(time);
			break;
		case GO_BACK:
			motor[motorA] = -50;
			motor[motorD] = -50;
			delay(time);
			break;
	}

}

bool isLine(int threshold) {
	return SensorValue(ev3color) < threshold;
}

bool isTouched() {
	return SensorValue(touch) == 0;
}
