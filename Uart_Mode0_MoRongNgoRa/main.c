#include<main.h>
#include<..\lib\Delay.h>

void Uart_Mode0_Write(unsigned char b)
{
	SBUF = b;

	while(TI == 0);
	TI = 0;

	P3_2 = 0;
	P3_2 = 1;
}

void main()
{
	unsigned char i;

	SM0 = SM1 = 0;		// UART mode 0

	while(1)
	{
		for(i=0;i<3;i++)
		{
		 	Uart_Mode0_Write(0x00);
			Delay_ms(500);
			Uart_Mode0_Write(0xFF);
			Delay_ms(500);
		}
		for(i=0;i<3;i++)
		{
		 	Uart_Mode0_Write(0x55);
			Delay_ms(500);
			Uart_Mode0_Write(0xAA);
			Delay_ms(500);
		}
	}
}