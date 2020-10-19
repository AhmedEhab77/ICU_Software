#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"TMR0_Priv.h"
#include"TMR0_Config.h"
#include"../Global Interrupt/GIE_Config.h"


/**GLOBAL POINTER TO FUNCTION**/
static void (*Gpfunc1)(void)=NULL;
static void (*Gpfunc2)(void)=NULL;
/********CALL BACK FUNCTION*****/
void TMR0_VidSetCallBackForOVF(void (*Lpfunc)(void))
{
	Gpfunc1=Lpfunc;
}
void TMR0_VidSetCallBackForCTC(void (*Lpfunc)(void))
{
	Gpfunc2=Lpfunc;
}

/*************ISR FOR TIMR0**********/
ISR(__vector_11)
{
	if(Gpfunc1 != NULL)
	{
		Gpfunc1();
	}
}

ISR(__vector_10)
{
	if(Gpfunc2 != NULL)
	{
		Gpfunc2();
	}
}

void TMR0_VidInit(void)
{
	/***************************MOODS OF TIMER0************************************/
	#if     TIMER0_Mood==Normal_MOOD
    CLR_BIT(TCCR0,WGM00);
    CLR_BIT(TCCR0,WGM01);
    #elif   TIMER0_Mood==PWM_PhaseCorrect_MOOD
    SET_BIT(TCCR0,WGM00);
    CLR_BIT(TCCR0,WGM01);
    #elif    TIMER0_Mood==CTC_MOOD
    CLR_BIT(TCCR0,WGM00);
    SET_BIT(TCCR0,WGM01);
    #elif   TIMER0_Mood==FAST_PWM_MOOD 
    SET_BIT(TCCR0,WGM00);
    SET_BIT(TCCR0,WGM01);
    #endif
	
	/***************************MOODS OF PRESCALER************************************/
	#if      Prescaler_Mood==NO_CLOCK_TIMER0
    CLR_BIT(TCCR0,CS00);
    CLR_BIT(TCCR0,CS01);
    CLR_BIT(TCCR0,CS02);
    #elif    Prescaler_Mood==NO_PRESCALER_TIMER0 
    CLR_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    CLR_BIT(TCCR0,CS02);
    #elif    Prescaler_Mood==PRESCALER_TIMER0_8
    CLR_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    CLR_BIT(TCCR0,CS02);
    #elif    Prescaler_Mood==PRESCALER_TIMER0_64
    SET_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    CLR_BIT(TCCR0,CS02);
    #elif    Prescaler_Mood==PRESCALER_TIMER0_256 
    CLR_BIT(TCCR0,CS00);
    CLR_BIT(TCCR0,CS01);
    SET_BIT(TCCR0,CS02);
    #elif    Prescaler_Mood==PRESCALER_TIMER0_1024
    SET_BIT(TCCR0,CS00);
    CLR_BIT(TCCR0,CS01);
    SET_BIT(TCCR0,CS02);
    #elif    Prescaler_Mood==EXT_CLOCK_TIMER0_FALLING
    CLR_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    SET_BIT(TCCR0,CS02);
	#elif    Prescaler_Mood==EXT_CLOCK_TIMER0_RISING
    SET_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    SET_BIT(TCCR0,CS02);
	#endif
	/*************************** TIMER0 OC0_PIN**********************/
	#if  OC0_MOOD==Normal_port_operation
    CLR_BIT(TCCR0,COM00);
    CLR_BIT(TCCR0,COM01);
    #elif   OC0_MOOD==Toggle_OC0 
    SET_BIT(TCCR0,COM00);
    CLR_BIT(TCCR0,COM01);
	#elif   OC0_MOOD==Reserved
    SET_BIT(TCCR0,COM00);
    CLR_BIT(TCCR0,COM01);
    #elif    OC0_MOOD==Clear_OC0 
    CLR_BIT(TCCR0,COM00);
    SET_BIT(TCCR0,COM01);
    #elif   OC0_MOOD==Set_OC0 
    SET_BIT(TCCR0,COM00);
    SET_BIT(TCCR0,COM01);
    #endif
}

void TMR0_VidOverFlowInterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}

void TMR0_VidOutputCompareMatchInterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}

void TMR0_VidPreLoadingTheCounter(u8 LOC_u8PreLoading_Value)
{
	TCNT0=LOC_u8PreLoading_Value;
}

void TMR0_VidCompareMatchValue(u8 LOC_u8CompareMatchValue)
{
	OCR0=LOC_u8CompareMatchValue;
}

void TMR0_VidSetDutyCycle(u8 LOC_u8DutyPercentage)
{
	OCR0=(LOC_u8DutyPercentage*255)/100;
}

