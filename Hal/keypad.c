/*
 * keypad.c
 *
 * Created: 7/2/2023 4:14:22 PM
 *  Author: mohamed hatem
 */ 
#include "stdtypes.h"
#include "DIO_INTERFACE.h"
#include "keypad_interface.h"
#include "keypad_cfg.h"
void KEYPAD_Init(void)
{
	u8 i=0;
	for(i=0;i<ROWS;i++)
	{
		DIO_WritePin(FIRST_OUTPUT+i,HIGH);
	}
}
u8 KEYPAD_GetKey(void)
{
	u8 r=0,c=0,key=NO_KEY;
	for(r=0;r<ROWS;r++)
	{
		DIO_WritePin(FIRST_OUTPUT+r,LOW);
		for(c=0;c<COLS;c++)
		{
			if((DIO_readPin(FIRST_INPUT+c))==LOW)
			{
				key=KeysArr[r][c];
				while(DIO_readPin(FIRST_INPUT+c)==LOW);
				{
					
				}
			}
			}
			DIO_WritePin(FIRST_OUTPUT+r,HIGH);
		}
	return key;
	
}
