#ifndef _CONFIG_H__
#define _CONFIG_H__

//these are per-configuration settings

#define STEPPER_STOP 2000
#define STEPPER_MAX_SPEED 400
#define STEPPER_ACCEL 50


//pins
//
//


//should have 4 pins here:
#define STEPPER_PINS 2,3,4,5
//#define STEPPER_PINS 5,4,3,2 //reverse polarity

#define IR_PIN	8
#define RED_PIN	11 //for some reason, red and green pins are swapped on the module
#define BLU_PIN 11
#define GRN_PIN 13 //.

#endif
