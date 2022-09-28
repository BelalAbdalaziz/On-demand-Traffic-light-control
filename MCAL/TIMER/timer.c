/*
 * File Name	: timer.c
 * Description	:
 * Created		: 9/2022
 *  Author		: Belal A.aziz
 */ 


/**************		     Includes		******************/
#include "timer.h"

/**************		Functions Space		******************/

/********************************************************************************/
/*								1.Timer(0)										*/
/********************************************************************************/

/*(1.1.initialization Function "TIMER0_init	" )*/
//used to set timer configuration--> choose mode of operation ,, set counter start value 
//describe
void TIMER0_init()		// set Timer0 configuration (mode ,, initial value)
{
	//1.set timer configuration (mode,prescaler) 
	TCCR0=	NORMAL_NO_PRESCALER;		//control register
	//2.set start value of timer for (1ms delay)
	TCNT0=	INITIAL_VALUE;				//data register
}
/*(1.2.start timer Function "TIMER0_start" )*/
//
//describe
void TIMER0_start()		// start Timer by add prescaller
{
	//	1.set prescaler(clk src)
	SET_BIT(TCCR0,0);	//-->  BIT-> CS00=1  "no prescaler"
	
}
/*(1.3.stop timer Function "TIMER0_stop" )*/
//
//describe
void TIMER0_stop()
{
	TCCR0=0x00;
}
/*(1.4.get state Function "TIMER0_getState" )*/
//
//describe
void TIMER0_getState(uint8_t* state)
{
	//1.read overflow flag
	*state= READ_BIT(TIFR,0);
}
/*(1.5. delay_mili seconds Function "delay_ms" )*/
//
//describe

void delay_ms(uint16_t timeDelay)
{
	//1.start timer
	TIMER0_start();		//TCCR0 |=(1<<0);
	//2.loop to number of over flows and repeat
	uint16_t overFlowCounter=0;//delayCounter=0; //timeDelay*NUMBER_OF_OVERFLOW;
		
	for (overFlowCounter=0;overFlowCounter<(timeDelay*NUMBER_OF_OVERFLOW);overFlowCounter++)
		{
			//3.wait till overflow occur " overflow flag =1 'TOIE0' "
			while(READ_BIT(TIFR,0)==0);
			//4. clear overflow flag By SET operation to repeat this steps till 	overFlowCounter=NUMBER_OF_OVERFLOW
			SET_BIT(TIFR,0);
		}
	// 5.zero to overFlowCounter ,, and increment delay counter
	overFlowCounter=0;
	// 6.Timer stop
	TIMER0_stop();
}

