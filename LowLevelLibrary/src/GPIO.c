#include "GPIO.h"

void pinFunction(uint8_t pin, uint8_t func)
{
	if BELONG_TO_PORT0(pin)
		if(func == PIN_PERIPHERAL)
			P0SEL |= (1<< (pin - PORT0));
		else if(func == PIN_GPIO)
			P0SEL &= ~(1<< (pin - PORT0));

	if BELONG_TO_PORT1(pin)
		if(func == PIN_PERIPHERAL)
			P1SEL |= (1<< (pin - PORT1));
		else if(func == PIN_GPIO)
			P1SEL &= ~(1<< (pin - PORT1));

	if BELONG_TO_PORT2(pin)
		if(func == PIN_PERIPHERAL)
			P2SEL |= (1<< (pin - PORT2));
		else if(func == PIN_GPIO)
			P2SEL &= ~(1<< (pin - PORT2));
}

void portFunction(uint8_t port, uint8_t func)
{
	if(port == PORT0)
		P0SEL = func;
	if(port == PORT1)
		P1SEL = func;
	if(port == PORT2)
		P2SEL = func;
}

void pinDirect(uint8_t pin, uint8_t dir)
{
	if BELONG_TO_PORT0(pin)
		if(dir == PIN_OUTPUT)
			P0DIR |= (1<< (pin - PORT0));
		else if(dir == PIN_INPUT)
			P0DIR &= ~(1<< (pin - PORT0));

	if BELONG_TO_PORT1(pin)
		if(dir == PIN_OUTPUT)
			P1DIR |= (1<< (pin - PORT1));
		else if(dir == PIN_INPUT)
			P1DIR &= ~(1<< (pin - PORT1));

	if BELONG_TO_PORT2(pin)
		if(dir == PIN_OUTPUT)
			P2DIR |= (1<< (pin - PORT2));
		else if(dir == PIN_INPUT)
			P2DIR &= ~(1<< (pin - PORT2));
}

void portDirect(uint8_t port, uint8_t dir)
{
	if(port == PORT0)
		P0DIR = dir;
	if(port == PORT1)
		P1DIR = dir;
	if(port == PORT2)
		P2DIR = dir;
}

//Chu y: Tren mot Port thi tat ca cac pin dong thoi PULLUP hoac PULLDOWN, nen khi ung dung ta chi duoc define PULLUP hoac PULL_DOWN, khong duoc define ca hai
void pinPull(uint8_t pin, uint8_t pull)
{
	if(pull == PIN_PULLNONE)
	{
		if BELONG_TO_PORT0(pin)
			P0INP |= (1 << (pin - PORT0));

		if BELONG_TO_PORT1(pin)
			P1INP |= (1 << (pin - PORT1));

		if BELONG_TO_PORT2(pin)
			P2INP |= (1 << (pin - PORT2));
	}
	else if(pull != PIN_PULLNONE)
	{
		#ifdef PIN_PULLUP
		P2INP &= ~(1<<5);
		P2INP &= ~(1<<6);
		P2INP &= ~(1<<7);
		#endif

		#ifdef PIN_PULLDOWN
		P2INP |= (1<<5);
		P2INP |= (1<<6);
		P2INP |= (1<<7);
		#endif

		if BELONG_TO_PORT0(pin)
			P0INP &= ~(1 << (pin - PORT0));

		if BELONG_TO_PORT1(pin)
			P1INP &= ~(1 << (pin - PORT1));

		if BELONG_TO_PORT2(pin)
			P2INP &= ~(1 << (pin - PORT2));
	}
}

void portPull(uint8_t port, uint8_t pull)
{
	if(pull != PORT_PULLNONE)
	{
		#ifdef PIN_PULLUP
		P2INP &= ~(1<<5);
		P2INP &= ~(1<<6);
		P2INP &= ~(1<<7);
		#endif

		#ifdef PIN_PULLDOWN
		P2INP |= (1<<5);
		P2INP |= (1<<6);
		P2INP |= (1<<7);
		#endif
	}

	if(port == PORT0)
		P0INP = pull;
	if(port == PORT1)
		P1INP = pull;
	if(port == PORT2)
		P2INP = pull;
}

void pinWrite(uint8_t pin, uint8_t val)
{
	if (val)
	{
		if BELONG_TO_PORT0(pin)
			P0 |= (1 << (pin - PORT0));

		if BELONG_TO_PORT1(pin)
			P1 |= (1 << (pin - PORT1));

		if BELONG_TO_PORT2(pin)
			P2 |= (1 << (pin - PORT2));
	}
	else
	{
		if BELONG_TO_PORT0(pin)
			P0 &= ~(1 << (pin - PORT0));

		if BELONG_TO_PORT1(pin)
			P1 &= ~(1 << (pin - PORT1));

		if BELONG_TO_PORT2(pin)
			P2 &= ~(1 << (pin - PORT2));
	}
}

void portWrite(uint8_t port, uint8_t val)
{
	if(port == PORT0)
		P0 = val;
	if(port == PORT1)
		P1 = val;
	if(port == PORT2)
		P2 = val;
}

uint8_t pinRead(uint8_t pin)
{
	uint8_t val;

	if BELONG_TO_PORT0(pin)
		val = (P0 & (1 << (pin - PORT0)));

	if BELONG_TO_PORT1(pin)
		val = (P1 & (1 << (pin - PORT1)));

	if BELONG_TO_PORT2(pin)
		val = (P2 & (1 << (pin - PORT2)));

	return val;
}

uint8_t portRead(uint8_t port)
{
	uint8_t val;

	if(port == PORT0)
		val = P0;
	if(port == PORT1)
		val = P1;
	if(port == PORT2)
		val = P2;
	
	return val;
}