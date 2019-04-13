/*
 Incremento do PORTB

 Author : Arthur Castro / Henrique Martins
 Created: 19/02/2019 17:15:57
*/ 

#include <avr/io.h>
#include <avr/delay.h>

#define F_CPU 1000000UL

int main(void)
{
	DDRB =  0b11111111;			// Seta o PORTB como saída
	PORTB = 0b00000000;			// Inicia o PORTB com valor 0
	
    while (1) 
    {
		PORTB++;				// Incrementa o PORTB
		_delay_ms(500);
    }
}
