/*
 * AnalogInput.c
 *
 * Created: 25/03/2020 10:29:59
 * Author : Arthur Castro
 */ 

#ifndef __AVR_ATtiny85__
    #define __AVR_ATtiny85__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED PB3
#define POT PB4

volatile int analogResult = 0;

ISR(ADC_vect){
    analogResult = (ADCH<<8) | ADCL;
}

int main(void){
    DDRB &= ~(1<<POT);      // Potentiometer Input
    DDRB |= (1<<LED);       // LED Output

    ADMUX &= ~((1<<REFS1)|(1<<REFS0)|(1<<ADLAR));
    ADMUX |= (1<<MUX1);

    ADCSRB &= ~((1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0));

    DIDR0 |= (1<<ADC2D);

    ADCSRA |= (1<<ADEN)|(1<<ADIE);
    sei();
    ADCSRA |= (1<<ADSC);

    while(1){
        if(analogResult > 500){
            PORTB |= (1<<LED);
        } else {
            PORTB &= ~(1<<LED);
        }
    }
}