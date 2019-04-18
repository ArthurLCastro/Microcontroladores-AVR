/*
 * Controlar LED por Pushbutton
 *
 * Created: 21/02/2019 15:41:01
 * Author : Arthur Castro
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/delay.h>

#define LED PB3
#define BUT PB4

int main(void)
{
	DDRB |= (1<<LED);
	PORTB |= (1<<BUT);

    while (1) 
    {
		if(!(PINB & (1<<BUT))){
			PORTB ^= (1<<LED);
			_delay_ms(10);
		}
    }
}
