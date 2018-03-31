#ifndef BICO_PORT_H
#define BICO_PORT_H

#include "Logic_Math.h"

#define BP(name, BP_NB) uint8_t name##_port[BP_NB]; \
  uint8_t name##_num_of_bit = BP_NB 

#define BPSetup(name, pins) BPSetup_routine(name##_port, name##_num_of_bit, pins)
#define BPGetReady(name, port_mode) BPGetReady_routine(name##_port, name##_num_of_bit, port_mode)
#define BPWrite(name, val) BPWrite_routine(name##_port, name##_num_of_bit, val)
#define BPRead(name) BPRead_routine(name##_port, name##_num_of_bit)

#define MODE_IN 1
#define MODE_OUT 0

void BPSetup_routine(uint8_t* BP_port, uint8_t num_of_bit, uint8_t* pins)
{
  uint8_t i = 0;
  for(i = 0; i < num_of_bit; i++)
  {
    BP_port[i] = pins[i];
  }
}

#ifndef FOR_PIC_CCS
void BPGetReady_routine(uint8_t* BP_port, uint8_t num_of_bit, bool port_mode)
{
  uint8_t i = 0;
  for(i = 0; i < num_of_bit; i++)
  {
    if(port_mode == MODE_OUT)
    {
      pinMode(BP_port[i], OUTPUT);
      digitalWrite(BP_port[i], LOW); 
    }
    else
      pinMode(BP_port[i], INPUT);
  }
}
#endif

void BPWrite_routine(uint8_t* BP_port, uint8_t num_of_bit, long val)
{
  uint8_t i = 0;
  for(i = 0; i < num_of_bit; i++)
  {
    digitalWrite(BP_port[i], getBit(val, i));
  }
}

long BPRead_routine(uint8_t* BP_port, uint8_t num_of_bit)
{
  long val = 0;
  uint8_t i = 0;
  for(i = 0; i < num_of_bit; i++)
  {
    if(digitalRead(BP_port[i]))
      val = setBit(val, i);
    else
      val = clrBit(val, i);
  }
  return val;
}
#endif
