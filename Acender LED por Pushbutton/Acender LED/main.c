/*
 Acender LED por Pushbutton

 Author : Arthur Castro
 Created: 19/02/2019 17:41:09
*/

#define F_CPU 1000000UL

#include <avr/io.h>

#define LED PB3
#define BUT PB4

int main(void){
	DDRB |= (1<<LED);				// Seta o PB3 como saída e os demais como entradas
	PORTB |= (1<<BUT);				// Habilita Pull-Up interno no PB4
	
	while (1){
		if(!(PINB&(1<<BUT))){
			PORTB |= (1<<LED);
			} else {
			PORTB &= ~(1<<LED);
		}
	}
}
