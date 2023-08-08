/*
 * filter.c
 *
 * Created: 7/7/2023 10:02:33 PM
 *  Author: mohamed hatem
 */ 
#include "stdtypes.h"
#include "sensors_interfaces.h"
u16 arr_filter[10];
u16 filterd_temp;
u16  un_filterd_temp;
void FILTER_Init(void)
{
	s16 i=TEMP_Read();
	un_filterd_temp=i;
	u8 j=0;
	for(j=0;j<10;j++)
	{
		arr_filter[j]=i;
	}
}

/* not more than 250 us*/
void FILTER_Runnable(void)
{
	static u8 i=0;
	u16 tempsum=0;
	arr_filter[i]=TEMP_Read();
	un_filterd_temp=arr_filter[i];
	i++;
	if(i==10)
	{
		i=0;
	}
	for(u8 j=0;j<10;j++)
	{
		tempsum=tempsum+arr_filter[j];
	}
	filterd_temp=(tempsum/10);
}

u16 FILTER_GetFilterdTemp(void)
{
	return filterd_temp;
}

u16 FILTER_GetUnFilterdTemp(void)
{
	return un_filterd_temp;
}

