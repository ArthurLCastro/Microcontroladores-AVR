/*
 * 16bitTimer.c
 *
 * Created: 23/03/2020 13:07:11
 * Author : Arthur Castro
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED PB5

int main(void){
	DDRB |= (1<<LED);
	PORTB = 0x00;

	// CTC Mode (Clear Timer on Compare)
	TCCR1A &= ~(1<<WGM10);	// WGM10 em 0
	TCCR1A &= ~(1<<WGM11);	// WGM11 em 0
	TCCR1B |= (1<<WGM12);	// WGM12 em 1
	TCCR1B &= ~(1<<WGM13);	// WGM13 em 0
	
	sei();
	
	// Clock Select Bit
	TCCR1B |= (1<<CS10);	// CS10 em 1
	TCCR1B &= ~(1<<CS11);	// CS11 em 0
	TCCR1B |= (1<<CS12);	// CS12 em 1
	
	OCR1A = 15625;
	
	TIMSK1 |= (1<<OCIE1A);	// OCIE1A em 1
	
    while (1){
		
	}
}

ISR(TIMER1_COMPA_vect){
	PORTB ^= (1<<LED);
}