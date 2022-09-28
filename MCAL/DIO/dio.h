/*
 * File Name	: dio.h
 * Description	:
 * Created		: 9/2022
 *  Author		: Belal A.aziz
 */ 



#ifndef DIO_H_
#define DIO_H_

/**************		     Includes		******************/
#include "../../utilities/registers.h"
#include "../../utilities/macros.h"
/**************		     Macro			******************/
//Port Number define
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
//Pin Number Define
#define PIN_0	0
#define PIN_1	1
#define PIN_2	2
#define PIN_3	3
#define PIN_4	4
#define PIN_5	5
#define PIN_6	6
#define PIN_7	7

//Direction define
#define IN  0
#define OUT 1
//value define
#define LOW  0
#define HIGH 1

/**************		Functions prototype		******************/

/*************************************************/
/*		Dealing with pins	-->	bit by bit		*/
/***********************************************/

void DIO_setPinDirection(uint8_t portNumber , uint8_t pinNumber , uint8_t direction);// initialize function to config direction of pin --> in ,, out
void DIO_writePinValue(uint8_t portNumber , uint8_t pinNumber , uint8_t value);		// write function to write value on pin --> high ,, low
void DIO_togglePin(uint8_t portNumber , uint8_t pinNumber );						//toggle function to toggle value from high to low vise versa
void DIO_readPinValue(uint8_t portNumber , uint8_t pinNumber , uint8_t *value );	//read function to read pin value  ,, *value to return reading value in it

/*************************************************/
/*		Dealing with ports	--> 8bit by 8bit	*/
/***********************************************/
void DIO_setPortDirection(uint8_t portNumber ,  uint8_t direction); // initialize function to config direction of port"8-bits" --> in ,, out
void DIO_writePortValue(uint8_t portNumber ,  uint8_t value);		// write function to write value on port"8-bits" --> in decimal or binary or hex
void DIO_togglePort(uint8_t portNumber  );							//toggle function to toggle value from high to low vise versa
void DIO_readPortValue(uint8_t portNumber , uint8_t *value );		//read function to read port value ,,*value to return reading value in it

/*****************************************************/		// High	  Low
/*	Dealing with high Nibble	-->4bit by 4bit		*/		//Nibble Nibble
/***************************************************/		// xxxx	 xxxx
void DIO_setHighNibbleDirection(uint8_t portNumber ,  uint8_t direction);	// initialize function to config direction of High Nibble-> in'0'-> DDRx & 0x0f ,, out'1' -> DDRx | 0xf0
void DIO_writeHighNibbleValue(uint8_t portNumber ,  uint8_t value);			// write function to write value on port"4-bits" --> in decimal or binary or hex ->(PORT & 0x0f)|(val & 0xf0)
void DIO_toggleHighNibble(uint8_t portNumber  );							//toggle function to toggle value from high to low vise versa
void DIO_readHighNibbleValue(uint8_t portNumber , uint8_t *value );			//read function to read HighNibble value ,,*value to return reading value in it
															
/*****************************************************/
/*	Dealing with Low Nibble	-->   4bit by 4bit		*/
/***************************************************/
void DIO_setLowNibbleDirection(uint8_t portNumber ,  uint8_t direction);	// initialize function to config direction of High Nibble-> in'0'-> DDRx & 0xf0 ,, out'1' -> DDRx | 0x0f
void DIO_writeLowNibbleValue(uint8_t portNumber ,  uint8_t value);			// write function to write value on port"4-bits" --> in decimal or binary or hex 
void DIO_toggleLowNibble(uint8_t portNumber  );							//toggle function to toggle value from high to low vise versa
void DIO_readLowNibbleValue(uint8_t portNumber , uint8_t *value );			//read function to read HighNibble value ,,*value to return reading value in it


#endif /* DIO_H_ */