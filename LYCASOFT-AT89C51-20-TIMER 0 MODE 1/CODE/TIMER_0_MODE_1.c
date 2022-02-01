#include<reg51.h>
//#include "8051_delay.h"

sbit LED = P2^0;

void T0_M1_delay()
{
	int i;
	TMOD = 0X01;
	for(i=0;i<20;i++)
	{
		TH0=0XFC;
		TL0=0X48;
		TR0=1;
		while(!TF0);
		TF0=0;
		TR0=0;
	}
}

void main()
{
	LED = ~LED;
	T0_M1_delay();
}