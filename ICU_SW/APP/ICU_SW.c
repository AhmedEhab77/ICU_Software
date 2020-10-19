/*
 * ICU_SW.c
 *
 *  Created on: Oct 18, 2020
 *      Author: Ahmed Ehab
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Int.h"
#include"../MCAL/DIO/DIO_Config.h"
#include"../HAL//LCD/LCD_Interface.h"
#include"../MCAL/TIMER0-8bit/TMR0_Int.h"
#include"../MCAL/TIMER1-16bit/TMR1_Int.h"
#include"../MCAL/TIMER1-16bit/TMR1_Priv.h"
#include"../MCAL/Global Interrupt/GIE_Int.h"
#include"../MCAL/External Interrupt/EXT_Int.h"
#include"../MCAL/External Interrupt/EXT_Config.h"




u8 volatile flag=0;
volatile u32 TON=0;
volatile u32 TOFF=0;
u32 volatile OVF_Counter=0;
u32 Ttotal=0;
u32 Dutycycle=0;

void Timer1_func(void);
void External_func(void);

int main(void)
{
	 /*LEDS TO CHECK*/
	DIO_VidSetPinDirection(DIO_PORTA,PIN3,OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTA,PIN4,OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTA,PIN5,OUTPUT);

	/*PWM PIN FOR TIMER0*/
	DIO_VidSetPinDirection(DIO_PORTB,PIN3,OUTPUT);//OC0 PIN

	/*SET CALL BACK FUNCTIONS*/
	INT0_VidSetCallBack(External_func);
	TMR1_VidSetCallBackForOVF(Timer1_func);

	/*LCD INIT*/
	LCD_VidIntilaization_8bit();

	/*EXTERNAL INIT*/
	EXT0_ENABLE();
	EXT0_MOOD(Rising_edge);

	/*TIMER1 INIT TO COUNT*/
	TMR1_VidInit();
	TMR1_VidOverFlowInterruptEnable();

	/*TIMER0 INIT FOR PWM*/
	TMR0_VidInit();

	/*SET PWM FOR TIMER0*/

	TMR0_VidSetDutyCycle(10);


	/*ENABLE GLOBAL INTERRUPT*/
	GIE_VidENABLE();





	/*CAPTURE VALUE OF TON & TOFF*/
	while(1)
	{
		if(flag == 3)
		{


			LCD_VidSetPosition(0,0);
			LCD_VidWriteString("TON=");
			LCD_VidWriteNum(TON);
			LCD_VidSetPosition(1,0);
			LCD_VidWriteString("TOFF=");
			LCD_VidWriteNum((TOFF));

			flag=0;

		}
	}
	return 0;
}


/******************************************************************************************/
void External_func(void)
{
	if(flag == 0)
	{
		DIO_VidSetPinValue(DIO_PORTA,PIN3,HIGH);
		TCNT1=0;
		OVF_Counter=0;
		EXT0_MOOD(Falling_edge);
		flag=1;
	}
	else if(flag == 1)
	{
		DIO_VidSetPinValue(DIO_PORTA,PIN4,HIGH);
		TON=(u8)TCNT1+(OVF_Counter*65535);
		TCNT1=0;
		OVF_Counter=0;
		EXT0_MOOD(Rising_edge);
		flag=2;
	}
	else if(flag == 2)
	{
		DIO_VidSetPinValue(DIO_PORTA,PIN5,HIGH);
		TOFF=(u8)TCNT1+( OVF_Counter*65535 );
		TCNT1=0;
		OVF_Counter=0;
		flag=3;
	}
}

/************************************************************************************************/
void Timer1_func(void)
{
	OVF_Counter++;
}
