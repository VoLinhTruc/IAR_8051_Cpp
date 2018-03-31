#include "Generic.h"
#include "GlobalINT.h"
#include "GPIO.h"
#include "UART.h"
#include "ADC.h"

uint8_t val = 0;

void echo()
{
  char c = UART0GetData();      // lay tin hieu tu buffer sau khi nhan duoc 1 byte
  val++;        // dem so lan nhan duoc du lieu, gia tri nay hien thi ra port 1
}

URX0ISRFunction(echo);  // lien ket IRS toi' ham echo


int main()
{
  //2 dong duoi nay la su dung XOSC 32MHz
  CLKCONCMD &= ~(1<<6);
  CLKCONCMD &= 0xFC;
  
  portFunction(PORT1, PORT_GPIO);
  portDirect(PORT1, PORT_OUTPUT);
  
  //URX0IF = 0; //xoa co ngat
  URX0InterruptSwitch(ON);      // cho phep ngat sau khi nhan 8 bit du lieu tu chan RX
  GlobalInterruptSwitch(ON);    // cho phep ngat toan cuc he thong
  pinFunction(PIN0_2, PIN_PERIPHERAL);  // cai dat pin 0_2 co chuc nang la pin ngoai vi
  pinFunction(PIN0_3, PIN_PERIPHERAL);  // cai dat pin 0_3 co chuc nang la pin ngoai vi
  UART0AssignLocation(UART0_P02_P03);   // dang ky pin TX va RX la 0_2 va 0_3, co the dang ky pin TX va RX trong port 1
  UART0ModeSel(UART_MODE);      // chon che do UART, tai vi pin TX va RX trung voi chan cua SPI, mac dinh khi reset thi che do cua 2 pin nay la PIN
  UART0SetBaud(57600);  // set baud rate, baud phu thuoc vao System Clock, baud nay duoc tinh dua tren System Clock la 32MHz
  
  //ADC common config
  selectStartCondition(SETBIT_ST);
  referenceVoltage(AVDD5);
  selectDecimationRate(RESOLUTION_7BIT);
  //ADC pin6 config
  pinFunction(PIN0_6, PIN_PERIPHERAL);
  enableADCPin(PIN0_6);
  channelSeleted(AIN6);
  
  pinFunction(PIN0_1, PIN_GPIO);
  pinDirect(PIN0_1, PIN_INPUT);
  
  for(;;)
  {

    //UART0FillData(CHIPID);
    pinWrite(PIN1_0, 1);
    delay_ms(500);
    pinWrite(PIN1_0, 0);
    delay_ms(500);
    
  }
  return 0;
}