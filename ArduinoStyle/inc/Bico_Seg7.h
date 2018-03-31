#ifndef BICO_SEG7_H
#define BICO_SEG7_H

#ifndef FOR_ARDUINO
#define delay delay_ms
#endif

#include "Bico_Port.h"
#include "Algebra_Math.h"
#include "Logic_Math.h"

#define COMMON_ANODE
//#define COMMON_CATHOD

#define ON_DELAY 4
#define OFF_DELAY 0

#ifdef COMMON_ANODE
#define MINUS_SYMBOL 0xBF
#define NULL_SYMBOL 0xFF
#define FLOAT_POINT_SYMBOL  0x7F
#endif

#ifdef COMMON_CATHODE
#define MINUS_SYMBOL 0x40
#define NULL_SYMBOL 0x00
#define FLOAT_POINT_SYMBOL  0x80
#endif

void BS7Setup(uint8_t* digit, uint8_t* code);
void BS7GetReady(void);
void BS7SetDigit(uint8_t stand, uint8_t val, bool set_point);
void BS7SetSymbol(uint8_t stand, char symbol);
void BS7Clear(uint8_t stand);
void BS7SetNumber(signed long num);
void BS7Hide(void);
void BS7Show(void);
void BS7SetNumberAndShow(signed long val);

BP(BS7_code, 8);
BP(BS7_digit, ND);
uint8_t BS7_output_data[ND];
#ifdef COMMON_ANODE
uint8_t seg7_code[16] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
#endif
#ifdef COMMON_CATHODE
uint8_t seg7_code[16] = {0x3F, 0x06, 0x5B, 0x79, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
#endif


//--------------------------------------------------
void BS7Setup(uint8_t* digit, uint8_t* code)
{
  BPSetup(BS7_code, code);
  BPSetup(BS7_digit, digit);
}
//--------------------------------------------------
#ifndef FOR_PIC_CCS
void BS7GetReady(void)
{
  BPGetReady(BS7_code, MODE_OUT);
  BPGetReady(BS7_digit, MODE_OUT);
}
#endif
//--------------------------------------------------
void BS7SetDigit(uint8_t stand, uint8_t val, bool set_point)
{
  if(set_point)
    #ifdef COMMON_ANODE
    BS7_output_data[stand] = seg7_code[val] & FLOAT_POINT_SYMBOL;
    #endif
    #ifdef COMMON_CATHODE
    BS7_output_data[stand] = seg7_code[val] | FLOAT_POINT_SYMBOL;
    #endif
  else
    BS7_output_data[stand] = seg7_code[val];
}
//--------------------------------------------------
void BS7SetSymbol(uint8_t stand, char symbol)
{
  switch(symbol)
  {
    case '-': {BS7_output_data[stand] = MINUS_SYMBOL; break;}
    case '.': {BS7_output_data[stand] = FLOAT_POINT_SYMBOL; break;}
  }
}
//--------------------------------------------------
void BS7Clear(uint8_t stand)
{
  BS7_output_data[stand] = NULL_SYMBOL;
}
//--------------------------------------------------
void BS7SetNumber(signed long num)
{
  uint8_t i;
  seperateDigit(num, BS7_output_data, ND);
  for(i = 0; i < ND; i++)
  {
    if((i >= getNumberOfDigit(num)) && (BS7_output_data[i] == 0))
      BS7_output_data[i] = NULL_SYMBOL;
    else
      BS7_output_data[i] = seg7_code[BS7_output_data[i]];
  }
  if(num < 0)
    BS7_output_data[getNumberOfDigit(num)] = MINUS_SYMBOL;
}
//--------------------------------------------------
void BS7Hide(void)
{
  #ifdef COMMON_ANODE
  BPWrite(BS7_digit, 0x00);
  #endif
  #ifdef COMMON_CATHODE
  BPWrite(BS7_digit, 0xFF);
  #endif
}
//--------------------------------------------------
void BS7Show(void)
{
  uint8_t i = 0;
  for(i = 0; i < ND; i++)
  { 
    BPWrite(BS7_code, BS7_output_data[i]);
    #ifdef COMMON_ANODE
    BPWrite(BS7_digit, (uint8_t)(1<<i));
    #endif
    #ifdef COMMON_CATHODE
    BPWrite(BS7_digit, (uint8_t)(~(1<<i)));
    #endif  
    delay(ON_DELAY);
    BS7Hide();
    delay(OFF_DELAY);
  }
}
//--------------------------------------------------
void BS7SetNumberAndShow(signed long val)
{
  BS7SetNumber(val);
  BS7Show();
}
//--------------------------------------------------
#endif

