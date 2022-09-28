/*
 * File Name	: button.h
 * Description	: 
 * Created		: 9/2022 
 *  Author		: Belal A.aziz
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

/**************		     Includes		******************/
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL//INTERRUPT/interrupt.h"
/**************		     Macro		******************/

//	Pin out  CCT Connection
#define BUTTON_1_PORT		PORT_C		
#define BUTTON_1_PIN		PIN_0		//Button_1	pull down configuration

#define BUTTON_2_PORT		PORT_D
#define BUTTON_2_PIN		PIN_0		//Button_2	pull Up configuration

//	Button States Pull Down Config --> normally GND
#define UNPRESSED_PD	0		//like LOW from DIO  ,, PD'Pull Down Configuration'
#define PRESSED_PD		1		//like HIGH from DIO ,, PD'Pull Down Configuration'

//	Button States Pull Up Config --> normally VCC
#define UNPRESSED_PU	1		//like HIGH from DIO  ,, PU'Pull Up Configuration'
#define PRESSED_PU		0		//like LOW from DIO ,, PU'Pull Up Configuration'



/*************** Functions prototype	******************/
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);
void BUTTON_readState(uint8_t buttonPort,uint8_t buttonPin,uint8_t *state);




#endif /* BUTTON_H_ */