#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"avr/delay.h"
#include"../../MCAL/DIO/DIO_Config.h"
#include"../../MCAL/DIO/DIO_Int.h"
#include"LCD_Config.h"






void LCD_VidIntilaization_8bit(void)
{
	_delay_ms(50);
	DIO_VidSetPortDirection(PORT_DATA ,0xFF);
	DIO_VidSetPinDirection(PORT_CONTROL,Pin_Control1,OUTPUT);
	DIO_VidSetPinDirection(PORT_CONTROL,Pin_Control2,OUTPUT);
	DIO_VidSetPinDirection(PORT_CONTROL,Pin_Control3,OUTPUT);

	LCD_VidWriteCommand(0b00111000);  //Function set
	_delay_ms(1); 
	LCD_VidWriteCommand(0b00001100);  //Diplay_On
	_delay_ms(1); 
	LCD_VidWriteCommand(0b00000001);  //Display_clear
	_delay_ms(2);
	LCD_VidWriteCommand(0b00000001);  //Entery mode set
}

void LCD_VidWriteCommand(u8 LOC_u8Command)
{
	DIO_VidSetPinValue(PORT_CONTROL,Pin_Control1,LOW); //RS=0
	DIO_VidSetPinValue(PORT_CONTROL,Pin_Control2,LOW); //Rw=0
	DIO_VidSetPortValue(PORT_DATA,LOC_u8Command); //Write command or data
	DIO_VidSetPinValue(PORT_CONTROL,Pin_Control3,HIGH);  //EN=1--rising edge
	_delay_ms(1);
	DIO_VidSetPinValue(PORT_CONTROL,Pin_Control3,LOW);  //EN=0--falling edge
	_delay_ms(1);

}
void LCD_VidWriteData(u8 LOC_u8Data)
{
	DIO_VidSetPinValue(PORT_CONTROL,Pin_Control1,HIGH); //RS=1
	DIO_VidSetPinValue(PORT_CONTROL,Pin_Control2,LOW); //Rw=0
	DIO_VidSetPortValue(PORT_DATA,LOC_u8Data); //Write command or data
	DIO_VidSetPinValue(PORT_CONTROL,Pin_Control3,HIGH); //EN=1--rising edge
	_delay_ms(1);
	DIO_VidSetPinValue(PORT_CONTROL,Pin_Control3,LOW); //EN=0--falling edge
	_delay_ms(1);
}

void LCD_VidWriteString(u8 *ptr)     

{
	u8 i;
	for(i = 0; ptr[i] != '\0'; i++)
	{
		LCD_VidWriteData(ptr[i]);
	}
}
void LCD_VidMoveWord(u8 *ptr)
{

	 LCD_VidWriteString(ptr);
	_delay_ms(400);
	for(u8 j=40;j>0;j--)
	{
		LCD_VidWriteCommand(0b00000001);  //Display_clear
		for(u8 i=40;i>=j;i--)
		{
			LCD_VidWriteCommand(0b00011100);//Shift Display
		}
		 LCD_VidWriteString(ptr);
		_delay_ms(400);
	}
}


		void LCD_VidFloatNum(f32 totalnum )//3.48
	{		      
		u32 num_after=0;
		u32 num_before=totalnum;//num1 before decimal point //3
		totalnum= totalnum-num_before;//num2 after decimal point//0.48
		while(totalnum != (u32)totalnum)//48.0007827 != 48
		{
			totalnum =totalnum *10; //48.000000   	
		}
		num_after= totalnum; //48 
		LCD_VidWriteNum(num_before);//num1 before decimal point
		LCD_VidWriteString(".");//decimal point
		LCD_VidWriteNum(num_after);//num2 before decimal point
	}
	
	
	void LCD_VidWriteNum(u32 LOC_u32num)
	{
		u32 revrese=0;
		u8 y;
		u8 counter=0;
		if(LOC_u32num==0)
		{
			LCD_VidWriteData(48);
		}
		else
	{
		while(LOC_u32num>0)
		{
			revrese=(revrese*10)+(LOC_u32num)%10;
			if(revrese==0)
			{
				 y=0;
				 counter++;
			}
			LOC_u32num=LOC_u32num/10;
		}
		while(revrese>0)
		{
			u8 res=revrese%10;
			LCD_VidWriteData(res+48);
			revrese=revrese/10;
		}
		if(y==0)
		{
			for(u8 i=0;i<counter;i++)
			{
		LCD_VidWriteData(48);
			}
		}
	}	
		
	}

	void LCD_VidSetPosition(u8 LOC_u8Row,u8 LOC_u8Column)
	{
		if(LOC_u8Row==0)
		{
			LCD_VidWriteCommand(128+LOC_u8Column);

		}
		else if(LOC_u8Row==1)
				{
					LCD_VidWriteCommand(128+64+LOC_u8Column);
				}
	}
	

	void LCD_VidCGRAM(u8 *ptr,u8 LOC_u8AdressCGRAM,u8 LOC_u8Row,u8 LOC_u8Col,u8 LOC_u8Location)
	{
		LCD_VidWriteCommand(64+LOC_u8AdressCGRAM);
		for(u8 i=0;i<8;i++)
		{
			LCD_VidWriteData(ptr[i]);
		}
		LCD_VidSetPosition(LOC_u8Row,LOC_u8Col);
		LCD_VidWriteData(LOC_u8Location);
	}
	
	
	
	void LCD_VidClearSpecificPosition(u8 LOC_u8Row,u8 LOC_u8StartColumn,u8 LOC_u8EndColumn)
	{
		u8 i;
		for( i=LOC_u8StartColumn;i<=LOC_u8EndColumn;i++)
		{
			LCD_VidSetPosition(LOC_u8Row,i);
			LCD_VidWriteData(' ');
		}
	}
	
