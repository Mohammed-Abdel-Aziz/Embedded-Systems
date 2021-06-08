#define F_CPU 1000000UL //Define the clock of Microcontroller
#include <avr/io.h>
#include <util/delay.h>

uint8_t englishNumbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x7, 0x7F, 0x67};
//7seg English numbers       0     1     2     3     4     5    6     7     8     9

uint8_t englishLetters[] = {
	// gfedcba in 7 Segments
	0b01110111, // a
	0b01111100, // b
	0b00111001, // c
	0b01011110, // d
	0b01111001, // e
	0b01110001, // f
	0b01111101, // g
	0b01110110, // h
	0b00110000, // i
	0b00011110, // j
	0b01110101, // k
	0b00111000, // l
	0b00110111, // m
	0b01010100, // n
	0b00111111, // o
	0b01110011, // p
	0b01100111, // q
	0b00110001, // r
	0b01101101, // s
	0b01111000, // t
	0b00011100, // u
	0b00111110, // v
	0b01111110, // w
	0b00110110, // x
	0b01101110, // y
	0b01011011  // z
};

int main(void)
{
	DDRD = 0xFF;	//Set portD as output port.
	DDRB = 0xFF;	//Set portB as output port.
	
	uint8_t englishNumbersSize = sizeof(englishNumbers)/sizeof(uint8_t); //Get the size of array.
	uint8_t englishLettersSize = sizeof(englishLetters)/sizeof(uint8_t); //Get the size of array.
	
	while (1)
	{
		uint8_t count = 0;	//Define counter for 2nd 7segment.
		for (uint8_t i = 0; i<englishLettersSize; i++)
		{
			PORTB = englishLetters[i];	//Print the English letters to 1st 7segment
			PORTD = englishNumbers[count];	//Print the English numbers to 2nd 7segment
			count=count+1;	//increment the counter by 1
			_delay_ms(500);
			
			//Check if the englishLetters finished the letters, set the counter to 0 and start count again.
			if (i==englishLettersSize)
			{
				i=0;
			}
			
			//Check if the englishNumbers finished the Numbers, set the counter to 0 and start count again.
			if (count == englishNumbersSize)
			{
				count=0;
			}
		}
	}
}