/*
 * 8bitTimer.c
 *
 * Created: 20/03/2020 15:58:11
 * Author : Arthur Castro
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED PB3
#define NUMBER_OF_REPEATS 10

unsigned int repeatCounter = 0;

int main(void){
	DDRB |= (1<<LED);
	PORTB = 0x00;

	// CTC Mode (Clear Timer on Compare)
	TCCR0A &= ~(1<<WGM00);	// WGM01 em 0
	TCCR0A |= (1<<WGM01);	// WGM01 em 1
	TCCR0B &= ~(1<<WGM02);	// WGM01 em 0
	
	sei();
	
	// Clock Select Bit
	TCCR0B |= (1<<CS00);	// CS00 em 1
	TCCR0B &= ~(1<<CS01);	// CS01 em 0
	TCCR0B |= (1<<CS02);	// CS02 em 1
	
	OCR0A = 97;
	TIMSK |= (1<<OCIE0A);	// OCIE0A em 1
	
    while (1){
		
	}
}

ISR(TIMER0_COMPA_vect){
	repeatCounter++;
	if(repeatCounter == NUMBER_OF_REPEATS){
		PORTB ^= (1<<LED);
		repeatCounter = 0;
	}
}