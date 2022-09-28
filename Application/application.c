/*
 * File Name	: application.c
 * Description	:
 * Created		: 9/2022 
 *  Author		: Belal A.aziz
 */ 


/**************		     Includes		******************/
#include "application.h"

uint8_t mode=NORMAL_MODE;
uint8_t carsLedState;
/**************		Functions Space		******************/

/************************************************************************/
/*							NORMAL_MODE                                 */
/************************************************************************/
void greenForCars(void)
{
	LED_on(CARS_LEDs_PORT,C_GREEN_PIN);
	delay_ms(5000);
	LED_off(CARS_LEDs_PORT,C_GREEN_PIN);
	carsLedState=GREEN_CARS;
}
void yellowForCars(void)
{
	LED_blink(CARS_LEDs_PORT,C_YELLOW_PIN);
	//delay_ms(1000);
	LED_off(CARS_LEDs_PORT,C_YELLOW_PIN);
	carsLedState=YELLOW_CARS;
}
void redForCars(void)
{
	LED_on(CARS_LEDs_PORT,C_RED_PIN);
	delay_ms(5000);
	LED_off(CARS_LEDs_PORT,C_RED_PIN);
	carsLedState=RED_CARS;
}
/************************************************************************/
/*							PEDESTRIANS_MODE                            */
/************************************************************************/
void pedstrainsMode(void)
{
	switch (carsLedState)
	{
		case GREEN_CARS:
		//blink yellow for booth
		LED_two_blink(CARS_LEDs_PORT,C_YELLOW_PIN,pedestrians_LEDs_PORT,P_YELLOW_PIN);
		//red led for cars ,, green led for pedestrians
		LED_on(CARS_LEDs_PORT,C_RED_PIN);
		LED_on(pedestrians_LEDs_PORT,P_GREEN_PIN);
		
		delay_ms(5000);
		
		LED_off(CARS_LEDs_PORT,C_RED_PIN);
		LED_off(pedestrians_LEDs_PORT,P_GREEN_PIN);
		//reset to normal mode
		mode=NORMAL_MODE;

		break;
		case YELLOW_CARS:
		//blink yellow for booth
		LED_two_blink(CARS_LEDs_PORT,C_YELLOW_PIN,pedestrians_LEDs_PORT,P_YELLOW_PIN);
		//red led for cars ,, green led for pedestrians
		LED_on(CARS_LEDs_PORT,C_RED_PIN);
		LED_on(pedestrians_LEDs_PORT,P_GREEN_PIN);
		delay_ms(5000);
		LED_off(CARS_LEDs_PORT,C_RED_PIN);
		LED_off(pedestrians_LEDs_PORT,P_GREEN_PIN);
		//reset to normal mode
		mode=NORMAL_MODE;
		break;
		case RED_CARS:
		//red led for cars ,, green led for pedestrians
		LED_on(CARS_LEDs_PORT,C_RED_PIN);
		LED_on(pedestrians_LEDs_PORT,P_GREEN_PIN);
		delay_ms(5000);
		LED_off(CARS_LEDs_PORT,C_RED_PIN);
		LED_off(pedestrians_LEDs_PORT,P_GREEN_PIN);
		//reset to normal mode
		mode=NORMAL_MODE;
		break;
	}
}
/*(1.initialization Function "APP_init" )*/
//use this function to initialize all peripherals 
//to make devices input or output device ,, and interrupt init
void APP_init()
{
	//initialization functions
	//1.three Leds for cars
	LED_init(CARS_LEDs_PORT,C_GREEN_PIN);
	LED_init(CARS_LEDs_PORT,C_YELLOW_PIN);
	LED_init(CARS_LEDs_PORT,C_RED_PIN);
	//2.three Leds for pedestrians
	LED_init(pedestrians_LEDs_PORT,P_GREEN_PIN);
	LED_init(pedestrians_LEDs_PORT,P_YELLOW_PIN);
	LED_init(pedestrians_LEDs_PORT,P_RED_PIN);
	//3.push button connected to INT0 pin for pedestrian
	BUTTON_init(PORT_D,PIN_2);
	INTERRUPT_init(INT_0,RISING_EDGE);
	
}

/*(1.process Function "APP_process" )*/
//use this function to do all repetitive functions 
void APP_process()
{
	while (1)
	{
		//repetitive functions
		
		//1.normal mode
		if (mode==NORMAL_MODE)
		{
			greenForCars();
			if (mode==PEDESTRAINS_MODE)
			{	//2.pedestrians Mode 
				pedstrainsMode();	}
			else
			{
				yellowForCars();
				if (mode==PEDESTRAINS_MODE)
				{	//2.pedestrians Mode
						pedstrainsMode();	}
				else
				{	redForCars();
					if (mode==PEDESTRAINS_MODE)
					{	//2.pedestrians Mode
						pedstrainsMode();	}
				}
			}
		}
		
		
	}
}

/************************************************************************/
/*				Interrupt service Routine                               */
/************************************************************************/
ISR(EXT_INT_0)
{
	if (mode==NORMAL_MODE)
	{
		mode=PEDESTRAINS_MODE;
	}
	else
	{
		//do nothing
		//mode=NORMAL_MODE;
	}
	
}
