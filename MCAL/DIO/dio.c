/*
 * File name	: dio.c
 * Description	:
 * Created		: 9/2022 
  *  Author		: Belal A.Aziz
 */ 
/**************		     Includes		******************/
#include "dio.h"

/**************		Functions Space		******************/

/*************************************************************************************/
/*						1.Dealing with pins	-->	bit by bit							*/
/***********************************************************************************/

/*(1.1.initialize Function "setPinDirection" )*/
// initialize function to config direction of pin --> in ,, out
//PORT_x --> name of port is 'x' ,, DDRx -->Data Direction Register if direction IN  -> zero -> clearBit
//																	if direction OUT -> one ->  setBit
void DIO_setPinDirection(uint8_t portNumber , uint8_t pinNumber , uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:						
			if(direction == IN)				
			{
				CLR_BIT(DDRA,pinNumber);	//DDRA &=~(1<<pinNumber);		
			}
			else if (direction== OUT)
			{
				SET_BIT(DDRA,pinNumber);	//DDRA |=(1<<pinNumber);
			}
			else
			{
				//error handling
			}
		break;	
		case PORT_B:
			if(direction == IN)
			{
				CLR_BIT(DDRB,pinNumber);	//DDRB &=~(1<<pinNumber);
			}
			else if (direction== OUT)
			{
				SET_BIT(DDRB,pinNumber);	//DDRB |=(1<<pinNumber);
			}
			else
			{
				//error handling
			}
		break;
		case PORT_C:
			if(direction == IN)
			{
				CLR_BIT(DDRC,pinNumber);	//DDRC &=~(1<<pinNumber);
			}
			else if (direction== OUT)
			{
				SET_BIT(DDRC,pinNumber);	//DDRC |=(1<<pinNumber);
			}
			else
			{
				//error handling
			}
		break;
		case PORT_D:
			if(direction == IN)
			{
				CLR_BIT(DDRD,pinNumber);	//DDRD &=~(1<<pinNumber);
			}
			else if (direction== OUT)
			{
				SET_BIT(DDRD,pinNumber);	//DDRD |=(1<<pinNumber);
			}
			else
			{
				//error handling
			}
		break;
	}
}

/*(1.2.Write Function "DIO_writePinValue")*/
// write function to write value on pin --> high ,, low
//PORT_x --> name of port is 'x' ,, PORTx -->Data Register is used to write value	 if value LOW  -> zero -> clearBit
//																					 if value HIGH -> one  ->  setBit
void DIO_writePinValue(uint8_t portNumber , uint8_t pinNumber , uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
			if(value == LOW)
			{
			CLR_BIT(PORTA,pinNumber);	//PORTA &=~(1<<pinNumber);
			}
			else if (value== HIGH)
			{
				SET_BIT(PORTA,pinNumber);	//PORTA |=(1<<pinNumber);
			}
			else
			{
				//error handling
			}
		break;
		case PORT_B:
			if(value == LOW)
			{
				CLR_BIT(PORTB,pinNumber);	//PORTB &=~(1<<pinNumber);
			}
			else if (value== HIGH)
			{
				SET_BIT(PORTB,pinNumber);	//PORTB |=(1<<pinNumber);
			}
			else
			{
				//error handling
			}
		break;
		case PORT_C:
			if(value == LOW)
			{
				CLR_BIT(PORTC,pinNumber);	//PORTC &=~(1<<pinNumber);
			}
			else if (value== HIGH)
			{
				SET_BIT(PORTC,pinNumber);	//PORTC |=(1<<pinNumber);
			}
			else
			{
				//error handling
			}
		break;
		case PORT_D:
			if(value == LOW)
			{
				CLR_BIT(PORTD,pinNumber);	//PORTD &=~(1<<pinNumber);
			}
			else if (value== HIGH)
			{
				SET_BIT(PORTD,pinNumber);	//PORTD |=(1<<pinNumber);
			}
			else
			{
				//error handling
			}
		break;
	}
}

/*(1.3.Toggle Function "DIO_togglePin")*/
//toggle function to toggle value from high to low vise versa
//PORT_x --> name of port is 'x' ,, PORTx -->Data Register is used to write value	 so --> to toggle pin use toggle macro 
void DIO_togglePin(uint8_t portNumber , uint8_t pinNumber )
{
	switch (portNumber)
	{
		case PORT_A:
			TOG_BIT(PORTA,pinNumber);  // PORTA ^=(1<<pinNumber);
		break;
		case PORT_B:
			TOG_BIT(PORTB,pinNumber);  // PORTB ^=(1<<pinNumber);
		break;
		case PORT_C:
			TOG_BIT(PORTC,pinNumber);  // PORTC ^=(1<<pinNumber);
		break;
		case PORT_D:
			TOG_BIT(PORTD,pinNumber);  // PORTD ^=(1<<pinNumber);
		break;
	}
}

/*(1.4.Read Function"DIO_readPinValue")*/
//read function to read pin value
// read function to read value on pin --> high ,, low
//POR_x --> name of port is 'x' ,, PINx -->Port Input Register is used to read value if value LOW  -> read zero 
//																					 if value HIGH -> read one  
void DIO_readPinValue(uint8_t portNumber , uint8_t pinNumber , uint8_t *value )	//*value to return reading value in it
{
	switch (portNumber)
	{
		case PORT_A:
			*value=READ_BIT(PINA,pinNumber);  // (PINA&(1<<pinNumber)>>pinNumber);
		break;
		case PORT_B:
			*value=READ_BIT(PINB,pinNumber);  // (PINB&(1<<pinNumber)>>pinNumber);
		break;
		case PORT_C:
			*value=READ_BIT(PINC,pinNumber);  // (PINC&(1<<pinNumber)>>pinNumber);
		break;
		case PORT_D:
			*value=READ_BIT(PIND,pinNumber);  // (PIND&(1<<pinNumber)>>pinNumber);
		break;
	}
}


/*************************************************************************************/
/*				2.Dealing with ports--> 8bit by 8bit								*/
/***********************************************************************************/

/*(2.1.initialize Function "setPortDirection" )*/
// initialize function to config direction of pin --> in ,, out
//PORT_x --> name of port is 'x' ,, DDRx -->Data Direction Register if direction IN  -->DDRx= 0x00 ,,if direction OUT	-->DDRx= 0xff
void DIO_setPortDirection(uint8_t portNumber ,  uint8_t direction)
{
	if (direction==IN)
	{
		switch(portNumber)
		{
			case PORT_A : DDRA=0x00; break;
			case PORT_B : DDRB=0x00; break;
			case PORT_C : DDRC=0x00; break;
			case PORT_D : DDRD=0x00; break;
			
		}
	}
	else if (direction==OUT)
	{
		switch(portNumber)
		{
			case PORT_A : DDRA=0xff; break;
			case PORT_B : DDRB=0xff; break;
			case PORT_C : DDRC=0xff; break;
			case PORT_D : DDRD=0xff; break;
			
		}
		
	}
	else
	{
		//error Handling
	}
}

/*(2.2.Write Function "DIO_writePortValue")*/
// write function to write value on pin --> Value in decimal or binary"0b--" or hex"0x--"
//PORT_x --> name of port is 'x' ,, PORTx -->Data Register is used to write value	 --> PORTx=value
void DIO_writePortValue(uint8_t portNumber ,  uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:	PORTA=value;	break;
		case PORT_B:	PORTB=value;	break;
		case PORT_C:	PORTC=value;	break;
		case PORT_D:	PORTD=value;	break;
	}
}

/*(2.3.Toggle Function "DIO_togglePort")*/
//toggle function to toggle value from high to low vise versa
//PORT_x --> name of port is 'x' ,, PORTx -->Data Register is used to write value to toggle -->	PORTx^=0xff   in this xoring " 0 xor 1 =1" ,, "1 xor 1 = 0"
void DIO_togglePort(uint8_t portNumber  )
{
	switch(portNumber)
	{
		case PORT_A:	PORTA^=0xff;	break;
		case PORT_B:	PORTB^=0xff;	break;
		case PORT_C:	PORTC^=0xff;	break;
		case PORT_D:	PORTD^=0xff;	break;
	}
}

/*(2.4.Read Function"DIO_readPinValue")*/
//read function to read port value
//POR_x --> name of port is 'x' ,, PINx -->Port Input Register is used to read value and save it in--> *value 
void DIO_readPortValue(uint8_t portNumber , uint8_t *value )
{
	switch(portNumber)
	{
		case PORT_A:	*value=PINA;	break;
		case PORT_B:	*value=PINB;	break;
		case PORT_C:	*value=PINC;	break;
		case PORT_D:	*value=PIND;	break;
	}
}


/*************************************************************************************/		// High	  Low
/*			3.Dealing with high Nibble	-->4bit by 4bit								*/		//Nibble Nibble
/***********************************************************************************/		// xxxx	 xxxx

/*(3.1.initialize Function "DIO_setHighNibbleDirection" )*/
// initialize function to config direction of High Nibble-> IN,,OUT
// in'0'-> DDRx & 0x0f -- let high zero , store least --> out'1' -> DDRx | 0xf0  --let high one , store least  
void DIO_setHighNibbleDirection(uint8_t portNumber ,  uint8_t direction)
{
	if (direction==IN)
	{
		switch(portNumber)
		{
			case PORT_A : DDRA &=0x0f; break;
			case PORT_B : DDRB &=0x0f; break;
			case PORT_C : DDRC &=0x0f; break;
			case PORT_D : DDRD &=0x0f; break;
			
		}
	}
	else if (direction==OUT)
	{
		switch(portNumber)
		{
			case PORT_A : DDRA |=0xf0; break;
			case PORT_B : DDRB |=0xf0; break;
			case PORT_C : DDRC |=0xf0; break;
			case PORT_D : DDRD |=0xf0; break;
			
		}
		
	}
	else
	{
		//error Handling
	}

}

/*(3.2.Write Function "DIO_writeHighNibbleValue")*/
// write function to write value on port"4-bits" --> in decimal or binary or hex 
//->(PORTx & 0x0f)|(val & 0xf0) -->Store least from PORTx ,, Store Highest from value ,, then ORing them
void DIO_writeHighNibbleValue(uint8_t portNumber ,  uint8_t value)	
{
	switch(portNumber)
	{
		case PORT_A:	PORTA=(PORTA & 0x0f)|(value & 0xf0);	break;
		case PORT_B:	PORTB=(PORTB & 0x0f)|(value & 0xf0);	break;
		case PORT_C:	PORTC=(PORTC & 0x0f)|(value & 0xf0);	break;
		case PORT_D:	PORTD=(PORTD & 0x0f)|(value & 0xf0);	break;
	}

}

/*(3.3.Toggle Function "DIO_toggleHighNibble")*/
//toggle function to toggle value from high to low vise versa																															
//PORT_x --> name of port is 'x' ,, PORTx -->Data Register is used to write value to toggle 
//-->	PORTA=(PORTx ^ 0xf0)|(PORTx & 0x0f)		in this xoring	" 0 xor 1 =1" ,, "1 xor 1 = 0" --> toggle highest ,, store least			
void DIO_toggleHighNibble(uint8_t portNumber  )
{
	switch(portNumber)
	{
		case PORT_A:	PORTA=(PORTA ^ 0xf0)|(PORTA & 0x0f);	break;
		case PORT_B:	PORTB=(PORTB ^ 0xf0)|(PORTB & 0x0f);	break;
		case PORT_C:	PORTC=(PORTC ^ 0xf0)|(PORTC & 0x0f);	break;
		case PORT_D:	PORTD=(PORTD ^ 0xf0)|(PORTD & 0x0f);	break;
	}

}	

/*(3.4.Read Function"DIO_readHighNibbleValue")*/			
//read function to read HighNibble value ,,*value to return reading value in it
//use PIN register to read DIO
// -->*value=((PINA & 0xf0)>>4) --> store highest then shift left
void DIO_readHighNibbleValue(uint8_t portNumber , uint8_t *value )		
{
	switch(portNumber)
	{
		case PORT_A:	*value=((PINA & 0xf0)>>4);	break;
		case PORT_B:	*value=((PINB & 0xf0)>>4);	break;
		case PORT_C:	*value=((PINC & 0xf0)>>4);	break;
		case PORT_D:	*value=((PIND & 0xf0)>>4);	break;
	}
}

/*************************************************************************************/		// High	  Low
/*					4.Dealing with low Nibble	-->4bit by 4bit						*/		//Nibble Nibble
/***********************************************************************************/		// xxxx	 xxxx

/*(4.1.initialize Function "DIO_setLowNibbleDirection" )*/
// initialize function to config direction of Low Nibble-> IN,,OUT
// in'0'-> DDRx & 0xf0 -- let low zero , store highest --> out'1' -> DDRx | 0x0f  --let Low one , store highest
void DIO_setLowNibbleDirection(uint8_t portNumber ,  uint8_t direction)
{
	if (direction==IN)
	{
		switch(portNumber)
		{
			case PORT_A : DDRA &=0xf0; break;
			case PORT_B : DDRB &=0xf0; break;
			case PORT_C : DDRC &=0xf0; break;
			case PORT_D : DDRD &=0xf0; break;
			
		}
	}
	else if (direction==OUT)
	{
		switch(portNumber)
		{
			case PORT_A : DDRA |=0x0f; break;
			case PORT_B : DDRB |=0x0f; break;
			case PORT_C : DDRC |=0x0f; break;
			case PORT_D : DDRD |=0x0f; break;
			
		}
		
	}
	else
	{
		//error Handling
	}
	
}

/*(4.2.Write Function "DIO_writeLowNibbleValue")*/
// write function to write value on port"4-bits" --> in decimal or binary or hex
//->(PORTx & 0xf0)|(val & 0x0f) -->Store higest from PORTx ,, Store least from value ,, then ORing them
void DIO_writeLowNibbleValue(uint8_t portNumber ,  uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:	PORTA=(PORTA & 0xf0)|(value & 0x0f);	break;
		case PORT_B:	PORTB=(PORTB & 0xf0)|(value & 0x0f);	break;
		case PORT_C:	PORTC=(PORTC & 0xf0)|(value & 0x0f);	break;
		case PORT_D:	PORTD=(PORTD & 0xf0)|(value & 0x0f);	break;
	}
}

/*(4.3.Toggle Function "DIO_toggleHighNibble")*/
//toggle function to toggle value from high to low vise versa
//PORT_x --> name of port is 'x' ,, PORTx -->Data Register is used to write value to toggle
//-->	PORTA=(PORTx ^ 0x0f)|(PORTx & 0xf0)		in this xoring	" 0 xor 1 =1" ,, "1 xor 1 = 0" --> toggle Least ,, store highest
void DIO_toggleLowNibble(uint8_t portNumber  )
{
	switch(portNumber)
	{
		case PORT_A:	PORTA=(PORTA ^ 0x0f)|(PORTA & 0xf0);	break;
		case PORT_B:	PORTB=(PORTB ^ 0x0f)|(PORTB & 0xf0);	break;
		case PORT_C:	PORTC=(PORTC ^ 0x0f)|(PORTC & 0xf0);	break;
		case PORT_D:	PORTD=(PORTD ^ 0x0f)|(PORTD & 0xf0);	break;
	}

}

/*(4.4.Read Function"DIO_readLowNibbleValue")*/
//read function to read HighNibble value ,,*value to return reading value in it
//use PIN register to read DIO
// -->*value=(PINx & 0x0f) --> store Least without any shift cause it is least value
void DIO_readLowNibbleValue(uint8_t portNumber , uint8_t *value )
{
	switch(portNumber)
	{
		case PORT_A:	*value=(PINA & 0x0f);	break;
		case PORT_B:	*value=(PINB & 0x0f);	break;
		case PORT_C:	*value=(PINC & 0x0f);	break;
		case PORT_D:	*value=(PIND & 0x0f);	break;
	}
}



/**************		EOF		******************/
