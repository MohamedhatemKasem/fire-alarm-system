/*
 * ADC_INTERFAC.h
 *
 * Created: 7/3/2023 5:08:15 PM
 *  Author: mohamed hatem
 */ 


#ifndef ADC_INTERFAC_H_
#define ADC_INTERFAC_H_

typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256V
}ADC_VoltRef_type;
typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
}ADC_Prescaler_type;
typedef enum
{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
	
}ADC_Channel_type;
typedef enum
{
	ADLAR0,
	ADLAR1,
	
	
}ADLAR_C;



void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler);
u16 ADC_Read(ADC_Channel_type CH,ADLAR_C AL);
u16 ADC_VoltRead(ADC_Channel_type CH);
void ADC_start_conversion(ADC_Channel_type CH);
u16 ADC_get_read(void);
u16 ADC_get_read_periodic(u16*pdata);
void adc_interrupt_Enable(void);
void ADC_set_callback(void(*local)(void));
void ADC_start_conversion_2(ADC_Channel_type CH);
#endif /* ADC_INTERFAC_H_ */