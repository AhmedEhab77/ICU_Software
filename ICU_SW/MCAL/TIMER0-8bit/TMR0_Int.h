#ifndef   _TMR0_INT_H
#define   _TMR0_INT_H



void TMR0_VidInit(void);
void TMR0_VidOverFlowInterruptEnable(void);
void TMR0_VidOutputCompareMatchInterruptEnable(void);
void TMR0_VidSetCallBackForCTC(void (*Lpfunc)(void));
void TMR0_VidSetCallBackForOVF(void (*Lpfunc)(void));
void TMR0_VidPreLoadingTheCounter(u8 LOC_u8PreLoading_Value);
void TMR0_VidCompareMatchValue(u8 LOC_u8CompareMatchValue);
void TMR0_VidSetDutyCycle(u8 LOC_u8DutyPercentage);


#endif