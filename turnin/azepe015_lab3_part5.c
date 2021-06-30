/*	Author: Alyssa Zepeda
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description:A car's passenger-seat weight sensor outputs 
 *	a 9-bit value (ranging from 0 to 511) and connects to input 
 *	PD7..PD0PB0 on the microcontroller. If the weight is equal to or 
 *	above 70 pounds, the airbag should be enabled by setting PB1 to 1. 
 *	If the weight is above 5 but below 70, the airbag should be disable
 *	and an "Airbag disabled" icon should light by setting PB2 to 1. 
 *	(Neither B1 nor B2 should be set if the weight is 5 or less, 
 *	as there is no passenger). 
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
	DDRB = 0XFE; PORTB = 0X01; //Config port B's 7 pins to output & PB0 to input
	DDRD = 0X00; PORTD = 0XFF; //Config port D's 8 pins to input
	unsigned char airBag = 0x00;
	unsigned char B = 0x00;
	unsigned short weight = 0x00;
    /* Insert your solution below */
    while (1) {
    	//get PB0
	B = PINB & 0x01;

	//get weight PD7..PD0PB0
	weight = PIND << 1; //make room for PB0
	weight = weight | B;

	if(weight <= 0x05) {
		airBag = 0x00;
	}
	else if(weight < 0x46) {
		airBag = 0x04; //PB2 is set
	}
	else {
		airBag = 0x02; //PB1 is set
	}

	PORTB = airBag;
    }
    return 1;
}
