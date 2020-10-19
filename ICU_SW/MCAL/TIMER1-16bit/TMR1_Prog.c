#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"TMR1_Priv.h"
#include"TMR1_Config.h"
#include"../Global Interrupt/GIE_Config.h"


/**GLOBAL POINTER TO FUNCTION**/
static void (*Gpfunc1)(void)=NULL;
static void (*Gpfunc2)(void)=NULL;
static void (*Gpfunc3)(void)=NULL;
/********CALL BACK FUNCTION*****/
void TMR1_VidSetCallBackForOVF(void (*Lpfunc)(void))
{
	Gpfunc1=Lpfunc;
}
void TMR1_VidSetCallBackForCTC(void (*Lpfunc)(void))
{
	Gpfunc2=Lpfunc;
}
void TMR1_VidSetCallBackForCaptureUnit(void (*Lpfunc)(void))
{
	Gpfunc3=Lpfunc;
}

/*************ISR FOR TIMR1**********/
ISR(__vector_9)
{
	if(Gpfunc1 != NULL)
	{
		Gpfunc1();
	}
}

ISR(__vector_7)
{
	if(Gpfunc2 != NULL)
	{
		Gpfunc2();
	}
}
ISR(__vector_6)
{
	if(Gpfunc3 != NULL)
	{
		Gpfunc1();
	}
}

void TMR1_VidInit(void)
{
	/***************************MOODS OF TIMER0************************************/
	#if     TIMER1_Mood==Normal_MOOD
    CLR_BIT(TCCR1A,WGM10);
    CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
    #elif    TIMER2_Mood==CTC_MOOD_OCR1A
    CLR_BIT(TCCR1A,WGM10);
    CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
    #elif   TIMER2_Mood==FAST_PWM_MOOD_ICR
    CLR_BIT(TCCR1A,WGM10);
    SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
    #endif
	
	/***************************MOODS OF PRESCALER************************************/
	#if      Prescaler_Mood_TIMER1 ==NO_CLOCK_TIMER1
    CLR_BIT(TCCR1B,CS10);
    CLR_BIT(TCCR1B,CS11);
    CLR_BIT(TCCR1B,CS12);
    #elif    Prescaler_Mood_TIMER1 ==NO_PRESCALER_TIMER1
    CLR_BIT(TCCR1B,CS10);
    SET_BIT(TCCR1B,CS11);
    CLR_BIT(TCCR1B,CS12);
    #elif    Prescaler_Mood_TIMER1 ==PRESCALER_TIMER1_8
    CLR_BIT(TCCR1B,CS10);
    SET_BIT(TCCR1B,CS11);
    CLR_BIT(TCCR1B,CS12);
    #elif    Prescaler_Mood_TIMER1 ==PRESCALER_TIMER1_64
    SET_BIT(TCCR1B,CS10);
    SET_BIT(TCCR1B,CS11);
    CLR_BIT(TCCR1B,CS12);
    #elif    Prescaler_Mood_TIMER1 ==PRESCALER_TIMER1_256 
    CLR_BIT(TCCR1B,CS10);
    CLR_BIT(TCCR1B,CS11);
    SET_BIT(TCCR1B,CS12);
    #elif    Prescaler_Mood_TIMER1 ==PRESCALER_TIMER1_1024
    SET_BIT(TCCR1B,CS10);
    CLR_BIT(TCCR1B,CS11);
    SET_BIT(TCCR1B,CS12);
    #elif    Prescaler_Mood_TIMER1 ==EXT_CLOCK_TIMER1_FALLING
    CLR_BIT(TCCR1B,CS10);
    SET_BIT(TCCR1B,CS11);
    SET_BIT(TCCR1B,CS12);
	#elif    Prescaler_Mood_TIMER1 ==EXT_CLOCK_TIMER1_RISING
    SET_BIT(TCCR1B,CS10);
    SET_BIT(TCCR1B,CS11);
    SET_BIT(TCCR1B,CS12);
	#endif
	/*************************** TIMER2 OC1_PIN**********************/
	#if   OC1_CHANNEL==OC1A_CHANNEL
	
	#if  OC1A_CHANNEL==Normal_port_operation
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	#elif   OC1A_CHANNEL==Toggle_OC1A 
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	#elif    OC1A_CHANNEL==Clear_OC1A 
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#elif   OC1A_CHANNEL==Set_OC1A 
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#endif
	
    #if OC1_CHANNEL==OC1B_CHANNEL
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
	#elif   OC1A_CHANNEL==Toggle_OC1B
	SET_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
	#elif    OC1A_CHANNEL==Clear_OC1B
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#elif   OC1B_CHANNEL==Set_OC1B 
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#endif

    #endif
}

void TMR1_VidOverFlowInterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}

void TMR1_VidOutputCompareMatchInterruptEnable_A(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void TMR1_VidOutputCompareMatchInterruptEnable_B(void)
{
	SET_BIT(TIMSK,OCIE1B);
}

void TMR1_VidPreLoadingTheCounter(u16 LOC_u8PreLoading_Value)
{
	TCNT1=LOC_u8PreLoading_Value;
}

void TMR1_VidCompareMatchValue_A(u16 LOC_u8CompareMatchValue)
{
	OCR1A=LOC_u8CompareMatchValue;
}
void TMR1_VidCompareMatchValue_B(u16 LOC_u8CompareMatchValue)
{
	OCR1B=LOC_u8CompareMatchValue;
}

void TMR1_VidSetDutyCycle(u16 LOC_u8TonValue)
{
	OCR1A=LOC_u8TonValue;
}

void TMR1_VidSetICRRegister(u16 LOC_u8ICR_Value)
{
	ICR1=LOC_u8ICR_Value;
}
void TMR1_VidInputCaptureInterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}


