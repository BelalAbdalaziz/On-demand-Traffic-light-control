/*
 * File Name	: macros.h 
 * Description	:
 * Created		: 9/2022
 *  Author		: Belal A.aziz
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(Reg,BIT_NO)			Reg |=(1<<BIT_NO)
#define CLR_BIT(Reg,BIT_NO)			Reg &=~ (1<<BIT_NO)
#define READ_BIT(Reg,BIT_NO)		(Reg&(1<<BIT_NO)>>BIT_NO)
#define TOG_BIT(Reg,BIT_NO)			Reg ^=(1<<BIT_NO)

#define SET_2BITS(Reg,FIRST_BIT_NO,SECOND_BIT_NO)	Reg|=(1<<FIRST_BIT_NO) |(1<<SECOND_BIT_NO)


#endif /* MACROS_H_ */