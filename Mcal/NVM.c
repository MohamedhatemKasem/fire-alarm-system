/*
 * NVM.c
 *
 * Created: 7/9/2023 11:47:40 PM
 *  Author: mohamed hatem
 */ 
#include "MemMap.h"
#include "utils.h"
#include "NVM.h"
#include "stdtypes.h"
u32	nvm_read_bit(u16 adress)
{
	u8 data;
	EEAR=adress;
	clear_bit(EECR,EEWE);
	clear_bit(EECR,EEMWE);
	set_bit(EECR,EERE);
	while(read_bit(EECR,EERE));
	data=EEDR;
	return data;
}
void nvm_read_block(u16 adress,u8 size,u8 *data)
{
	u8 i=0;
	data[i]=nvm_read_bit(adress+i);
	for(;i<size &&data[i]!=0;)
	{
		i++;
		data[i]=nvm_read_bit(adress+i);
	}
}
void NVM_write_bit(u16 adress,u8 data)
{
	EEAR=adress;
	EEDR=data;
	clear_bit(EECR,EERE);
	set_bit(EECR,EEMWE);
	set_bit(EECR,EEWE);
	while(read_bit(EECR,EEWE));
}
void NVM_write_block(u16 adress,u8 *arr_data,u8 size)
{
	u8 i=0;
	for(i=0;i<size&&arr_data[i]!=0;i++)
	{
		NVM_write_bit(adress+i,arr_data[i]);
	}
	NVM_write_bit(adress+i,0);
}