// Programando, Compilando e Gravando hex em AVR no VScode
// Arthur Castro
// 25 de Março de 2020

#ifndef __AVR_ATtiny85__
    #define __AVR_ATtiny85__
#endif

//#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#define LED PB3

int main(void){
    DDRB |= (1<<LED);
    
    while(1){
        PORTB ^= (1<<LED);
        _delay_ms(100);
    }
}