/*	Author: Alyssa Zepeda
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description:  Read an 8-bit value on PA7..PA0 and write 
 *	that value on PB3..PB0PC7..PC4. That is to say,  take the upper 
 *	nibble of PINA and map it to the lower nibble of PORTB, likewise 
 *	take the lower nibble of PINA and map it to the upper nibble of 
 *	PORTC (PA7 -> PB3, PA6 -> PB2, … PA1 -> PC5, PA0 -> PC4).

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
	DDRB = 0XFF; PORTB = 0X00; //Config port B's 8 pins to output
	DDRC = 0XFF; PORTC = 0X00; //Config port C's 8 pins to output
	unsigned char B = 0x00;
	unsigned char C = 0x00;
    /* Insert your solution below */
    while (1) {
    	B = PINA & 0xF0; //A's upper nibble
	C = PINA & 0x0F; //A's lower nibble
	
	//assign upper nibble to lower of B
	B = B >> 4;
	PORTB = B;
	
	//assign lower nibble to uppwe of C
	C = C << 4;
	PORTC = C;
    }
    return 1;
}
