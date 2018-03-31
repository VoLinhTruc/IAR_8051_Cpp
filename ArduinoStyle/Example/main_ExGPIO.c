#include "CCINO_GPIO.h"
int main()
{ 
  pinMode(PIN1_0, OUTPUT);
  pinMode(PIN1_1, OUTPUT);
  
  pinMode(PIN0_6, OUTPUT);
  pinMode(PIN0_7, OUTPUT);
  
  for(;;)
  {
    digitalWrite(PIN1_0, digitalRead(PIN0_6));
    digitalWrite(PIN1_1, digitalRead(PIN0_7));
  }
  return 0;
}
