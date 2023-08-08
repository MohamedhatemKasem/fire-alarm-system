/*
 * APP.c
 *
 * Created: 8/8/2023 6:59:49 AM
 *  Author: mohamed hatem
 */ 
#include "utils.h"
#include "MemMap.h"
#include "stdtypes.h"
#include "DIO_INTERFACE.h"
#include "motor_interface.h"
#include "lcd_interface.h"
#include "keypad_interface.h"
#include "ADC_INTERFAC.h"
#include "sensors_interfaces.h"
#include "filter.h"
#include "NVM.h"
#include "password.h"
void app_start(void)
{
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	FILTER_Init();
	u16 temp=0,prev_temp=0,smoke=0,flag=0,k,i=0,flagp=0,flag1=0,flag2=0,flagc=0,z=0,flags=0;
	if(nvm_read_bit(pass_store_status)==PASS_NOT_SET)
	{
		NVM_write_block(PASS_ADDRESS,default_pass,pass_size);
		NVM_write_bit(pass_store_status,PASS_SET);
	}
	pass_change();
	while(1)
	{
		FILTER_Runnable();
		temp=FILTER_GetFilterdTemp();
		k=KEYPAD_GetKey();
		if (k!='T')
		{
			if(k=='C')
			{
				LCD_Clear();
				i=reset_system();
				if(i==1)
				{
					LCD_Clear();
					LCD_WriteString("system reset susscefully");
					_delay_ms(500);
					i=0;
					flagp=0;
					flag=0;
					flag1=0;
					flag2=0;
					MOTOR_Stop(M1);
					prev_temp=0;
				}
				else
				{
					LCD_Clear();
					LCD_WriteString("wrong pass");
					_delay_ms(500);
					if(flag2==1)
					{
						prev_temp=50;
					}
					else
					{
						prev_temp=0;
					}

					
					flagp=0;
				}
			}
		}
		if (temp>=45&&temp<=50&&flag==0)
		{
			
			if (temp==50||temp==45)
			{
				flag1=0;
				flag2=0;
			}
			else if(prev_temp>49)
			{
				flag2=1;
				flag1=0;
			}
			else if(prev_temp<46)
			{
				flag1=1;
				flag2=0;
			}
		}
		if(temp<=45&&flag==0||flag1==1)
		{
			if(prev_temp!=temp)
			{
				prev_temp=temp;
				LCD_Clear();
				LCD_WriteString("FINE");
				DIO_WritePort(PC,0b00100000);
				LCD_GoTo(1,0);
				LCD_WriteString("temp is :");
				LCD_WriteNumber(temp);
				LCD_GoTo(0,0);
				
			}
		}
		else if(temp>=50||flag==1||flag2==1)
		{
			smoke=smoke_Read();
			if(smoke<75&&flag==0)
			{
				if(prev_temp!=temp)
				{
					prev_temp=temp;
					LCD_Clear();
					LCD_WriteString("heat");
					DIO_WritePort(PC,0b01000000);
					LCD_GoTo(1,0);
					LCD_WriteString("temp is :");
					LCD_WriteNumber(temp);
					LCD_GoTo(0,0);
					
				}
			}
			else
			{
				if(flag==0)
				{
					MOTOR_CW(M1);
					flag=1;
					prev_temp=0;
				}
				if((prev_temp!=temp))
				{
					prev_temp=temp;
					LCD_Clear();
					LCD_WriteString("fire");
					DIO_WritePort(PC,0b10000000);
					LCD_GoTo(1,0);
					LCD_WriteString("temp is :");
					LCD_WriteNumber(temp);
					LCD_GoTo(0,0);
				}
			}
			
		}
	}
	
}

