#ifndef _CONFIG_H__
#define _CONFIG_H__

//these are per-configuration settings

#define STEPPER_MAX_SPEED 400
#define STEPPER_ACCEL 50


#define MAX_SOLAR_PANEL 9999 //define this with your position!


#define INTERVAL 10			//minimal step while homing and setting position, only during setup
#define INT_STR "10"		//string of the above

//should have 4 pins here:
#define STEPPER_PINS 2,3,4,5
//#define STEPPER_PINS 5,4,3,2 //reverse polarity

#define IR_PIN	8
#define RED_PIN	11 //for some reason, red and green pins are swapped on the module
#define BLU_PIN 11 //
#define GRN_PIN 13 //.


#define WAITING 1
#define MOVING 2
#define RESET 3
#define HOMED 4
#define PAUSE 5


#endif
