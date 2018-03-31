#ifndef _UART_H_
#define _UART_H_

#include "Generic.h"

#define SPI_MODE 0
#define UART_MODE 1

#define UART_RECEIVER_ENABLE 1
#define UART_RECEIVER_DISABLE 0

#define UART0_START 1
#define UART0_STOP 0

#define UART0_P02_P03 0
#define UART0_P14_P15 1
#define UART1_P05_P04 0
#define UART1_P07_P06 1

#define SPI0_P02_TO_P05 0 
#define SPI0_P12_TO_P15 1
#define SPI1_P02_TO_P05 0
#define SPI1_P14_TO_P17 1

#define SPI_MODE 0
#define UART_MODE 1

#define URX0ISRFunction(func) _Pragma("vector=URX0_VECTOR") __interrupt void urx0Int0(void) \
{\
	func();\
}

#define URX1ISRFunction(func) _Pragma("vector=URX1_VECTOR") __interrupt void urx1Int0(void) \
{\
	func();\
}


// UART0
extern void UART0AssignLocation(uint8_t sel);	//PERCFG.U0CFG, See table 7.1
extern void UART0ModeSel(uint8_t mode);	//MODE
extern void UART0ReceiverEn(uint8_t sel);	//RE, 1 is En, 0 is Dis
extern void UART0DiscardDataBuff();	//write to RX_BYTE
extern uint8_t UART0IsReceiving();	//read from RX_BYTE
extern uint8_t UART0TranmissionCompleted();	//TX_BYTE
extern uint8_t UART0IsBusy();	//ACTIVE
extern void UART0SetBaud(unsigned long baud);	//BAUD bit and U0BAUD reg
extern uint8_t UART0GetData();	//DATA reg
extern void UART0FillData(uint8_t data);	//DATA reg

// UART1
extern void UART1AssignLocation();	//PERCFG.U1CFG, See table 7.1
extern void UART1ModeSel(uint8_t mode);	//MODE
extern void UART1ReceiverEn(uint8_t sel);	//RE
extern void UART1DiscardDataBuff();	//write to RX_BYTE
extern uint8_t UART1IsReceiving();	//read from RX_BYTE
extern uint8_t UART1TranmissionCompleted();	//TX_BYTE
extern uint8_t UART1IsBusy();	//ACTIVE
extern void UART1SetBaud(unsigned long baud);	//BAUD bit and U1BAUD reg
extern uint8_t UART1GetData();	//DATA reg
extern void UART1FillData(uint8_t data); //DATA reg


#endif