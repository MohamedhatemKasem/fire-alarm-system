/*
 * lcd_interface.h
 *
 * Created: 6/30/2023 1:16:40 AM
 *  Author: mohamed hatem
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_Init(void);
void WriteIns(u8 ins);
void WriteData(u8 data);
void LCD_WriteChar(u8 ch);
void LCD_GoTo(u8 line,u8 cell);
void LCD_WriteString(c8*str);
void LCD_WriteNumber(s32 num);
void LCD_Clear(void);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);
void LCD_ClearPosition(u8 line ,u8 cell,u8 NoCells);

#endif /* LCD_INTERFACE_H_ */