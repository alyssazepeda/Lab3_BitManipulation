/*	Author: Alyssa Zepeda
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: A car has a fuel-level sensor that sets 
 *	PA3..PA0 to a value between 0 (empty) and 15 (full). A series of 
 *	LEDs connected to PC5..PC0 should light to graphically indicate the
 *	fuel level. If the fuel level is 1 or 2, PC5 lights. If the level
 *	is 3 or 4, PC5 and PC4 light. Level 5-6 lights PC5..PC3. 7-9
 *	lights PC5..PC2. 10-12 lights PC5..PC1. 13-15 lights PC5..PC0. 
 *	Also, PC6 connects to a "Low fuel" icon, which should light if 
 *	the level is 4 or less.
 *	(The example below shows the display for a fuel level of 3).    


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
	DDRC = 0XFF; PORTC = 0X00; //Config port C's 8 pins to output
	unsigned char fuelLevel = 0x00;
	unsigned char LED = 0x00;
    /* Insert your solution below */
    while (1) {
	fuelLevel = PINA & 0x0F; //only read PA3-PA0
	if(fuelLevel == 0) {
		LED = 0x40; // low fuel light turns on
	} 
	else if(fuelLevel < 3) {
		LED = 0x60; //low fuel & PC5
	} 
	else if(fuelLevel < 5) {
		LED = 0x70; //low fuel, PC5 & PC4
	} 
	else if(fuelLevel < 7) {
		LED = 0x38; //PC5-3
	} 
	else if(fuelLevel < 10) {
		LED = 0x3C; //PC5-2
	} 
	else if(fuelLevel < 13) {
	       LED = 0x3E; //PC5-1
	}
	else {
		LED = 0x3F; //PC5-0
	}
	PORTC = LED;	
    }
    return 1;
}
