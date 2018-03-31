#include "CCINO_GPIO.h"

void pinMode(uint8_t pin, uint8_t mode)
{
	pinFunction(pin, PIN_GPIO);

	if((mode == INPUT) || (mode == INPUT_PULLUP) || (mode == INPUT_PULLDOWN))
	{
		pinDirect(pin, PIN_INPUT);

		if(mode == INPUT)
			pinPull(pin, PIN_PULLNONE);

		#ifdef PIN_PULLUP
		if(mode == INPUT_PULLUP)
			pinPull(pin, PIN_PULLUP);
		#endif

		#ifdef PIN_PULLDOWN
		if(mode == INPUT_PULLDOWN)
			pinPull(pin, PIN_PULLDOWN);
		#endif
	}
	else if(mode == OUTPUT)
	{
		pinDirect(pin, PIN_OUTPUT);
	}
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	pinWrite(pin, val);
}

uint8_t digitalRead(uint8_t pin)
{
	return pinRead(pin);
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
	uint8_t i;

	for (i = 0; i < 8; i++)  {
		if (bitOrder == LSBFIRST)
			digitalWrite(dataPin, !!(val & (1 << i)));
		else	
			digitalWrite(dataPin, !!(val & (1 << (7 - i))));
			
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);		
	}
}