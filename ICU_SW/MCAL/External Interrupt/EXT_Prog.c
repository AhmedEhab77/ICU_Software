#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"EXT_Priv.h"
#include"EXT_Config.h"
#include"../Global Interrupt/GIE_Config.h"

/**GLOBAL POINTER TO FUNCTION**/
static void (*Gpfunc1)(void)=NULL;
static void (*Gpfunc2)(void)=NULL;
static void (*Gpfunc3)(void)=NULL;
/********CALL BACK FUNCTION*****/
void INT0_VidSetCallBack(void (*Lpfunc)(void))
{
	Gpfunc1=Lpfunc;
}
void INT1_VidSetCallBack(void (*Lpfunc)(void))
{
	Gpfunc2=Lpfunc;
}
void INT2_VidSetCallBack(void (*Lpfunc)(void))
{
	Gpfunc3=Lpfunc;
}

/*************ISR FOR EXTERNAL INTERRUPT**********/
ISR(__vector_1)
{
	if(Gpfunc1 != NULL)
	{
		Gpfunc1();
	}
}
ISR(__vector_2)
{
	if(Gpfunc2 != NULL)
	{
		Gpfunc2();
	}
}
ISR(__vector_3)
{
	if(Gpfunc3 != NULL)
	{
		Gpfunc3();
	}
}


void EXT0_ENABLE(void)
{
	/***INT0 ENABLE***/
	SET_BIT(GICR,INT0_ENABLE); 
}
void EXT1_ENABLE(void)
{
	/***INT1 ENABLE***/
   SET_BIT(GICR,INT1_ENABLE); 
}

void EXT2_ENABLE(void)
{
	/***INT2 ENABLE***/
   SET_BIT(GICR,INT2_ENABLE); 
   
}

void EXT0_MOOD(u8 LOC_u8SenseControl)
{
	switch (LOC_u8SenseControl)
	{
		case Falling_edge:
		CLR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;
		case Rising_edge :
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;
		case Low_level   :
		CLR_BIT(MCUCR,ISC00);
	    CLR_BIT(MCUCR,ISC01);
		break;
		case Any_change  :
		SET_BIT(MCUCR,ISC00);
		CLR_BIT(MCUCR,ISC01);
		break;
	}
} 

void EXT1_MOOD(u8 LOC_u8SenseControl)
{
	switch (LOC_u8SenseControl)   
	{        
		case Falling_edge:
		CLR_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		break;
		case Rising_edge :
		SET_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		break;
		case Low_level   :
		CLR_BIT(MCUCR,ISC10);
	    CLR_BIT(MCUCR,ISC11);
		break;
		case Any_change  :
		SET_BIT(MCUCR,ISC10);
		CLR_BIT(MCUCR,ISC11);
		break;
	}
} 


void EXT2_MOOD(u8 LOC_u8SenseControl)
{
	switch (LOC_u8SenseControl)   
	{        
		case Falling_edge:
		CLR_BIT(MCUCSR,ISC2);
		break;
		case Rising_edge :
		SET_BIT(MCUCSR,ISC2);
		break;
	}
}    
   
        