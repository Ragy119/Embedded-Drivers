#include"types.h"
#include"Addresses.h"
#define F_CPU 16000000
#include"avr/delay.h"

// data --> portA
// Rs   --> D0
// Rw   --> D1
// E    --> D2

void Write_cmd(u8 cmd)
{
	PORTD &= 0xFE;   //Rs=0
	PORTD &= 0xFD;   //Rw=0
	PORTA = cmd;
	PORTD |= 0x04;   //clock
	_delay_ms(1);
	PORTD &= 0xFB;
}

void Write_data(u8 data)
{
	PORTD |= 0x01;   //Rs=1
	PORTD &= 0xFD;   //Rw=0
	PORTA = data;
	PORTD |= 0x04;   //clock
	_delay_ms(1);
	PORTD &= 0xFB;
}

void LCD_init(void)
{
	_delay_ms(50);
	Write_cmd(0b00111000);
	_delay_ms(1);
	Write_cmd(0b00001100);
	_delay_ms(1);
	Write_cmd(0b00000001);
	_delay_ms(2);
	Write_cmd(0b00000110);
}

