#ifndef   _TMR1_CONFIG_H
#define   _TMR1_CONFIG_H

       
/**********************   Definitions of TCCR1A   ******************************/
/*****************************************************************************/
#define  COM1A1       7
#define  COM1A0       6
#define  COM1B1       5
#define  COM1B0       4
#define  FOC1A        3
#define  FOC1B        2
#define  WGM11        1
#define  WGM10        0
     
/**********************   Definitions of TCCR1B   ******************************/
/*****************************************************************************/
#define  ICNC1       7
#define  ICES1      6
#define  WGM13      4
#define  WGM12      3
#define  CS12       2
#define  CS11       1
#define  CS10       0

/**********************   Definitions of TIMSK   ******************************/
/*****************************************************************************/
#define  TOIE1       2
#define  OCIE1B      3
#define  OCIE1A      4
#define  TICIE1      5

 

/******************************************************************************/
/***************************MOODS OF TIMER1************************************/
/******************************************************************************/
#define  Normal_MOOD                      0
#define  CTC_MOOD_OCR1A                   1
#define  FAST_PWM_MOOD_ICR                2
/******************************************************/
#define TIMER1_Mood          Normal_MOOD    
/******************************************************/



/**********************   PRESCALER MOODS   **********************************/
/*****************************************************************************/
#define  NO_CLOCK_TIMER1               0																																							
#define  NO_PRESCALER_TIMER1           1								
#define  PRESCALER_TIMER1_8            2
#define  PRESCALER_TIMER1_64           3 
#define  PRESCALER_TIMER1_256          4
#define  PRESCALER_TIMER1_1024         5
#define  EXT_CLOCK_TIMER1_FALLING      7
#define  EXT_CLOCK_TIMER1_RISING       6												
/******************************************************/
#define Prescaler_Mood_TIMER1          PRESCALER_TIMER1_64    
/******************************************************/


/******************************************************************************/
/***************************Definitions of TIMER1 OC1B_PIN**********************/
/******************************************************************************/
#define  Normal_port_operation              0
#define  Toggle_OC1B                        1
#define  Clear_OC1B                         2
#define  Set_OC1B                           3
#define  Reserved                           4
/******************************************************/
#define OC1B_CHANNEL         Normal_port_operation
/******************************************************/

/******************************************************************************/
/***************************Definitions of TIMER1 OC1A_PIN**********************/
/******************************************************************************/
#define  Normal_port_operation              0
#define  Toggle_OC1A                        1
#define  Clear_OC1A                         2
#define  Set_OC1A                           3
#define  Reserved                           4
/******************************************************/
#define OC1A_CHANNEL        Normal_port_operation
/******************************************************/

/***************************************************/
#define    OC_CHANNEL     OC1A_CHANNEL
/***************************************************/


#endif