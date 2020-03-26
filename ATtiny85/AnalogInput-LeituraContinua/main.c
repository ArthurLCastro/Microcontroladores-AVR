/*
 * AnalogInput.c
 * Leitura Contínua
 * 
 * Created: 25/03/2020 22:36
 * Author : Arthur Castro
 */

#ifndef __AVR_ATtiny85__
    #define __AVR_ATtiny85__
#endif

#include <avr/io.h>

#define LED PB3
#define POT PB4
#define VALOR_MINIMO 500

void ioConfig();
void configAdc();
unsigned int lerAdc();

int main(void){
    unsigned int leituraAnalogica = 0;

    ioConfig();
    configAdc();

    while(1){

        leituraAnalogica = lerAdc();
        
        // Se a leitura for maior que o valor mínimo o LED acende, caso contrário, apaga
        if(leituraAnalogica > VALOR_MINIMO){
            PORTB |= (1<<LED);
        } else {
            PORTB &= ~(1<<LED);
        }
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