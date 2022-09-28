/*
 * File Name	: led.h
 * Description	:
 * Created		: 9/2022
 *  Author		: Belal A.aziz
 */ 



#ifndef LED_H_
#define LED_H_

//#define F_CPU 1000000u //1MHz
//#include <util/delay.h>	//use to make delay ,, after develop timer driver delete it
/**********		Includes	**********************/
#include "../../MCAL/DIO/dio.h"	
#include "../../MCAL//TIMER/timer.h"
/********* Functions prototype	******************/
void LED_init(uint8_t ledPort , uint8_t ledPin);
void LED_on	(uint8_t ledPort , uint8_t ledPin);
void LED_off(uint8_t ledPort , uint8_t ledPin);
void LED_toggel(uint8_t ledPort , uint8_t ledPin);
void LED_blink(uint8_t ledPort , uint8_t ledPin);
void LED_two_blink(uint8_t led_1_Port , uint8_t led_1_Pin,uint8_t led_2_Port, uint8_t led_2_Pin);





#endif /* LED_H_ */