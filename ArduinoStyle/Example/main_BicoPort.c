#include "CCINO_GPIO.h"
#include "Bico_Port.h"

BP(myP, 6);
uint8_t pins[] = {PIN1_2, PIN1_3, PIN1_4, PIN1_5, PIN1_6, PIN1_7};

int main()
{ 
  BPSetup(myP, pins);
  BPGetReady(myP, MODE_OUT);
  
  pinMode(PIN1_0, OUTPUT);
  pinMode(PIN1_1, OUTPUT);
  
  pinMode(PIN0_6, OUTPUT);
  pinMode(PIN0_7, OUTPUT);
  
  for(;;)
  {
    digitalWrite(PIN1_0, digitalRead(PIN0_6));
    digitalWrite(PIN1_1, digitalRead(PIN0_7));
    BPWrite(myP, 0xAA);
    delay_ms(200);
    BPWrite(myP, 0x55);
    delay_ms(200);
  }
  return 0;
}
