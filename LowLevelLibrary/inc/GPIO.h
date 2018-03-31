#ifndef _GPIO_H_
#define _GPIO_H_

#include "Generic.h"

#define PORT_GPIO 0
#define PORT_PERIPHERAL 0xFF
#define PORT_INPUT 0
#define PORT_OUTPUT 0xFF

#define PIN_GPIO 0
#define PIN_PERIPHERAL 1
#define PIN_INPUT 0
#define PIN_OUTPUT 1

//Chu y: Tren mot Port thi tat ca cac pin dong thoi PULLUP hoac PULLDOWN, nen khi ung dung ta chi duoc define PULLUP hoac PULL_DOWN, khong duoc define ca hai
#define PORT_PULLUP 0
// #define PORT_PULLDOWN 0
#define PORT_PULLNONE 0xFF
//Chu y: Tren mot Port thi tat ca cac pin dong thoi PULLUP hoac PULLDOWN,  nen khi ung dung ta chi duoc define PULLUP hoac PULL_DOWN, khong duoc define ca hai
#define PIN_PULLUP 0
// #define PIN_PULLDOWN 0
#define PIN_PULLNONE 1

#define PORT0 0
#define PORT1 8
#define PORT2 16

#define PIN0_0 0
#define PIN0_1 1
#define PIN0_2 2
#define PIN0_3 3
#define PIN0_4 4
#define PIN0_5 5
#define PIN0_6 6
#define PIN0_7 7

#define PIN1_0 8
#define PIN1_1 9
#define PIN1_2 10
#define PIN1_3 11
#define PIN1_4 12
#define PIN1_5 13
#define PIN1_6 14
#define PIN1_7 15

#define PIN2_0 16
#define PIN2_1 17
#define PIN2_2 18
#define PIN2_3 19
#define PIN2_4 20

/*
Ly do khong lam kieu ((n>=0) && (n<=7)), ((n>=8) && (n<=15)), ((n>=16) && (n<=20))
la vi phep so sanh '<=' hay '>=' se lau hon '<' hay '>'
*/
#define BELONG_TO_PORT0(pin) ((pin<8))
#define BELONG_TO_PORT1(pin) ((pin>7) && (pin<16))
#define BELONG_TO_PORT2(pin) ((pin>15) && (pin<21))

extern void pinFunction(uint8_t pin, uint8_t func);
extern void portFunction(uint8_t port, uint8_t func);

extern void pinDirect(uint8_t pin, uint8_t dir);
extern void portDirect(uint8_t port, uint8_t dir);

extern void pinPull(uint8_t pin, uint8_t pull);
extern void portPull(uint8_t port, uint8_t pull);

extern void pinWrite(uint8_t pin, uint8_t val);
extern void portWrite(uint8_t port, uint8_t val);

extern uint8_t pinRead(uint8_t pin);
extern uint8_t portRead(uint8_t port);

#endif