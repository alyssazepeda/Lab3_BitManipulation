/*	Author: Alyssa Zepeda
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: Count the number of 1s on ports A and B and output that number on port C.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0X00; PORTA = 0XFF; //Config port A's 8 pins to inputs
	DDRB = 0X00; PORTB = 0XFF; //Config port B's 8 pins to input
	DDRC = 0XFF; PORTC = 0X00; //Config port C's 8 pins to output
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char oneCnt = 0x00;
    /* Insert your solution below */
    while (1) {
	tempA = PINA;
	tempB = PINB;

	for(int i = 0; i < 8; i++) {
		if(tempA & 0x01) {
			++oneCnt;
		}
		tempA = tempA >> 1;
	}
	for(int j = 0; j < 8; j++) {
		if(tempB & 0x01) {
			++oneCnt;
		}
		tempB = tempB >> 1;
	}
	PORTC = oneCnt;
	oneCnt = 0;
    }
    return 1;
}
