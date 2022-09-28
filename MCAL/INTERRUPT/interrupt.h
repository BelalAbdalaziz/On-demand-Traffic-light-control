 /*
 * File Name	: interrupt.h
 * Description	:
 * Created		: 9/2022
 *  Author		: Belal A.aziz
 */ 



#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/**************		     Includes		******************/

#include "../../utilities/macros.h"
#include "../../utilities/types.h"
#include "../../utilities/registers.h"

/************************************************************************/
/*							MACRO                                       */
/************************************************************************/

/***************		Interrupt Request				*****************/
//External interrupt request
#define EXT_INT_0 __vector_1	// INT0"PORT_D PIN_2" 
#define EXT_INT_1 __vector_2	// INT1"PORT_D PIN_3"
#define EXT_INT_2 __vector_3	// INT2"PORT_B PIN_3"

/***************		Interrupt Service Routine		*****************/
#define ISR(INT_VECT)\
	void INT_VECT(void)__attribute__((signal,used));\
	void INT_VECT(void)
//to implement ISR in File.c EX	-->	ISR(EXT_INT_0){	//write the ISR Logic here }

/***************			Global Interrupt			*****************/
//Enable	(set) global interrupt
#define sei()				__asm__ __volatile__ ("sei":::"memory"); //assembly code
#define ENABLE_GLOBAL_INT	SET_BIT(SREG,7)
//Disable	(CLR) global interrupt
#define cli()				__asm__ __volatile__ ("cli":::"memory"); //assembly code
#define DISABLE_GLOBAL_INT	CLR_BIT(SREG,7)

/***************			Interrupt Number			*****************/
#define INT_0	0
#define INT_1	1	
#define INT_2	2

/***************		Bits To enable EXT Interrupt	*****************/
#define ENABLE_INT_0_BIT	6
#define ENABLE_INT_1_BIT	7
#define ENABLE_INT_2_BIT	5

/***************			Interrupt Sense			*****************/
#define LOW_LEVEL		0
#define LOGICAL_CHANGE	1
#define FALLING_EDGE	2
#define RISING_EDGE		3

/***************	MCU Control Register – MCUCR BITS *******************/
#define ISC00	0	//bit to control sense of INT_0
#define ISC01	1	//bit to control sense of INT_0
#define ISC10	2	//bit to control sense of INT_1
#define ISC11	3	//bit to control sense of INT_1

/***********	MCU Control And Status Register – MCUCSR BITS ***********/
#define ISC2	6	//bit to control sense of INT_2

/************************************************************************/
/*						Functions prototype                             */
/************************************************************************/
void INTERRUPT_init(uint8_t interruptNumber ,uint8_t interruptSense);


#endif /* INTERRUPT_H_ */

/************************************************************************/
/*					Register Explain                                    */
/************************************************************************/
/*
MCU Control Register – MCUCR
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Bit 3:0 –ISC 11:00 : Sense control to EXT Interrupt (INT0,INT1) 
################################################################
ISC01	ISC00	Desc
  0		  0		LOW Level Of INT0 generate an interrupt request
  0		  1		Any Logic change on INT0 generate an interrupt request
  1		  0		Falling Edge of INT0 generate an interrupt request
  1		  1		Rising Edge of INT0 generate an interrupt request
  ----------------------------------------------------
ISC11	ISC10	Desc
  0		  0		LOW Level Of INT1 generate an interrupt request
  0		  1		Any Logic change on INT1 generate an interrupt request
  1		  0		Falling Edge of INT1 generate an interrupt request
  1		  1		Rising Edge of INT1 generate an interrupt request  
-----------------------------------------------------------------------
MCU Control And Status Register – MCUCSR
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Bit 6 –ISC2 : Sense control to EXT Interrupt (INT2)
################################################################
ISC2
 0		Falling Edge of INT1 generate an interrupt request
 1		Rising Edge of INT1 generate an interrupt request
-----------------------------------------------------------------------
General Interrupt Control Register – GICR
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Bit 7:5 – INT1 |INT0 |INT2 : to enable EXT Interrupt SET_BIT
-----------------------------------------------------------------------
*/
