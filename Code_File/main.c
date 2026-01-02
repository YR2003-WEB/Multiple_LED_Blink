#include<lpc21xx.h>
#define leds 0xff

void delay_ms(int ms)
{
	T0PR=15000-1;
	T0TCR=0X01;
	while(T0TC<ms);
	T0TCR=0X03;
	T0TCR=0X00;
}

int main()
{
	int i,j;
	IODIR0=leds;
	while(1)
	{
		// Right shift 
		for(i=7;i>=0;i--)
		{
			IOSET0=1<<i;
			delay_ms(10);
			IOCLR0=1<<i;
			delay_ms(10);
		}
		// Left Shift 
		for(i=0;i<=7;i++)
		{
			IOSET0=1<<i;
			delay_ms(10);
			IOCLR0=1<<i;
			delay_ms(10);
		}
		// Convergence & Divergence
		for(i=0,j=7;i<8;i++,j--)
		{
			IOSET0=1<<i|1<<j;
			delay_ms(50);
			IOCLR0=1<<i|1<<j;
			delay_ms(50);
		}
	}
}

