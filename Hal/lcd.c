/*
 * lcd.c
 *
 * Created: 6/30/2023 1:15:54 AM
 *  Author: mohamed hatem
 */ 
#include "StdTypes.h"
#include "DIO_INTERFACE.h"
#include "LCD_Cfg.h"
#include "LCD_Interface.h"
#include "UTILS.h"
#define  F_CPU   8000000
#include <util/delay.h>
#if LCD_MODE ==_8_BIT
 void WriteIns(u8 ins)
 {
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
 }
void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0X38);
	WriteIns(0X0c);
	WriteIns(0X01);
	_delay_ms(1);
	WriteIns(0X06);
	
	
}
void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
#else
void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
void LCD_Init(void)
{
_delay_ms(50);
WriteIns(0X02);
WriteIns(0X28);
WriteIns(0X0c);
WriteIns(0X01);
_delay_ms(1);
WriteIns(0X06);
}
void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
#endif

void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}
void LCD_GoTo(u8 line,u8 cell)
{
	if (line==0)
	{
		WriteIns(0x80+cell);
	}
	else
	{
		WriteIns(0xc0+cell);
	}
}
void LCD_WriteString(c8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}
void LCD_WriteNumber(s32 num)
{
	c8 str[20];
	u8 i=0;
	s8 j;
	if (num==0)
	{
		LCD_WriteChar('0');
		return ;
	}
	if (num<0)
	{
		LCD_WriteChar('-');
		num=num*(-1);
	}
	
	while(num)
	{
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	for (j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	//LCD_WriteString(str);
}
void LCD_Clear(void)
{
	WriteIns(0x01);
	_delay_ms(1);
}
void LCD_WriteBinary(u8 num)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
	LCD_WriteChar(read_bit(num,i)+'0');
	//LCD_WriteNumber(read_bit(num,i));
	}
}
void LCD_WriteHex(u8 num)
{
	u8 HN=num>>4;
	u8 LN=num&0x0f;
	if (HN<10)
	{
		LCD_WriteChar(HN+'0');
	}
	else
	{
		LCD_WriteChar(HN-10+'A');
	}
	if (LN<10)
	{
		LCD_WriteChar(LN+'0');
	}
	else
	{
		LCD_WriteChar(LN-10+'A');
	}
}
void LCD_ClearPosition(u8 line ,u8 cell,u8 NoCells)
{
	u8 i=0;
	LCD_GoTo(line,cell);
	for(i=0;i<NoCells;i++)
	
	{
		LCD_WriteChar(' ');
	}
	LCD_GoTo(0,0);
}