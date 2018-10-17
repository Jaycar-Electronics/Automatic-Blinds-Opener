# Automatic Blinds Opener
Let the power of the sun encourage you to get out of bed each morning with this curtain/blinds opener. We’ve made a little motor/solar panel combo that will automatically open your blinds at sunrise and close at sunset. We've also included a remote so you can open and shut them whenever you want.

## Bill of Materials
| Qty | Product | Description |
| :------------- | :------------- | ---- |
|1 | [YM2756](http://jaycar.com.au/p/YM2756) | NEMA stepper motor|
|1 | [XC4427](http://jaycar.com.au/p/XC4427) | Infra-red reciver module|
|1 | [XC3718](http://jaycar.com.au/p/XC3718) | IR Remote|
|1 | [XC4428](http://jaycar.com.au/p/XC4428) | RGB LED module|
|1 | [ZM9015](http://jaycar.com.au/p/ZM9015) | 1.5V Solar panel|
|1 | [XC4492](http://jaycar.com.au/p/XC4492) | Stepper motor controller  |
| 1| [XC4430](http://jaycar.com.au/p/XC4430) | Duinotech Leonardo |

Our prototype from the picture also had the following, but you can use any case to fit it in:

| Qty | Product | Description |
| :------------- | :------------- | ---- |
|1 | [HB6216](http://jaycar.com.au/p/HB6216) | Enclosure |
|1 | [WC6028](http://jaycar.com.au/p/WC6028) | Jumper leads |


## Software

| Library | Author | Version |
| :------------- | :------------- | --- |
| AccelStepper | Mike McCauley | 1.58.0 |
| IRremote | shirriff | 2.2.3 |

* Also be sure to download the [XC3718 codes helper]()

## Connection Table

| Leonardo | Connection | Device |
| --- | --- | --- |
| 3 | IN1 | Motor Controller |  
| 4 | IN2 | Motor Controller |
| 5 | IN3 |  Motor Controller |
| 6 | IN4 |  Motor Controller |
| A0 | + | Solar panel |
| GND | - |  Solar panel |
|13 | R| RGB LED module |
|12 | G|  RGB LED module |
|11 | B|  RGB LED module | 


## Assembly

## Programming

## Use
