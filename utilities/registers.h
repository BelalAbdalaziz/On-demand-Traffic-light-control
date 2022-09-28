/*
 * File Name	: register.h 
 * Description	:
 * Created		: 9/2022
 *  Author		: Belal A.aziz
 */ 



#ifndef REGISTERS_H_
#define REGISTERS_H_
/**************		Includes	******************/
#include "types.h"

/************************************************************************/
/*	                        DIO                                         */
/************************************************************************/
//Port A Register
#define PORTA	*((volatile uint8_t*)(0x3B))
#define DDRA	*((volatile uint8_t*)(0x3A))
#define PINA	*((volatile uint8_t*)(0x39))
//Port A Register
#define PORTB	*((volatile uint8_t*)(0x38))
#define DDRB	*((volatile uint8_t*)(0x37))
#define PINB	*((volatile uint8_t*)(0x36))
//Port A Register
#define PORTC	*((volatile uint8_t*)(0x35))
#define DDRC	*((volatile uint8_t*)(0x34))
#define PINC	*((volatile uint8_t*)(0x33))
//Port A Register
#define PORTD	*((volatile uint8_t*)(0x32))
#define DDRD	*((volatile uint8_t*)(0x31))
#define PIND	*((volatile uint8_t*)(0x30))

/************************************************************************/
/*							TIMER                                       */
/************************************************************************/

#define TIFR	*((volatile uint8_t*)(0x58))
#define TIMSK	*((volatile uint8_t*)(0x59))

//	TIMER0
#define TCCR0	*((volatile uint8_t*)(0x53))	
#define TCNT0	*((volatile uint8_t*)(0x52))

/************************************************************************/
/*                            Interrupt                                 */
/************************************************************************/
#define SREG	*((volatile uint8_t*)(0x5F))
#define MCUCR	*((volatile uint8_t*)(0x55))
#define MCUCSR	*((volatile uint8_t*)(0x54))
#define GICR	*((volatile uint8_t*)(0x5B))
#define GIFR	*((volatile uint8_t*)(0x5A))

/************************************************************************/
/*							ADC                                         */
/************************************************************************/
#define ADMUX	*((volatile uint8_t*)(0x27))
#define ADCSRA	*((volatile uint8_t*)(0x26))
#define ADCH	*((volatile uint8_t*)(0x25))
#define ADCL	*((volatile uint8_t*)(0x24))
#define SFIOR	*((volatile uint8_t*)(0x50))


#endif /* REGISTERS_H_ */