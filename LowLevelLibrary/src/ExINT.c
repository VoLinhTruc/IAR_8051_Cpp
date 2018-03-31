#include "ExINT.h"

void pinInterruptSwitch(uint8_t pin, uint8_t mode)
{
	pinClearFlag(pin);

	if BELONG_TO_PORT0(pin)
	{
		if(mode == ON)
			P0IEN |= (1<< (pin - PORT0));
		else if(mode == OFF)
			P0IEN &= ~(1<< (pin - PORT0));
		P0InterruptSwitch(ON);
	}
	if BELONG_TO_PORT1(pin)
	{
		if(mode == ON)
			P1IEN |= (1<< (pin - PORT1));
		else if(mode == OFF)
			P1IEN &= ~(1<< (pin - PORT1));
		P1InterruptSwitch(ON);
	}
	if BELONG_TO_PORT2(pin)
	{
		if(mode == ON)
			P2IEN |= (1<< (pin - PORT2));
		else if(mode == OFF)
			P2IEN &= ~(1<< (pin - PORT2));
		P2InterruptSwitch(ON);
	}

	GlobalInterruptSwitch(ON);
}

void portInterruptSwitch(uint8_t port, uint8_t mode)
{
	portClearFlag(port);

	if(port == PORT0)
	{
		P0IEN = mode;
		P0InterruptSwitch(mode);
	}
	if(port == PORT1)
	{
		P1IEN = mode;
		P1InterruptSwitch(mode);
	}
	if(port == PORT2)
	{
		P2IEN = mode;
		P2InterruptSwitch(mode);
	}

	GlobalInterruptSwitch(ON);
}

void egdeSelectionP0(uint8_t sel)
{
	if(sel == FALLING)
		PICTL |= 1;
	else if(sel == RAISING)
		PICTL &= ~1;
}
void egdeSelectionP1_0ToP1_3(uint8_t sel)
{
	if(sel == FALLING)
		PICTL |= (1<<1);
	else if(sel == RAISING)
		PICTL &= ~(1<<1);
}
void egdeSelectionP1_4ToP1_7(uint8_t sel)
{
	if(sel == FALLING)
		PICTL |= (1<<2);
	else if(sel == RAISING)
		PICTL &= ~(1<<2);
}
void egdeSelectionP2_0ToP2_4(uint8_t sel)
{
	if(sel == FALLING)
		PICTL |= (1<<3);
	else if(sel == RAISING)
		PICTL &= ~(1<<3);
}