#include"types.h"
#include"Addresses.h"
#define F_CPU 16000000
#include"avr/delay.h"



u8 CheckButton(u8 ButtonNum)
{
	u8 row,column,status=0;

	row=ButtonNum/4;
	column=ButtonNum%4;

	u8 arr[4]={0b11111110,0b11111101,0b11111011,0b11110111};

	PORTA &=0xF0;
	PORTA |=arr[row];


	if((((PINA>>4)>>column)&0x01)==0)
	{
		_delay_ms(20);
		if((((PINA>>4)>>column)&0x01)==0)
		{
			status=1;
		}
		else
		{
			status=0;
		}

	}

	return status;
}

// (0000)most (0000)least
// least --> rows --> output (ones)
// Most --> columns --> input --> pullup (out = 1)
