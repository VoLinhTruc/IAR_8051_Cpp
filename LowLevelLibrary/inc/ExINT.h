#ifndef _EXINT_H_
#define _EXINT_H_

#include "GPIO.h"
#include "GlobalINT.h"

#define RAISING 1
#define FALLING 0

#define P0ISRFunction(func) _Pragma("vector=P0INT_VECTOR") __interrupt void exInt0(void) \
{\
	func();\
	portClearFlag(PORT0);\
}

#define P1ISRFunction(func) _Pragma("vector=P1INT_VECTOR") __interrupt void exInt1(void) \
{\
	func();\
	portClearFlag(PORT1);\
}

#define P2ISRFunction(func) _Pragma("vector=P2INT_VECTOR") __interrupt void exInt2(void) \
{\
	func();\
	portClearFlag(PORT2);\
}


static void pinClearFlag(uint8_t pin)
{
	if BELONG_TO_PORT0(pin)
	{
		P0IFG &= ~(1<< (pin - PORT0));
		P0IF = 0;
	}

	if BELONG_TO_PORT1(pin)
	{
		P1IFG &= ~(1<< (pin - PORT1));
		P1IF = 0;
	}

	if BELONG_TO_PORT2(pin)
	{
		P2IFG &= ~(1<< (pin - PORT2));
		P2IF = 0;
	}
}

static void portClearFlag(uint8_t port)
{
	if(port == PORT0)
	{
		P0IFG = 0;
		P0IF = 0;
	}
	if(port == PORT1)
	{
		P1IFG = 0;
		P1IF = 0;
	}
	if(port == PORT2)
	{
		P2IFG = 0;
		P2IF = 0;
	}
}

extern void pinInterruptSwitch(uint8_t pin, uint8_t mode);
extern void portInterruptSwitch(uint8_t port, uint8_t mode);

extern void egdeSelectionP0(uint8_t sel);
extern void egdeSelectionP1_0ToP1_3(uint8_t sel);
extern void egdeSelectionP1_4ToP1_7(uint8_t sel);
extern void egdeSelectionP2_0ToP2_4(uint8_t sel);

#endif