#ifndef __XC3718_CODES_H__
#define __XC3718_CODES_H__

// ****
// this is a code define file to make it a little easier to use the XC3718 remote control.
// include this in your projects, along with the IRremote.h library from the arduino library manager
//
// IRremote Library by shirriff, version 2.2.3 as of the time of this writing.
//
// simply include the library and use as normal, but use if(code == XC_PREV) to test if the receive button is pressed, 
// similar for other buttons.
// 
// you can also use XC_STR(code) and XC_INT(code) to convert into string names or int values (for the numbers)
//
// comment out the below so that XC_CODE_STRINGS is undefined, if you do not need to "decode" into strings.
// doing so will save a bit of memory
#define XC_CODE_STRINGS
//

#define XC_CHDOWN	0xffa25d
#define XC_CH		0xff629d
#define XC_CHUP		0xffe21d

#define XC_PREV		0xff22dd
#define XC_NEXT		0xff02fd
#define XC_PLAY		0xffc23d

#define XC_VOLDOWN	0xffe01f
#define XC_VOLUP	0xffa857
#define XC_EQ		0xff906f

#define XC_0		0xff6897
#define XC_100		0xff9867
#define XC_200		0xffb04f

#define XC_1		0xff30cf
#define XC_2		0xff18ef
#define XC_3		0xff7a85
#define XC_4		0xff10ef
#define XC_5		0xff38c7
#define XC_6		0xff5aa5
#define XC_7		0xff42bd
#define XC_8		0xff4ab5
#define XC_9		0xff52ad

#define XC_REPEAT	0xffffff

#ifdef XC_CODE_STRINGS

#define XC_STR(x) (x==XC_0?"0":\
	x== XC_CHDOWN	?"Channel Down":\
	x== XC_CH		?"Channel":\
	x== XC_CHUP		?"Channel Up":\
	x== XC_PREV		?"Previous":\
	x== XC_NEXT		?"Next":\
	x== XC_PLAY		?"Play":\
	x== XC_VOLDOWN	?"Vol Down":\
	x== XC_VOLUP	?"Vol Up":\
	x== XC_EQ		?"EQ":\
	x== XC_REPEAT	?"Repeat":\
	x== XC_0		?"0":\
	x== XC_100		?"100+":\
	x== XC_200		?"200+":\
	x== XC_1		?"1":\
	x== XC_2		?"2":\
	x== XC_3		?"3":\
	x== XC_4		?"4":\
	x== XC_5		?"5":\
	x== XC_6		?"6":\
	x== XC_7		?"7":\
	x== XC_8		?"8":\
	x== XC_9		?"9":"Unknown")
#endif
#define XC_INT(x) (x==XC_0?0:\
		x==XC_1?1:\
		x==XC_2?2:\
		x==XC_3?3:\
		x==XC_4?4:\
		x==XC_5?5:\
		x==XC_6?6:\
		x==XC_7?7:\
		x==XC_8?8:\
		x==XC_9?9:\
		x==XC_100?100:\
		x==XC_200?200:-1)\

#endif
