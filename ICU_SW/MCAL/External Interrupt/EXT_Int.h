#ifndef   _EXT_INT_H
#define   _EXT_INT_H


void EXT0_ENABLE(void);
void EXT1_ENABLE(void);
void EXT2_ENABLE(void);
void INT0_VidSetCallBack(void (*Lpfunc)(void));
void INT1_VidSetCallBack(void (*Lpfunc)(void));
void INT2_VidSetCallBack(void (*Lpfunc)(void));
void EXT0_MOOD(u8 LOC_u8SenseControl);
void EXT1_MOOD(u8 LOC_u8SenseControl);
void EXT2_MOOD(u8 LOC_u8SenseControl);




#endif