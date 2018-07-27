#include <AFMotor.h>

// Create the motor shield object with the default I2C address
// AF_DCMotor AFMS = Adafruit_MotorShield();

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup()
{

}

void loop()
{
	motor1.run(FORWARD);
	motor2.run(FORWARD);

	for (int i = 0; i < 255; i++)
	{
		motor1.setSpeed(i);
		motor2.setSpeed(i);
		delay(30);
	}

	for (int i = 255; i >= 0; i--)
	{
		motor1.setSpeed(i);
		motor2.setSpeed(i);
		delay(30);
	}

	motor1.run(RELEASE);
	motor2.run(RELEASE);

	motor1.setSpeed(150);
	motor2.setSpeed(150);

	for (int i = 0; i < 50; i++)
	{
		motor1.run(BACKWARD);
		delay(300);
		motor1.run(RELEASE);

		motor2.run(BACKWARD);
		delay(300);
		motor2.run(RELEASE);
	}
}
