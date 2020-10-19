#ifndef   _TMR0_CONFIG_H
#define   _TMR0_CONFIG_H


/**********************   Definitions of TCCR0   ******************************/
/*****************************************************************************/
#define  FOC0       7
#define  WGM00      6
#define  COM01      5
#define  COM00      4
#define  WGM01      3
#define  CS02       2
#define  CS01       1
#define  CS00       0

 
/**********************   Definitions of TIMSK   ******************************/
/*****************************************************************************/
#define  TOIE0      0
#define  OCIE0      1

 
/**********************   Definitions of TIFR   ******************************/
/*****************************************************************************/
#define  TOV0      0
#define  OCF0      1


/******************************************************************************/
/***************************MOODS OF TIMER0************************************/
/******************************************************************************/
#define  Normal_MOOD                      0
#define  PWM_PhaseCorrect_MOOD            1
#define  CTC_MOOD                         2
#define  FAST_PWM_MOOD                    3
/******************************************************/
#define TIMER0_Mood          FAST_PWM_MOOD
/******************************************************/



/**********************   PRESCALER MOODS   **********************************/
/*****************************************************************************/
#define  NO_CLOCK_TIMER0               0																																							
#define  NO_PRESCALER_TIMER0           1								
#define  PRESCALER_TIMER0_8            2
#define  PRESCALER_TIMER0_64           3 
#define  PRESCALER_TIMER0_256          4
#define  PRESCALER_TIMER0_1024         5
#define  EXT_CLOCK_TIMER0_FALLING      7
#define  EXT_CLOCK_TIMER0_RISING       6												
/******************************************************/
#define Prescaler_Mood          PRESCALER_TIMER0_64    
/******************************************************/





/******************************************************************************/
/***************************Definitions of TIMER0 OC0_PIN**********************/
/******************************************************************************/
#define  Normal_port_operation             0
#define  Toggle_OC0                        1
#define  Clear_OC0                         2
#define  Set_OC0                           3
#define  Reserved                          4
/******************************************************/
#define OC0_MOOD        Clear_OC0
/******************************************************/



#endif
