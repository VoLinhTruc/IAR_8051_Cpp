#include "ADC.h"

static uint8_t dec_rate_selected;

uint8_t enableADCPin(uint8_t pin)
{
	if BELONG_TO_PORT0(pin)
	{
		APCFG |= (1 << (pin - PORT0));

		return 1;
	}
	else return 0xFF;
}

uint8_t disableADCPin(uint8_t pin)
{
	if BELONG_TO_PORT0(pin)
	{
		APCFG &= ~(1 << (pin - PORT0));

		return 1;
	}
	else return 0xFF;
}

uint8_t completedConvertion()
{
	return (ADCCON1 & (1<<7));
}

void startConvertion()
{
	ADCCON1 |= (1<<6);
}

uint8_t isInConvertion()
{
	return (ADCCON1 & (1<<6));
}

void selectStartCondition(uint8_t sel)
{
	//clear 2 bit in ADCCON1.STSEL
	ADCCON1 &= ~(1<<4);
	ADCCON1 &= ~(1<<5);

	//insert 2 bit in sel into ADCCON1.STSEL	
	ADCCON1 |= (sel<<4);
}

void referenceVoltage(uint8_t sel)
{
	//clear 2 bit in ADCCON2.SREF
	ADCCON2 &= ~(1<<6);
	ADCCON2 &= ~(1<<7);

	//insert 2 bit in sel into ADCCON2.SREF	
	ADCCON2 |= (sel<<6);
}

void selectDecimationRate(uint8_t sel)
{
	//clear 2 bit in ADCCON2.SDIV
	ADCCON2 &= ~(1<<4);
	ADCCON2 &= ~(1<<5);

	//insert 2 bit in sel into ADCCON2.SDIV	
	ADCCON2 |= (sel<<4);
        
        dec_rate_selected = sel;
}

void channelSeleted(uint8_t sel)
{
	//clear 4 bit in ADCCON2.SCH	
	ADCCON2 &= ~(1<<0);
	ADCCON2 &= ~(1<<1);
	ADCCON2 &= ~(1<<2);
	ADCCON2 &= ~(1<<3);

	//insert 2 bit in sel into ADCCON2.SDIV, (sel << 0) = sel
	ADCCON2 |= sel;
}


void singleConversionreferenceVoltage(uint8_t sel)
{
	//clear 2 bit in ADCCON3.SREF
	ADCCON3 &= ~(1<<6);
	ADCCON3 &= ~(1<<7);

	//insert 2 bit in sel into ADCCON3.SREF	
	ADCCON3 |= (sel<<6);
}

void singleConversionselectDecimationRate(uint8_t sel)
{
	//clear 2 bit in ADCCON3.SDIV
	ADCCON3 &= ~(1<<4);
	ADCCON3 &= ~(1<<5);

	//insert 2 bit in sel into ADCCON3.SDIV	
	ADCCON3 |= (sel<<4);
}

void singleConversionchannelSeleted(uint8_t sel)
{
	//clear 4 bit in ADCCON3.SCH	
	ADCCON3 &= ~(1<<0);
	ADCCON3 &= ~(1<<1);
	ADCCON3 &= ~(1<<2);
	ADCCON3 &= ~(1<<3);

	//insert 2 bit in sel into ADCCON3.SDIV, (sel << 0) = sel
	ADCCON3 |= sel;
}

void connectTemSensorToADC(uint8_t sel)
{
	TR0 = sel;
}

int readResult()
{
	int result = ADCH;
	result <<= 8;
	result |= ADCL;

	switch (dec_rate_selected)
	  {
	    case DEC_RATE_64:
	      result >>= 8;
	      break;
	    case DEC_RATE_128:
	      result >>= 6;
	      break;
	    case DEC_RATE_256:
	      result >>= 4;
	      break;
	    case DEC_RATE_512:
	    default:
	      result >>= 2;
	    break;
	  }

	return result;
}