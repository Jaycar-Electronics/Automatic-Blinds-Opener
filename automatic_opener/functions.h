#ifndef _FUNCTIONS_H__
#define _FUNCTIONS_H__

unsigned short blink_status(); //blink the status on the LED. do this first so that it can enable failsafe

//motor functions

void full_open();
void full_close();

void set_open(unsigned short percentage);

unsigned short read_panel();


#define WAIT 1
#define MOVING 2
#define RESET 4

#endif
