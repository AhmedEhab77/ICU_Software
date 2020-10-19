#ifndef   _TMR1_INT_H
#define   _TMR1_INT_H


void TMR1_VidInit(void);
void TMR1_VidOverFlowInterruptEnable(void);
void TMR1_VidOutputCompareMatchInterruptEnable_A(void);
void TMR1_VidOutputCompareMatchInterruptEnable_B(void);
void TMR1_VidInputCaptureInterruptEnable(void);
void TMR1_VidSetCallBackForCTC(void (*Lpfunc)(void));
void TMR1_VidSetCallBackForOVF(void (*Lpfunc)(void));
void TMR1_VidPreLoadingTheCounter(u8 LOC_u8PreLoading_Value);
void TMR1_VidCompareMatchValue_A(u8 LOC_u8CompareMatchValue);
void TMR1_VidCompareMatchValue_B(u8 LOC_u8CompareMatchValue);
void TMR1_VidSetDutyCycle(u16 LOC_u8TonValue);
void TMR1_VidSetICRRegister(u8 LOC_u8ICR_Value);
void TMR1_VidSetCallBackForCaptureUnit(void (*Lpfunc)(void));




#endif