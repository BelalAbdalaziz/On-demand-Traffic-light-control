/*
 * File Name	: timer.h
 * Description	:
 * Created		: 9/2022
 *  Author		: Belal A.aziz
 */ 



#ifndef TIMER_H_
#define TIMER_H_

/**************		     Includes		******************/
#include "../../utilities/registers.h"
#include "../../utilities/macros.h"
/**************		     Macro			******************/
// Timer0 configuration into TCCR0				[			WGM01	COM01	COM00	WGM00	CS02	CS01	CS00  ]
//												[		   |	choose operation Mode	 | |  Choose Prescaler	| ]
#define NORMAL_NO_PRESCALER		0x00
/******	CALCULATIONS	********/
/*																------------
given{"8bit timer"-> n=8	,,	Fcpu=1MHz	,, no presclaer	,,	|Tdelay=1ms| }
calculate max delay												------------
###################	
-> Ttick=(presclaer/Fcpu)	=(1/1000000)=1us
-> Tmax=(2^n)(Ttick)		=(2^8)(1us) =256us
	---------------------------- 
calculate initial Value ,, number of overflows
###############################################
-> number of overflow(N) =(Tdelay/Tmax) =(1ms/256us)=4
-> initial value =(2^n)((Tdelay/Ttick)/N) = 6
*/
// initial value into TCNT0															 
#define INITIAL_VALUE			0x06												

//used when desiredDelay > maxDelay 
#define NUMBER_OF_OVERFLOW		4

/*************** Functions prototype	******************/
void TIMER0_init();			// set Timer0 configuration (mode ,, initial value)
void TIMER0_start();		// start Timer by add prescaller
void TIMER0_stop();			// 
void TIMER0_getState();
void delay_ms(uint16_t timeDelay);

#endif /* TIMER_H_ */

/****************************************************/
/*				Register Explain					*/
/****************************************************/
/* 
Timer/Counter0 Control Register – TCCR0 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Bit 6, 3 – WGM01:0: Waveform Generation Mode
############################################
WGM01 WGM00 Timer/Counter Mode of Operation
  0     0               Normal 
  0     1          PWM, Phase Correct
  1     0                 CTC
  1     1               Fast PWM
--------------------------------------------
RANGE : ( HIGH_VAL "1" or LOW_VAL "0")
---------------------------------------------------
Bit 5:4 – COM01:0: Compare Match Output Mode 
#############################################
Compare Output Mode, non-PWM Mode
COM01 COM00     Description
  0     0    Normal port operation, OC0 disconnected --> No compare match.
  0     1    Toggle OC0 on compare match
  1     0    Clear OC0 on compare match
  1     1    Set OC0 on compare match
---------------------------------------------------
Compare Output Mode, Fast PWM Mode
COM01 COM00           Description
  0     0   Normal port operation, OC0 disconnected -->No compare match.
  0     1              Reserved
  1     0   Clear OC0 on compare match, set OC0 at TOP
  1     1   Set OC0 on compare match, clear OC0 at TOP
---------------------------------------------------
Compare Output Mode, Phase Correct PWM Mode
COM01 COM00            Description
  0     0      Normal port operation, OC0 disconnected-->No compare match.
  0     1                Reserved
  1     0  Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
  1     1  Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
----------------------------------------------------
RANGE : ( HIGH_VAL "1" or LOW_VAL "0")
----------------------------------------------------
Bit 2:0 – CS02:01 Clock Select "prescaler"
############################################
CS02 CS01 CS00 	Description
0 	  0 	0 	No clock source (Timer/Counter stopped).
0  	  0 	1 	clk/(No prescaling)
0 	  1 	0 	clk/8 (From prescaler)
0     1 	1 	clk/64 (From prescaler)
1 	  0 	0 	clk/256 (From prescaler)
1 	  0 	1   clk/1024 (From prescaler)
1 	  1 	0 	External clock source on T0 pin. Clock on falling edge.
1 	  1 	1 	External clock source on T0 pin. Clock on rising edge.
RANGE : ( HIGH_VAL "1" or LOW_VAL "0")
*/

/*
Timer/Counter Interrupt Mask Register – TIMSK
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
RANGE : ( HIGH_VAL "1" or LOW_VAL "0") */

/*
Timer/Counter Interrupt Flag Register - TIFR 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable

RANGE : ( HIGH_VAL "1" or LOW_VAL "0") */