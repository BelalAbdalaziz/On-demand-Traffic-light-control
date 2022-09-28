/*
 * File Name	: button.c
 * Description	: 
 * Created		: 9/2022 
 *  Author		: Belal A.aziz
 */ 

/**************		     Includes		******************/
#include "button.h"
/**************		Functions Space		******************/

/*(1.button initialization Function "BUTTON_init" )*/
//use function of DIO_setPinDirection from lower layer
//to make button input device
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin)
{
	DIO_setPinDirection(buttonPort,buttonPin,IN);
}

/*(2.button read state Function "BUTTON_readState" )*/
//use function of DIO_readPinValue from lower layer
//to read state -->PRESSED '1' ,, UNPRESSED '0'
void BUTTON_readState(uint8_t buttonPort,uint8_t buttonPin,uint8_t *state)
{
	DIO_readPinValue(buttonPort,buttonPin,state);
}
