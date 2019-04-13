# Microcontroladores AVR

Repositório destinado ao compartilhamento e armazenamento de códigos simples em linguagem C para microcontroladores AVR como ATtiny85 e ATmega328P

## USBasp e ATtiny85:
Hardware para programar o AVR ATtiny85 utilizando o gravador USBasp
![Hardware - ATtiny85 e USBasp](https://github.com/ArthurLCastro/Microcontroladores-AVR/blob/master/hardware-ATtiny85-USBasp.png)
Obs.: O gravador alimenta o circuito com os 5V necessários

## Regulador de Tensão:
Após a gravação do código na memória do microcontrolador, podem ser desconectados os fios entre o ATtiny85 e o USBasp. Logo, será necessária uma alimentação externa de 5V para que o circuito funcione. Uma alternativa é o uso de um circuito regulador de tensão com o CI LM7805.
* LM7805 - Regulador de Tensão
* Diodo - Evita danos ao circuito caso a alimentação de entrada (9V) seja ligada de forma incorreta
* Capacitor Eletrolítico de 10uF - Filtro para a entrada do Circuito Regulador
* Capacitor Cerâmico de 10nF - Filtro para a saída do Circuito Regulador
* Capacitor Eletrolítico de 100uF - Filtro para a saída do Circuito Regulador
![Hardware - Regulador de Tensão com LM7805](https://github.com/ArthurLCastro/Microcontroladores-AVR/blob/master/hardware-Regulador7805.png)
