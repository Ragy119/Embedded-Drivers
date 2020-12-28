#include"types.h"
#include"Addresses.h"
#define F_CPU 16000000
#include"avr/delay.h"


void ADC_VidAdcInit(void)
{
	ADMUX  = 0b01100000;
	ADCSRA = 0b10000000;
	ADCH   = 0b00000000;
}


u16 ADC_u16AdcConvAndGetRes(void)
{
	// start conversion
	ADCSRA |= 0b01000000;

	// wait for conversion to complete
	while((ADCSRA & 0b01000000) == 0);

	// clear flag (upnormal it's reset by set another one)
	ADCSRA |= 0b00010000;

	// return ADCH
	return ADCH;
}