/*
 * PWM-FastMode.c
 *
 * Created: 25/03/2020 00:10:15
 * Author : Arthur Castro
 */ 

#include <avr/io.h>

#define PWM_PIN_NON_INVERTED PB0			// OC0A
#define PWM_PIN_INVERTED PB1				// OC0B

int main(void){	
	double dutyCycle_Percent = 75.2;						// Percentual de Duty Cycle positivo
	unsigned int dutyCycle_8bit = 0;
	
	DDRB |= (1<<PWM_PIN_INVERTED) | (1<<PWM_PIN_NON_INVERTED);

	TCCR0A = (1<<WGM01) | (1<<WGM00) | (1<<COM0A1) | (1<<COM0B1) | (1<<COM0B0);
	TCCR0B = (1<<CS01) | (1<<CS00);	
	
	dutyCycle_8bit = (dutyCycle_Percent/100)*255;			// OCR0A recebe valores entre 0 e 255, o +Duty é dado em percentual
	OCR0A = dutyCycle_8bit;
	OCR0B = dutyCycle_8bit;

    while (1){
    }
}

