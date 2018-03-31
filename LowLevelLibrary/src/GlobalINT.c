#include "GlobalINT.h"

void GlobalInterruptSwitch(uint8_t mode)
{
	EA = mode;
}

void P0InterruptSwitch(uint8_t mode)
{
	P0IE = mode;
}

void P1InterruptSwitch(uint8_t mode)
{
	if(mode == ON)
		IEN2 |= (1<<4);
	else if(mode == OFF)
		IEN2 &= ~(1<<4);
}

void P2InterruptSwitch(uint8_t mode)
{
	if(mode == ON)
		IEN2 |= (1<<1);
	else if(mode == OFF)
		IEN2 &= ~(1<<1);
}

void URX0InterruptSwitch(uint8_t mode)
{
  	if(mode == ON)
          IEN0 |= (1<<2);
	else if(mode == OFF)
          IEN0 &= ~(1<<2);
}

void URX1InterruptSwitch(uint8_t mode)
{
  	if(mode == ON)
          IEN0 |= (1<<3);
	else if(mode == OFF)
          IEN0 &= ~(1<<3);
}