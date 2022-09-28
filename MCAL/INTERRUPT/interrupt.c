/*
 * File Name	: interrupt.c
 * Description	:
 * Created		: 9/2022
 *  Author		: Belal A.aziz
 */ 


/**************		     Includes		******************/

#include "interrupt.h"

void INTERRUPT_init(uint8_t interruptNumber ,uint8_t interruptSense)
{
	//1.enable global interrupt (from SREG or assembly code)
	ENABLE_GLOBAL_INT;
	//sei();
	//2.choose interrupt sense
	switch(interruptSense)
		{
			case LOW_LEVEL :
					if (interruptNumber==INT_0)
					{
					//2.choose interrupt sense"LOW LEVEL"
						CLR_BIT(MCUCR,ISC00);	//ISC01 ISC00
						CLR_BIT(MCUCR,ISC01);	//	0	  0 ->	LOW LEVEL
					//3.Enable External Interrupt "INT0"
						SET_BIT(GICR,ENABLE_INT_0_BIT);
					}
					else if(interruptNumber==INT_1)
					{
					//2.choose interrupt sense"LOW LEVEL"
						CLR_BIT(MCUCR,ISC10);	//ISC11 ISC10
						CLR_BIT(MCUCR,ISC11);	//	0	  0 ->	LOW LEVEL
					//3.Enable External Interrupt "INT1"
						SET_BIT(GICR,ENABLE_INT_1_BIT);
					
					}
			break;
			
		case LOGICAL_CHANGE :
					if (interruptNumber==INT_0)
					{
						//2.choose interrupt sense"LOGICAL CHANGE"
						SET_BIT(MCUCR,ISC00);	//ISC01 ISC00
						CLR_BIT(MCUCR,ISC01);	//	0	  1 ->	LOGICAL CHANGE
						//3.Enable External Interrupt "INT0"
						SET_BIT(GICR,ENABLE_INT_0_BIT);
					}
					else if(interruptNumber==INT_1)
					{
						//2.choose interrupt sense"LOGICAL CHANGE"
						SET_BIT(MCUCR,ISC10);	//ISC11 ISC10
						CLR_BIT(MCUCR,ISC11);	//	0	  1 ->	LOGICAL CHANGE
						//3.Enable External Interrupt "INT1"
						SET_BIT(GICR,ENABLE_INT_1_BIT);
						
					}
			break;
		
		case FALLING_EDGE :
				if (interruptNumber==INT_0)
				{
					//2.choose interrupt sense"FALLING EDGE"
					CLR_BIT(MCUCR,ISC00);	//ISC01 ISC00
					SET_BIT(MCUCR,ISC01);	//	1	  0 ->	FALLING EDGE
					//3.Enable External Interrupt "INT0"
					SET_BIT(GICR,ENABLE_INT_0_BIT);
				}
				else if(interruptNumber==INT_1)
				{
					//2.choose interrupt sense"FALLING EDGE"
					SET_BIT(MCUCR,ISC10);	//ISC11 ISC10
					CLR_BIT(MCUCR,ISC11);	//	1	  0 ->	FALLING EDGE
					//3.Enable External Interrupt "INT1"
					SET_BIT(GICR,ENABLE_INT_1_BIT);
					
				}
				else if(interruptNumber==INT_2)
				{
					//2.choose interrupt sense"FALLING EDGE"
					CLR_BIT(MCUCR,ISC2);	//ISC2 ->	0	 ->	FALLING EDGE	
					//3.Enable External Interrupt "INT2"
					SET_BIT(GICR,ENABLE_INT_2_BIT);
					
				}
		
			break;
		
		case RISING_EDGE :
			if (interruptNumber==INT_0)
					{
						//2.choose interrupt sense"RISING EDGE"
						SET_BIT(MCUCR,ISC00);	//ISC01 ISC00
						SET_BIT(MCUCR,ISC01);	//	1	  1 ->	RISING EDGE
						//3.Enable External Interrupt "INT0"
						SET_BIT(GICR,ENABLE_INT_0_BIT);
					}
					else if(interruptNumber==INT_1)
					{
						//2.choose interrupt sense"RISING EDGE"
						SET_BIT(MCUCR,ISC10);	//ISC11 ISC10
						SET_BIT(MCUCR,ISC11);	//	1	  1 ->	RISING EDGE
						//3.Enable External Interrupt "INT1"
						SET_BIT(GICR,ENABLE_INT_1_BIT);
					
					}
					else if(interruptNumber==INT_2)
					{
						//2.choose interrupt sense"RISING EDGE"
						SET_BIT(MCUCR,ISC2);	//ISC2 ->	1	 ->	RISING EDGE	
						//3.Enable External Interrupt "INT2"
						SET_BIT(GICR,ENABLE_INT_2_BIT);
					
					}
			break;
		}
}