/*
 * filter.h
 *
 * Created: 7/7/2023 10:01:54 PM
 *  Author: mohamed hatem
 */ 


#ifndef FILTER_H_
#define FILTER_H_


extern  u16 arr_filter[10];
extern  u16 filterd_temp;
extern  u16  un_filterd_temp;
void FILTER_Init(void);
void FILTER_Runnable(void);
u16 FILTER_GetFilterdTemp(void);
u16 FILTER_GetUnFilterdTemp(void);
#endif /* FILTER_H_ */