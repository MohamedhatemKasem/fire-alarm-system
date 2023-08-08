/*
 * Sensors.c
 *
 * Created: 7/4/2023 4:23:55 AM
 *  Author: mohamed hatem
 */ 
#include "stdtypes.h"
#include "ADC_INTERFAC.h"
#include "MemMap.h"
#include "sensors_interfaces.h"
#include "adc_cfg.h"
s16 TEMP_Read(void)
{
	s16 temp;
	temp=ADC_VoltRead(LM35_CH);
	temp=(temp+5)/10;
	return temp;
}
s16 smoke_Read(void)
{
	s16 smoke;
	smoke=ADC_VoltRead(smoke_CH);
	return (smoke+5)/10;
}
u16 preasure_Read(void)
{
u16 pressure=((((u32)1000*ADC_Read(CH_7,ADLAR0))/921)-(((u32)55*1000)/921))+150;
return pressure;
}