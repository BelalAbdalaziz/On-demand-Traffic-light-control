/*
 * File Name	: application.h
 * Description	:
 * Created		: 9/11/2022 6:12:40 AM
 *  Author		: Belal A.aziz
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

/**************		     Includes		******************/
#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"
/************************************************************************/
/*								MACRO                                   */
/************************************************************************/

#define NORMAL_MODE			0
#define PEDESTRAINS_MODE	1


#define CARS_LEDs_PORT	PORT_A
#define	C_GREEN_PIN		0
#define	C_YELLOW_PIN	1
#define	C_RED_PIN		2

#define GREEN_CARS		0
#define YELLOW_CARS		1
#define RED_CARS		2

#define pedestrians_LEDs_PORT	PORT_B
#define	P_GREEN_PIN		0
#define	P_YELLOW_PIN	1
#define	P_RED_PIN		2

/************************************************************************/
/*					Functions Prototype                                 */
/************************************************************************/
void greenForCars(void);
void yellowForCars(void);
void redForCars(void);
void pedstrainsMode(void);

void APP_init(void);
void APP_process(void);


#endif /* APPLICATION_H_ */