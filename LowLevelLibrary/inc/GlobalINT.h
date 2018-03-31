#ifndef _GLOBALINT_H_
#define _GLOBALINT_H_

#include "Generic.h"

#define ON 1
#define OFF 0

extern void GlobalInterruptSwitch(uint8_t mode);

extern void P0InterruptSwitch(uint8_t mode);
extern void P1InterruptSwitch(uint8_t mode);
extern void P2InterruptSwitch(uint8_t mode);

extern void URX0InterruptSwitch(uint8_t mode);
extern void URX1InterruptSwitch(uint8_t mode);

#endif