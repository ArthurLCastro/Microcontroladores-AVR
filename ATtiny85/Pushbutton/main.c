/*
 * Pushbutton.c
 *
 * Created: 19/03/2020 21:34:23
 * Author : Arthur Castro
 */

#include <avr/io.h>

#define LED PINB3
#define PUSHBUTTON PINB4

int main(void){
	DDRB = (1<<LED);				// Define PB3 como output e as demais como input
	PORTB = (1<<PUSHBUTTON);		// Habilita o Pullup interno
	
	while(1){
		if(!(PINB & 0x10)){
			PORTB |= (1<<LED);
			} else {
			PORTB &= ~(1<<LED);
		}
	}
}