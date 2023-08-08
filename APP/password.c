/*
 * password.c
 *
 * Created: 8/8/2023 7:00:34 AM
 *  Author: mohamed hatem
 */ 
#include "stdtypes.h"
#include "password.h"
#include "utils.h"
u8 pass[pass_size];
u8 check_arr[pass_size]={0};
u8 Pass_len(u8*x)
{
	int i;
	for(i=0;x[i]!=0;i++)
	{

	}
	return i;
}
void write_pass(void)
{
	u8 i=0,k=0;
	LCD_WriteString("insert pass");
	LCD_GoTo(1,0);
	while(k!='=')
	{
		k=KEYPAD_GetKey();
		if (k!='T')
		{
			if(k>='0'&&k<='9')
			{
				pass[i]=k;
				i++;
				LCD_WriteChar(PASSWORD_SYMBOL);
			}
			if(k=='=')
			{
				LCD_Clear();
				pass[i]=0;
				nvm_read_block(PASS_ADDRESS,pass_size,check_arr);
			}
		}
	}
}

u8 Pass_compare (u8*x,u8*y)
{
	u16 i,j;
	i=Pass_len(x);
	j=Pass_len(y);
	if(i!=j)
	{
		return 0;
	}
	for(i=0;x[i]!=0&&y[i]!=0;i++)
	{
		if(x[i]!=y[i])
		{
			return 0;
		}

	}
	return 1;

}
void set_pass_(void)
{
	u8 i=0,k=0;
	LCD_WriteString("Set pass");//printing the set admin password menu
	_delay_ms(300);
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteString("max pass is9 num");
	LCD_GoTo(1,0);
	/********************************* setting Admin password **********************************************/
	//the array where it stored the password
	while(k!='=')
	{
		k=KEYPAD_GetKey();
		if (k!='T')
		{
			if(k>='0'&&k<='9')
			{
				pass[i]=k;
				i++;
				LCD_WriteChar(PASSWORD_SYMBOL);
			}
			if(k=='=')
			{
				pass[i]=0;
				NVM_write_block(PASS_ADDRESS,pass,pass_size);
				LCD_WriteString("Pass Saved");
				NVM_write_bit(pass_store_status,PASS_SET);//write the status of pass as it is set
				_delay_ms(500);//Halt the system for the given time in (ms)
				LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row

			}
		}
	}
}
void pass_change(void)
{
	u8 i=0,k=0;
	LCD_WriteString("1 change pass");
	LCD_GoTo(1,0);
	LCD_WriteString("2 continue");
	while(k<'1'||k>'2')
	{
		k=KEYPAD_GetKey();
	}
	LCD_Clear();
	if(k=='1')
	{
		write_pass();
		if(Pass_compare(check_arr,pass))
		{
			set_pass_();
		}
		else
		{
			LCD_WriteString("failed to change");
			_delay_ms(100);
		}
	}

}
u8 reset_system(void)
{
	write_pass();
	if(Pass_compare(check_arr,pass))
	{
		return 1;
	}
	return 0;
	
	
}