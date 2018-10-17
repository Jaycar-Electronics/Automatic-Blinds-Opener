#include <AccelStepper.h> //1.58.0
#include "functions.h"
#include "config.h"
#include "XC3718_codes.h"

AccelStepper s_motor(8,STEPPER_PINS);
IRrecv		 ir_recv(IR_PIN);			//pin 12
void setup(){
	s_motor.setMaxSpeed(STEPPER_MAX_SPEED);
	s_motor.setAcceleration(STEPPER_ACCEL);
	s_motor.setSpeed(STEPPER_MAX_SPEED);
}

void loop(){

	switch(blink_status()){

	case RESET:		//this is a "fresh reset" case, when the unit has not been reset and doesn't know where it is

		//do nothing until configured.
		if(I
		break;

	case WAIT:
		break;

	case MOVING:
		break;

	}

	delay(1000);
}
