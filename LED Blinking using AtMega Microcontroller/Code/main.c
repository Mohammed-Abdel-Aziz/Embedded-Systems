#include <avr/io.h>
//#define F_CPU 16000000UL //Central Processing unit for the clock frequency of 16MHz External Crystal.
#define F_CPU 1000000 //Central Processing unit for the clock frequency of Internal Crystal.
#include "util/delay.h" //To call delay function.

int main(void)
{
	DDRD = 0x04;	//Set this port as output port. Hex.
	//DDRD = 0b00000100;	//Set this port as output port. Binary.
	
	while (1)
	{
		PORTD = 0x04;	//Turn on the port. Hex
		//PORTD = 0b00000100;	//Turn on the port. Binary.
		_delay_ms(1000);	//1000ms = 1 Second delay
		
		PORTD = 0x00;	//Turn off the port. Hex.
		//PORTD = 0b00000000;	//Turn on the port. Binary
		_delay_ms(1000);
	}
}

