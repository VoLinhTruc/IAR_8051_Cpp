#ifndef _ADC_H_
#define _ADC_H_

#include "GPIO.h"

#define CONVERTION_COMPLETED 1

#define EX_TRIG 0
#define FULLSPEED_NOTWAIT 1
#define T1_CHANNEL0 2
#define SETBIT_ST 3

#define IN_REF 0
#define EX_REF 1
#define AVDD5 2
#define A6_A7 3

#define DEC_RATE_64 0   // 7 ENOB(Effective number of bit)
#define DEC_RATE_128 1  // 9 ENOB(Effective number of bit)
#define DEC_RATE_256 2  // 11 ENOB(Effective number of bit)
#define DEC_RATE_512 3  // 13 ENOB(Effective number of bit)
//addition defination to easily select resolution
#define RESOLUTION_7BIT DEC_RATE_64
#define RESOLUTION_9BIT DEC_RATE_128
#define RESOLUTION_11BIT DEC_RATE_256
#define RESOLUTION_13BIT DEC_RATE_512

#define AIN0 0
#define AIN1 1
#define AIN2 2
#define AIN3 3
#define AIN4 4
#define AIN5 5
#define AIN6 6
#define AIN7 7
#define AIN0_AIN1 8
#define AIN2_AIN3 9
#define AIN4_AIN5 10
#define AIN6_AIN7 11
#define GND 12
#define RESERVED 13
#define TEMPERATURE 14
#define VDD_DIV_3 15


extern uint8_t enableADCPin(uint8_t pin);
extern uint8_t disableADCPin(uint8_t pin);

extern uint8_t completedConvertion();
extern void startConvertion();
extern uint8_t isInConvertion();
extern void selectStartCondition(uint8_t sel);

extern void referenceVoltage(uint8_t sel);
extern void selectDecimationRate(uint8_t sel);
extern void channelSeleted(uint8_t sel);

extern void singleConversionreferenceVoltage(uint8_t sel);
extern void singleConversionselectDecimationRate(uint8_t sel);
extern void singleConversionchannelSeleted(uint8_t sel);

extern void connectTemSensorToADC(uint8_t sel);

extern int readResult();

#endif