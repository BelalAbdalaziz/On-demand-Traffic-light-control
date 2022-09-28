/*
 * File Name	: led.c
 * Description	: 
 * Created		: 9/2022 
 *  Author		: belal
 */ 

/**************		     Includes		******************/
#include "led.h"
/**************		Functions Space		******************/

/*(1.Led initial Function "LED_init" )*/
//	use function of DIO_setPinDirection 
// to make this device output --> direction is OUT
void LED_init(uint8_t ledPort , uint8_t ledPin)
{
	DIO_setPinDirection(ledPort,ledPin,OUT);
}

/*(2.turn on led Function "LED_on" )*/
//	use function of DIO_writePinValue 
//	to turn on this device set HIGH value
void LED_on	(uint8_t ledPort , uint8_t ledPin)
{
	DIO_writePinValue(ledPort,ledPin,HIGH);
}

/*(3.turn off led Function "LED_off" )*/
//	use function of DIO_writePinValue
//	to turn on this device set LOW value
void LED_off(uint8_t ledPort , uint8_t ledPin)
{
	DIO_writePinValue(ledPort,ledPin,LOW);
}
/*(4.led toggle Function "LED_toggle" )*/
//	use function of DIO_togglePin 
//	to make turn on is turn off and vise versa
void LED_toggel(uint8_t ledPort , uint8_t ledPin)
{
	DIO_togglePin(ledPort,ledPin);
}
/*(5.led blinking Function "LED_blink" )*/
//use function of DIO_writePinValue -->make it low and high
//between low and high must use delay 
void LED_blink(uint8_t ledPort , uint8_t ledPin)
{
		for (int i=0;i<10;i++)  //	250*2*10	=	5000ms	=	5sec
		{
			DIO_writePinValue(ledPort,ledPin,HIGH);
			delay_ms(250);
			DIO_writePinValue(ledPort,ledPin,LOW);
			delay_ms(250);

		}
}
void LED_two_blink(uint8_t led_1_Port , uint8_t led_1_Pin,uint8_t led_2_Port, uint8_t led_2_Pin)
{
	for (int i=0;i<10;i++)  //	250*2*10	=	5000ms	=	5sec
	{
		DIO_writePinValue(led_1_Port,led_1_Pin,HIGH);
		DIO_writePinValue(led_2_Port,led_2_Pin,HIGH);
		delay_ms(250);
		
		DIO_writePinValue(led_1_Port,led_1_Pin,LOW);
		DIO_writePinValue(led_2_Port,led_2_Pin,LOW);
		delay_ms(250);

	}
}
/**************		EOF		******************/


