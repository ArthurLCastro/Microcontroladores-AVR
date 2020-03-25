/*
 * PWM.c
 *
 * Created: 24/03/2020 20:50:33
 * Author : Arthur Castro
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define PWM_PIN PB0

double dutyCycle = 70;			// Duty Cycle em Percentual

int main(void){
	DDRB = (1<<PWM_PIN);		// Define o PB5 como Output 
	
	TCCR0A = (1<<COM0A1) | (1<<WGM00) | (1<<WGM01);
	
	TIMSK = (1<<TOIE0);
	
	OCR0A = (dutyCycle/100)*255;
	
	sei();						// Set External Interrupts

	TCCR0B = (1<<CS00);
	    
	while(1){
    }
}

ISR(TIMER0_OVF_vect){
}
