#include "Generic.h"

void delay_5us(unsigned long microSecs)
{
  while(microSecs--)
  {
    asm("NOP"); asm("NOP"); asm("NOP"); asm("NOP");
    asm("NOP"); asm("NOP"); asm("NOP"); asm("NOP");
    asm("NOP");
  }
}

void delay_ms(unsigned long milliSecs)
{
  while(milliSecs--)
  {
    delay_5us(200);
  }
}