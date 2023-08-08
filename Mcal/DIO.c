
#include "stdtypes.h"
#include "MemMAP.h"
#include "utils.h"
#include "DIO-PRIVATE.h"
#include "dio_cfg.h"
#include "DIO_INTERFACE.h"
void DIO_InitPin2(DIO_Port_type port,u8 pin_num,DIO_PinStatus_type status)
{
	switch (status)
	{
		case OUTPUT:
		switch (port)
		{
			case PA:
			set_bit(DDRA,pin_num);
			clear_bit(PORTA,pin_num);
			break;
			case PB:
			set_bit(DDRB,pin_num);
			clear_bit(PORTB,pin_num);
			break;
			case PC:
			set_bit(DDRC,pin_num);
			clear_bit(PORTC,pin_num);
			break;
			case PD:
			set_bit(DDRD,pin_num);
			clear_bit(PORTD,pin_num);
			break;
		}
		break;
		case INFREE:
		switch (port)
		{
			case PA:
			clear_bit(DDRA,pin_num);
			clear_bit(PORTA,pin_num);
			break;
			case PB:
			clear_bit(DDRB,pin_num);
			clear_bit(PORTB,pin_num);
			break;
			case PC:
			clear_bit(DDRC,pin_num);
			clear_bit(PORTC,pin_num);
			break;
			case PD:
			clear_bit(DDRD,pin_num);
			clear_bit(PORTD,pin_num);
			break;
		}
		break;
		case INPULL:
		switch (port)
		{
			case PA:
			clear_bit(DDRA,pin_num);
			set_bit(PORTA,pin_num);
			break;
			case PB:
			clear_bit(DDRB,pin_num);
			set_bit(PORTB,pin_num);
			break;
			case PC:
			clear_bit(DDRC,pin_num);
			set_bit(PORTC,pin_num);
			break;
			case PD:
			clear_bit(DDRD,pin_num);
			set_bit(PORTD,pin_num);
			break;
		}
		break;
	}
}
void DIO_InitPin(DIO_Pin_type pin ,DIO_PinStatus_type status)
{
	u8 pin_num =pin%8;
	DIO_Port_type port=pin/8 ;
	switch (status)
	{
		case OUTPUT:
		switch (port)
		{
			case PA:
			set_bit(DDRA,pin_num);
			clear_bit(PORTA,pin_num);
			break;
			case PB:
			set_bit(DDRB,pin_num);
			clear_bit(PORTB,pin_num);
			break;
			case PC:
			set_bit(DDRC,pin_num);
			clear_bit(PORTC,pin_num);
			break;
			case PD:
			set_bit(DDRD,pin_num);
			clear_bit(PORTD,pin_num);
			break;
		}
		break;
		case INFREE:
		switch (port)
		{
			case PA:
			clear_bit(DDRA,pin_num);
			clear_bit(PORTA,pin_num);
			break;
			case PB:
			clear_bit(DDRB,pin_num);
			clear_bit(PORTB,pin_num);
			break;
			case PC:
			clear_bit(DDRC,pin_num);
			clear_bit(PORTC,pin_num);
			break;
			case PD:
			clear_bit(DDRD,pin_num);
			clear_bit(PORTD,pin_num);
			break;
		}
		break;
		case INPULL:
		switch (port)
		{
			case PA:
			clear_bit(DDRA,pin_num);
			set_bit(PORTA,pin_num);
			break;
			case PB:
			clear_bit(DDRB,pin_num);
			set_bit(PORTB,pin_num);
			break;
			case PC:
			clear_bit(DDRC,pin_num);
			set_bit(PORTC,pin_num);
			break;
			case PD:
			clear_bit(DDRD,pin_num);
			set_bit(PORTD,pin_num);
			break;
		}
		break;
	}
}
void DIO_WritePin(DIO_Pin_type pin ,DIO_PinVoltage_type volt)
{
	u8 pin_num =pin%8;
	DIO_Port_type port=pin/8 ;
	if(volt==HIGH)
	{
		switch (port)
		{
			case PA:
			set_bit(PORTA,pin_num);
			break;
			case PB:
			set_bit(PORTB,pin_num);
			break;
			case PC:
			set_bit(PORTC,pin_num);
			break;
			case PD:
			set_bit(PORTD,pin_num);
			break;
		}
		
	}
		else 
		{
			switch (port)
			{
				case PA:
				clear_bit(PORTA,pin_num);
				break;
				case PB:
				clear_bit(PORTB,pin_num);
				break;
				case PC:
				clear_bit(PORTC,pin_num);
				break;
				case PD:
				clear_bit(PORTD,pin_num);
				break;
			}
			
		}
}
DIO_PinVoltage_type DIO_readPin(DIO_Pin_type pin) 
{
	u8 pin_num =pin%8;
	DIO_Port_type port=pin/8 ;
	DIO_PinVoltage_type x=LOW;
	switch (port)
	{
		case PA:
		x=read_bit(PINA,pin_num);
		break;
		case PB:
		x=read_bit(PINB,pin_num);
		break;
		case PC:
		x=read_bit(PINC,pin_num);
		break;
		case PD:
		x=read_bit(PIND,pin_num);
		break;
	}
	return x;
	
}
void DIO_TogglePin(DIO_Pin_type pin)
{
	u8 pin_num =pin%8;
	DIO_Port_type port=pin/8 ;
	switch (port)
	{
		case PA:
		toogle_bit(PORTA,pin_num);
		break;
		case PB:
		toogle_bit(PORTB,pin_num);
		break;
		case PC:
		toogle_bit(PORTC,pin_num);
		break;
		case PD:
		toogle_bit(PORTD,pin_num);
		break;
	}
	
	
}
void DIO_WritePort(DIO_Port_type port,u8 data)
{
	switch(port)
	{
		case PA:
		PORTA=data;
		break;
		case PB:
		PORTB=data;
		break;
		case PC:
		PORTC=data;
		break;
		case PD:
		PORTD=data;
		break;
	}
}
u8 DIO_ReadPort(DIO_Port_type port)
{
	u8 data=0 ;
	
	switch(port)
	{
		case PA:
		data=PINA;
		break;
		case PB:
		data=PINB;
		break;
		case PC:
		data=PINC;
		break;
		case PD:
		data=PIND;
		break;
	}
	return data;
}
void DIO_togglePort(DIO_Port_type port)
{
	switch(port)
	{
		case PA:
		PORTA=~PORTA;
		break;
		case PB:
		PORTB=~PORTB;
		break;
		case PC:
		PORTC=~PORTC;
		break;
		case PD:
		PORTD=~PORTD;;
		break;
	}
}
void DIO_Init(void)
{ DIO_Pin_type i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
	DIO_InitPin(i,DIO_PinsStatusArr[i]);
}
}