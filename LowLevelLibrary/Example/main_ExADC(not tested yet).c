#include "Generic.h"
#include "ADC.h"
#include "GPIO.h"

uint8_t val = 0;

int main()
{
  enableADCPin(PIN0_6);
  enableADCPin(PIN0_7);
  
  selectStartCondition(SETBIT_ST);
  referenceVoltage(IN_REF);
  selectDecimationRate(DEC_RATE_256);
  
  
  //P1 as Output
  P1SEL = 0x00;
  P1DIR = 0xFF;
  P1 = 0x00;

  for(;;)
  {
    channelSeleted(AIN6);
    startConvertion();
    while(!completedConvertion())
    {}
    P1 = val;
  }
  return 0;
}