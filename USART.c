#include"types.h"
#include"Addresses.h"
#define F_CPU 16000000
#include"avr/delay.h"



void USART_vodinit(void)
{
	UCSRB=0b00011000;
	UCSRC=0b10000110;

	UBRRL=103;
	UBRRH=0;
}

u8 USART_u8ReadChar(void)
{
	while((UCSRA & 0b10000000) == 0);
	return UDR;
}


void USART_u8WriteData(u8 Data)
{
	while((UCSRA & 0b00100000) == 0);
	UDR=Data;
}