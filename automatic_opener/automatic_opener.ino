#include <AccelStepper.h> //1.58.0
#include <IRremote.h> //2.2.3
#include "functions.h"
#include "config.h"
#include "XC3718_codes.h"

AccelStepper s_motor(8,STEPPER_PINS);
IRrecv		 ir_recv(IR_PIN);			//pin 12

long full_position;

bool homed = false;
bool moving = false;
bool daylight = false;

decode_results ir_res;

void setup(){
	s_motor.setMaxSpeed(STEPPER_MAX_SPEED);
	s_motor.setAcceleration(STEPPER_ACCEL);
	s_motor.setSpeed(STEPPER_MAX_SPEED);

  Serial.begin(9600);
  pinMode(RED_PIN,OUTPUT);
  pinMode(BLU_PIN,OUTPUT);
  pinMode(GRN_PIN,OUTPUT);

  pinMode(IR_PIN+1,OUTPUT);   //power the IR sensor
  digitalWrite(IR_PIN+1,HIGH);//off gpio
  pinMode(IR_PIN+2,OUTPUT);   //power the IR sensor
  digitalWrite(IR_PIN+2,LOW);//off gpio

  ir_recv.enableIRIn();
}

void loop(){
	switch(blink_status()){

	case RESET:		//this is a "fresh reset" case, when the unit has not been reset and doesn't know where it is
		//do nothing until configured.
    if(ir_recv.decode(&ir_res)){
      Serial.println(ir_res.value,HEX);
      if( ir_res.value == XC_CH ){
        homed = true;
        while(true){
          ir_recv.resume();
          
          if(ir_recv.decode(&ir_res)){
            switch((long)ir_res.value){
              case XC_CHUP:
                s_motor.runToNewPosition(s_motor.currentPosition()+10); break;
              case XC_CHDOWN:
                s_motor.runToNewPosition(s_motor.currentPosition()-10); break;
              case XC_CH:
                full_position = s_motor.currentPosition();
              default:
                //flash green
                blink(GRN_PIN);
            }
          }
          
        }
      }
    }
		break;

	case WAIT:
   if(ir_recv.decode(&ir_res)){
      if( ir_res.value == XC_PREV ){
        full_close();
      } else if ( ir_res.value == XC_NEXT){
        full_open();
      }

   }
		break;

	case MOVING:
		break;
	}

 ir_recv.resume();
}

// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------

void full_open(){
  s_motor.moveTo(full_position);
}
void full_close(){
  s_motor.moveTo(0);
}

void set_open(unsigned short percentage){
  if (percentage > 100)
    return;
  s_motor.moveTo(full_position * (percentage/100));
}

unsigned short blink_status(){
  turn_off(GRN_PIN);
  
  if(!homed){
    short_blink(RED_PIN);
    return RESET;
  }

  if(moving){
    blink(BLU_PIN);
    return MOVING;
  }

  if(daylight){
    solid_on(GRN_PIN);
  }
  else{
    long_pulse(GRN_PIN); //do not disturb during the night
  }
  return WAIT;
}

void turn_off(short pin){
  digitalWrite(pin,LOW);
}
void solid_on(short pin){
  digitalWrite(pin,HIGH);
}

void short_blink(short pin){

  for(short i = 0; i < 2; i++){
    digitalWrite(pin,HIGH);
    delay(100);
    digitalWrite(pin,LOW);
    delay(100);
  }
  delay(1000);
}
void blink(short pin){
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
  delay(500);
}
void long_pulse(short pin){
  digitalWrite(pin,HIGH);
  delay(400);
  digitalWrite(pin,LOW);
  delay(1200);
}
