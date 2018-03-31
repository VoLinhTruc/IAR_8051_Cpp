#ifndef _CCINO_GPIO_H_
#define _CCINO_GPIO_H_

#include "GPIO.h"

#ifndef HIGH
	#define HIGH 1
#endif

#ifndef LOW
	#define LOW 0
#endif

#ifndef LSBFIRST
#define LSBFIRST 0x80 //0x80 cho phu hop voi thu vien SPI
#endif

#ifndef MSBFIRST
#define MSBFIRST 0x00 //0x00 cho phu hop voi thu vien SPI
#endif

#define OUTPUT 0
#define INPUT 1
#define INPUT_PULLUP 2
#define INPUT_PULLDOWN 3

extern void pinMode(uint8_t pin, uint8_t mode);
extern void digitalWrite(uint8_t pin, uint8_t val);
extern void digitalWriteReverse(uint8_t pin);
extern uint8_t digitalRead(uint8_t pin);

extern void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);

#endif