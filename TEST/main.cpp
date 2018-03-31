#include "hal_led.h"

int main()
{
  HalLedInit();
    
  for(;;)
  {
    HalLedBlink(HAL_LED_1, 10, 50, 1000);
  }
  return 0;
}
