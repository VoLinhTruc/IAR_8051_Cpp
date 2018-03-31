#include "ExINT.h"

unsigned char val = 5; 

void abc();

//Ket noi IRS toiws mot ham nao do, in this case la abc()
P0ISRFunction(abc);

int main()
{
  //P0 as Input
  P0SEL = 0x00;
  P0DIR = 0x00;
  
  //P1 as Output
  P1SEL = 0x00;
  P1DIR = 0xFF;
  P1 = 0x00;
  
  //enable ngat tren pin P0_6
  pinInterruptSwitch(PIN0_6, ON);
  
  //chon dieu kien tac dong la xung canh xuong
  egdeSelectionP0(FALLING);

  for(;;)
  {
    // P1 will indicate to us how "val""is change when interrput occurs
    P1 = val;
  }
  return 0;
}

void abc()
{
  val++;
}
