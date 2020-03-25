/*
 * PWM-FastMode.c
 *
 * Created: 25/03/2020 00:10:15
 * Author : Arthur Castro
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

#define PWM_PIN_NON_INVERTED PB0			// OC0A
#define PWM_PIN_INVERTED PB1				// OC0B

int main(void){
	unsigned int dutyCycle_8bit = 0;		// Duty Cycle com valores entre 0 e 255

	DDRB |= (1<<PWM_PIN_INVERTED) | (1<<PWM_PIN_NON_INVERTED);

	TCCR0A = (1<<WGM01) | (1<<WGM00) | (1<<COM0A1) | (1<<COM0B1) | (1<<COM0B0);
	TCCR0B = (1<<CS01) | (1<<CS00);	
	
    while (1){
		// Incrementa a cada 20ms o Duty  Cycle do PWM
		for(dutyCycle_8bit=0; dutyCycle_8bit<=255; dutyCycle_8bit++){
			OCR0A = dutyCycle_8bit;
			OCR0B = dutyCycle_8bit;
			_delay_ms(20);
		}
    }
}

