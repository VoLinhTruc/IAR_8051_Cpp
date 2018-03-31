#ifndef ALGEBRA_MATH_H
#define ALGEBRA_MATH_H

signed long get_abs(signed long num);
signed long orderNumber(signed long num, unsigned char order); //Ham luy thua, num có the am hoac duong, order khong duoc am
signed char getNumberOfDigit(signed long num); //Ham lay so chu so cua mot so, VD: getNumberOfDigit(1425) se tra ve ket qua la 4
signed char getDigitInNumber(signed long num, unsigned char stand); //stand - vi tri cua so can lay, lay mot chu so trong mot so, VD: getDigitInNumber(14578, 2) se tra ve ket qua la 5, num có the am hoac duong, stand khong duoc am
void seperateDigit(signed long num, unsigned char* storage, unsigned char storage_size); //tach cac chu so cua mot so va luu vao mang storage, VD: seperateDigit(452, a) thi cac phan tu cua a luc nay la a[0]=2, a[1]=5, a[2]=4

//--------------------------------------------------
signed long get_abs(signed long num)
{
  return ((num < 0)? (-num):num);
}
//--------------------------------------------------
signed long orderNumber(signed long num, unsigned char order)
{
  signed long result = 1;
  unsigned char i = 0;
  for(i = 0; i < order; i++)
    result *= num;
  return result;
}
//--------------------------------------------------
signed char getNumberOfDigit(signed long num)
{
  unsigned char num_of_digit = 0;
  num = get_abs(num);
  do
  {
    num_of_digit++;
  }
  while((num /= 10) >0 );

  return num_of_digit;
}
//--------------------------------------------------
signed char getDigitInNumber(signed long num, unsigned char stand) //stand - vi tri cua so can get
{
  return ((get_abs(num) / orderNumber(10, stand))%10);
}
//--------------------------------------------------
void seperateDigit(signed long num, unsigned char* storage, unsigned char storage_size)
{
  unsigned char i = 0;
  num = get_abs(num);
  for(i = 0; i < storage_size; i++)
  {
    storage[i] = getDigitInNumber(num, i);
  }
}
//--------------------------------------------------
#endif
