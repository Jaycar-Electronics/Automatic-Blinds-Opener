#ifndef _LED_H__
#define _LED_H__


#define R_BLINK 500
#define B_BLINK 100
#define G_BLINK 1000

typedef struct{
	short pin;
	bool on;
	long timer;
	bool active;
} _rgbLED;

class RGBLed{

public:
	_rgbLED r,g,b;

	RGBLed(short, short, short);


	void blink_red(bool clear_others = false);
	void blink_grn(bool clear_others = false);
	void blink_blu(bool clear_others = false);

	void refresh();

	void clear_all();

};

#endif
