#include "UART.h"

// UART0
void UART0AssignLocation(uint8_t sel)	//PERCFG.U0CFG, See table 7.1
{
	if(sel == UART0_P14_P15)
		PERCFG |= sel;
	else if(sel == UART0_P02_P03)
		PERCFG &= ~sel;
}

void UART0ModeSel(uint8_t mode)	//MODE
{
	if(mode == UART_MODE)
		U0CSR |= (mode << 7);
}

void UART0ReceiverEn(uint8_t sel)	//RE
{
	if(sel)
	{
		U0CSR |= (sel << 6);
	}
	else
	{
		U0CSR &= ~(sel << 6);
	}
}

void UART0DiscardDataBuff()	//write to RX_BYTE
{
	U0CSR &= ~(1 << 2);
}

uint8_t UART0IsReceiving()	//read from RX_BYTE
{
	return U0CSR & (1 << 2);
}

uint8_t UART0TranmissionCompleted()	//TX_BYTE
{
	return U0CSR & (1 << 1);
}

uint8_t UART0IsBusy()	//ACTIVE
{
	return U0CSR & 1;
}

void UART0SetBaud(unsigned long baud)	//BAUD bit and U0BAUD reg
{
	switch(baud)
	{
		case 2400: 
		{
			U0BAUD = 59;
			U0GCR = 6;
                        break;
		}

		case 4800: 
		{
			U0BAUD = 59;
			U0GCR = 7;
                        break;
		}

		case 9600: 
		{
			U0BAUD = 59;
			U0GCR = 8;
                        break;
		}

		case 14400: 
		{
			U0BAUD = 216;
			U0GCR = 8;
                        break;
		}

		case 19200: 
		{
			U0BAUD = 59;
			U0GCR = 9;
                        break;
		}

		case 28800: 
		{
			U0BAUD = 216;
			U0GCR = 9;
                        break;
		}

		case 38400: 
		{
			U0BAUD = 59;
			U0GCR = 10;
                        break;		}

		case 57600: 
		{
			U0BAUD = 216;
			U0GCR = 10;
                        break;
		}

		case 76800: 
		{
			U0BAUD = 59;
			U0GCR = 11;
                        break;
		}

		case 115200: 
		{
			U0BAUD = 216;
			U0GCR = 11;
                        break;
		}

		case 230400: 
		{
			U0BAUD = 216;
			U0GCR = 12;
                        break;
		}
	}
}

uint8_t UART0GetData()	//DATA reg
{
	return U0DBUF;
}

void UART0FillData(uint8_t data)	//DATA reg
{
	U0DBUF = data;
}






// UART1
void UART1AssignLocation(uint8_t sel)	//PERCFG.U1CFG, See table 7.1
{
	if(sel == UART1_P07_P06)
		PERCFG |= (sel << 1);
	else if(sel == UART1_P05_P04)
		PERCFG &= ~(sel << 1);
}

void UART1ModeSel(uint8_t mode)	//MODE
{
	if(mode == UART_MODE)
		U1CSR |= (mode << 7);
}

void UART1ReceiverEn(uint8_t sel)	//RE
{
	if(sel)
	{
		U1CSR |= (sel << 6);
	}
	else
	{
		U1CSR &= ~(sel << 6);
	}
}

void UART1DiscardDataBuff()	//write to RX_BYTE
{
	U1CSR &= ~(1 << 2);
}

uint8_t UART1IsReceiving()	//read from RX_BYTE
{
	return U1CSR & (1 << 2);
}

uint8_t UART1TranmissionCompleted()	//TX_BYTE
{
	return U1CSR & (1 << 1);
}

uint8_t UART1IsBusy()	//ACTIVE
{
	return U1CSR & 1;
}

void UART1SetBaud(unsigned long baud)	//BAUD bit and U1BAUD reg
{
	switch(baud)
	{
		case 2400: 
		{
			U1BAUD = 59;
			U1GCR = 6;
                        break;
		}

		case 4800: 
		{
			U1BAUD = 59;
			U1GCR = 7;
                        break;
		}

		case 9600: 
		{
			U1BAUD = 59;
			U1GCR = 8;
                        break;
		}

		case 14400: 
		{
			U1BAUD = 216;
			U1GCR = 8;
                        break;
		}

		case 19200: 
		{
			U1BAUD = 59;
			U1GCR = 9;
                        break;
		}

		case 28800: 
		{
			U1BAUD = 216;
			U1GCR = 9;
                        break;
		}

		case 38400: 
		{
			U1BAUD = 59;
			U1GCR = 10;		
                        break;
                }

		case 57600: 
		{
			U1BAUD = 216;
			U1GCR = 10;
                        break;
		}

		case 76800: 
		{
			U1BAUD = 59;
			U1GCR = 11;
                        break;
		}

		case 115200: 
		{
			U1BAUD = 216;
			U1GCR = 11;
                        break;
		}

		case 230400: 
		{
			U1BAUD = 216;
			U1GCR = 12;
                        break;
		}
	}
}

uint8_t UART1GetData()	//DATA reg
{
	return U1DBUF;
}

void UART1FillData(uint8_t data)	//DATA reg
{
	U1DBUF = data;
}