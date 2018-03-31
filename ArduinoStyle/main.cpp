#include "CCINO_GPIO.h"

#define ND 2
#include "Bico_Seg7.h"

uint8_t digit[] = {PIN0_6, PIN0_7};
uint8_t code[] = {PIN1_0, PIN1_1, PIN1_2, PIN1_3, PIN1_4, PIN1_5, PIN1_6, PIN1_7};

uint8_t val = 0;

int main()
{ 
  pinMode(PIN1_1, OUTPUT);
  
  for(;;)
  {
    digitalWrite(PIN1_1, HIGH);
    delay_ms(500);
    digitalWrite(PIN1_1, LOW);
    delay_ms(500);
  }
  return 0;
}
