
#include "led.h"
#include <Arduino.h>

#define CLR(x,y) (x.active = false; y.active = false;)

RGBLed::RGBLed(short rp, short gp, short bp){

	this->r = {rp,false,0,false};
	this->g = {gp,false,0,false};
	this->b = {bp,false,0,false};
	
}

void RGBLed::blink_red(bool clear_others){
	
	long now = millis();
	if((now - this->r.timer) > R_BLINK){
		this->r.on = !this->r.on;
		this->r.timer = now;
	}
	this->r.active = true;

	if(clear_others){
		this->g.active = false;
		this->b.active = false;
	}
}

void RGBLed::blink_grn(bool clear_others){
	
	long now = millis();
	if((now - this->g.timer) > G_BLINK){
		this->g.on = !this->g.on;
		this->g.timer = now;
	}
	this->g.active = true;
	if(clear_others){
		this->r.active = false;
		this->b.active = false;
	}
}
void RGBLed::blink_blu(bool clear_others){
	
	long now = millis();
	if((now - this->b.timer) > B_BLINK){
		this->b.on = !this->b.on;
		this->b.timer = now;
	}
	this->b.active = true;

	if(clear_others){
		this->g.active = false;
		this->r.active = false;
	}

}
void RGBLed::clear_all(){
	this->g.active = false;
	this->r.active = false;
	this->b.active = false;
}
void RGBLed::refresh(){

	if(this->r.on && this->r.active)
		digitalWrite(this->r.pin,HIGH);
	else
		digitalWrite(this->r.pin,LOW);

	if(this->g.on && this->g.active)
		digitalWrite(this->g.pin,HIGH);
	else
		digitalWrite(this->g.pin,LOW);

	if(this->b.on && this->b.active)
		digitalWrite(this->b.pin,HIGH);
	else
		digitalWrite(this->b.pin,LOW);

}
