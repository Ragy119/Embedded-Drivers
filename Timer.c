#include"types.h"
#include"Addresses.h"
#define F_CPU 16000000
#include"avr/delay.h"

void TIMER0_vodinit_OVF(void)     //normal
{
	SREG   = 0b10000000;

	TCCR0  = 0b00000010;
	TCNT0  = 0b00000000;
	TIMSK  = 0b00000001;

}


void TIMER0_vodinit_OCR(void)    //fast PWM
{
	SREG   = 0b10000000;

	TCCR0 |= 0b01101010;
	TCNT0  = 0b00000000;

	//OCR0

}




void TIMER1_vodinit_OCR(void)    //fast PWM
{
	TCCR1A |= 0b10000010;
	TCCR1B |= 0b00001101;
	//ICR1H  |= 0b00000001;  //313
	//ICR1L  |= 0b00111001;
	//OCR1AH
	//OCR1AL
}


