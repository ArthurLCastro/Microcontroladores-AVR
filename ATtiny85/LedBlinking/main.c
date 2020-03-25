/*
 * LedBlinking.c
 *
 * Created: 19/03/2020 21:17:21
 * Author : Arthur Castro
 */

// Ajuste de frequência para o uso do delay
#define F_CPU 1000000UL		// Clock interno de 8MHz/8

// Inclusão de Bibliotecas
#include <avr/io.h>
#include <util/delay.h>

// Função Principal
int main(void){
	DDRB = 0b00001000;		// Define PB3 como OUTPUT
	PORTB = 0;				// PORTB em nível baixo
	
	while(1){
		PORTB = 0x08;		// PB3 em nível alto
		_delay_ms(500);
		PORTB = 0x00;		// PB3 em nível baixo
		_delay_ms(500);
	}
}