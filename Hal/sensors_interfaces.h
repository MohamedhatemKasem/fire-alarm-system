/*
 * sensors_interfaces.h
 *
 * Created: 7/4/2023 4:24:16 AM
 *  Author: mohamed hatem
 */ 


#ifndef SENSORS_INTERFACES_H_
#define SENSORS_INTERFACES_H_
#define  LM35_CH  CH_6
#define  smoke_CH  CH_7
#define  MPX_4115  CH_7
s16 TEMP_Read(void);
s16 smoke_Read(void);
u16 preasure_Read(void);
#endif /* SENSORS_INTERFACES_H_ */