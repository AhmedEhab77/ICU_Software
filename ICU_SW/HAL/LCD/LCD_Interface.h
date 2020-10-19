#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_


void LCD_VidIntilaization_8bit(void);

void LCD_VidWriteCommand(u8 LOC_u8Command);

void LCD_VidWriteData(u8 LOC_u8Data);

void LCD_VidWriteString(u8 *ptr);

void LCD_VidMoveWord(u8 *LOC_u8ptr);

void LCD_VidWriteNum(u32 LOC_u32num);

void LCD_VidSetPosition(u8 LOC_u8Row,u8 LOC_u8Column);

void LCD_VidCGRAM(u8 *ptr,u8 LOC_u8AdressCGRAM,u8 LOC_u8Row,u8 LOC_u8Col,u8 LOC_u8Location);

void LCD_VidClearSpecificPosition(u8 LOC_u8Row,u8 LOC_u8StartColumn,u8 LOC_u8EndColumn);

void LCD_VidFloatNum(f32 LOC_f32num );







#endif
