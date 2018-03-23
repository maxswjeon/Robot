const int	POINT_TURN_RIGHT = 1;
const int POINT_TURN_LEFT = 2;

void MotorControl(int control);
void MotorControl(int time, int speed_left, int speed_right);

task main()
{
	MotorControl(3000, 50, 50);
	MotorControl(POINT_TURN_RIGHT);
	MotorControl(3500, 50, 50);
	MotorControl(POINT_TURN_RIGHT);
	MotorControl(3500, 50, 50);
	MotorControl(POINT_TURN_LEFT);
	MotorControl(5000, 50, 50);

}

void MotorControl(int time, int speed_left, int speed_right) {
	motor[motorA] = speed_left;
	motor[motorD] = speed_right;

	delay(time);
}

void MotorControl(int control) {
	switch(control) {
		case POINT_TURN_LEFT:
			motor[motorA] = -50;
			motor[motorD] = 50;
			break;
		case POINT_TURN_RIGHT:
			motor[motorA] = 50;
			motor[motorD] = -50;
			break;
	}
	delay(315);
}
