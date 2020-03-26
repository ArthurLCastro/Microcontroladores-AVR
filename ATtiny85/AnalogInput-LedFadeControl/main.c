/*
 * AnalogInput.c
 * Controle de Brilho de um LED por Potenciômetro
 * 
 * Created: 25/03/2020 22:58
 * Author : Arthur Castro
 */

#ifndef __AVR_ATtiny85__
    #define __AVR_ATtiny85__
#endif

#include <avr/io.h>

#define LED PB0
#define POT PB4

void ioConfig();
void configAdc();
unsigned int lerAdc();
void configFastPwm();

int main(void){
    unsigned int leituraAnalogica = 0;

    ioConfig();
    configAdc();
    configFastPwm();

    while(1){
        leituraAnalogica = lerAdc();

        OCR0A = leituraAnalogica/4;		// Duty Cycle com valores entre 0 e 255
    }
}

void ioConfig(){
    DDRB &= ~(1<<POT);      // Potenciômetro como entrada
    DDRB |= (1<<LED);       // LED como saída
}

void configAdc(){
    // VCC used as Voltage Reference, disconnected from PB0 (AREF).
    ADMUX &= ~(1<<REFS0);
    ADMUX &= ~(1<<REFS1);
    
    // Result is Right Adjusted
    ADMUX &= ~(1<<ADLAR);
    
    // Input Channel Selections - ADC2 (PB4)
    ADMUX &= ~(1<<MUX0);
    ADMUX |= (1<<MUX1);
    ADMUX &= ~(1<<MUX2);
    ADMUX &= ~(1<<MUX3);

    // Habilita o ADC
    ADCSRA |= (1<<ADEN);

    // ADC Auto Trigger Source Selections - Free Running mode
    ADCSRB &= ~(1<<ADTS0);
    ADCSRB &= ~(1<<ADTS1);
    ADCSRB &= ~(1<<ADTS2);

    // Digital Input Disable
    DIDR0 |= (1<<ADC2D);
}

unsigned int lerAdc(){
    ADCSRA |= (1<<ADSC);        // Inicia a Conversão
    return ADC;
}

void configFastPwm(){
	TCCR0A = (1<<WGM01) | (1<<WGM00) | (1<<COM0A1) | (1<<COM0B1) | (1<<COM0B0);
	TCCR0B = (1<<CS01) | (1<<CS00);
}