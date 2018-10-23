#include <AccelStepper.h> //1.58.0
#include <IRremote.h> //2.2.3
#include "config.h"
#include "XC3718_codes.h"
#include "led.h"

AccelStepper s_motor(8,STEPPER_PINS);
IRrecv		 ir_recv(IR_PIN);			//pin 8

decode_results ir_res;

RGBLed led(RED_PIN,BLU_PIN,GRN_PIN);

long full_position = 0;

bool homed = false;
bool moving = false;
bool daylight = false;

short status = RESET;
short last = 0;
long val = 0;

void setup(){
	s_motor.setMaxSpeed(STEPPER_MAX_SPEED);
	s_motor.setAcceleration(STEPPER_ACCEL);
	s_motor.setSpeed(STEPPER_MAX_SPEED);

	Serial.begin(9600);
	Serial.println("OK");
	pinMode(RED_PIN,OUTPUT); //this should be in led.cpp tbh
	pinMode(BLU_PIN,OUTPUT);
	pinMode(GRN_PIN,OUTPUT);


	ir_recv.enableIRIn();
}

void loop(){

	val = 0;
	
	if(ir_recv.decode(&ir_res)){
		val = ir_res.value;
		ir_recv.resume();
	}


	switch(status){
		case RESET:		//first state, not sure how anything is
			if(val == XC_CH){ //if the user presses the CH button
				homed = true;
				status = HOMED;	//store this as point 0;
				Serial.println("set home");
			}
			break;

		case HOMED:		//Knows where 0 is
			if(val == XC_CHUP){
				Serial.println(F("moving " INT_STR));
				s_motor.move(INTERVAL);
				last = +INTERVAL;
				status = MOVING;
			}
			else if (val == XC_CHDOWN){
				Serial.println(F("moving -" INT_STR));
				s_motor.move(-INTERVAL);
				last = -INTERVAL;
				status = MOVING;
			}
			else if (val == XC_CH){
				Serial.println("storing value and homing");
				full_position = s_motor.currentPosition();
				last = 0;
				s_motor.moveTo(0);
				status = MOVING;
			}
			else if (val == XC_REPEAT){			//repeat the last command
				s_motor.move(last);
				s_motor.runSpeed();				//keep it moving
				status = MOVING; //still moving
			}
			break;

		case MOVING:	//Moving to another position
			if(val == XC_PLAY)
				status = PAUSE;
			else
				s_motor.run();
				if (s_motor.distanceToGo() == 0)
					if (full_position != 0)	//we've set a full_position
						status = WAITING;	//waiting for more commands
					else
						status = HOMED;		//homed but no limit set
			break;

		case PAUSE:
			if(val == XC_PLAY)
				status = MOVING;
			//do nothing
			Serial.println("paused");
			break;

		case WAITING:	//waiting for solar or remote

			if(XC_INT(val) > -1 && XC_INT(val) < 100){ 			//move to specific percentage
				long move_val = map(XC_INT(val),0,10,0,full_position);
				Serial.print("move to ");
				Serial.print(move_val);
				Serial.print(" out of ");
				Serial.print(full_position);
				Serial.print(" - ");
				Serial.println(XC_INT(val),DEC);

				s_motor.moveTo(move_val);
				status = MOVING;
			} else {

			//read analog pin and set percentage
			
			long move_val = map(analogRead(A0),0,MAX_SOLAR_PANEL,0,full_position);

			}
			
			break;
	}

	blink_status();
}

void blink_status(){

	switch(status){
		case RESET:
			led.blink_red();
			break;
		case HOMED:
			led.blink_grn();
			break;
		case WAITING:
				//no blink
			break;
		case MOVING:
			led.blink_blu();
		default:
			led.clear_all();
	}

	led.refresh();
}
