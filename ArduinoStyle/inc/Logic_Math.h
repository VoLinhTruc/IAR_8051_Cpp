#ifndef LOGIC_MATH_H
#define LOGIC_MATH_H

signed char getBit(signed long num, signed char bit);
signed long setBit(signed long num, signed char bit);
signed long clrBit(signed long num, signed char bit);

//--------------------------------------------------
signed char getBit(signed long num, signed char bit)
{
  return !!(num &= (1 << bit));
}
//--------------------------------------------------
signed long setBit(signed long num, signed char bit)
{
  return (num |= (1 << bit));
}
//--------------------------------------------------
signed long clrBit(signed long num, signed char bit)
{
  return (num &= ~(1 << bit));
}
//--------------------------------------------------

#endif
