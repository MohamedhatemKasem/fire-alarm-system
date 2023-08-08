/*
 * motor_cfg.h
 *
 * Created: 6/29/2023 1:59:29 PM
 *  Author: mohamed hatem
 */ 


#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_
#include "DIO_INTERFACE.h"

#define  M1_IN1   PIND0
#define  M1_IN2   PIND1

#define  M2_IN1   PIND0
#define  M2_IN2   PIND1


#define  M3_IN1   PIND3
#define  M3_IN2   PIND4


#define  M4_IN1   PIND5
#define  M4_IN2   PIND6
typedef struct{
	DIO_Pin_type in1;
	DIO_Pin_type in2;
	
}MOTOR_Pin_type;


/*********************************	IN1   IN2*/
DIO_Pin_type MotorPinsArr[4][2]={{M1_IN1,M1_IN2},/* M1*/
{M2_IN1,M2_IN2},/* M2*/
{M3_IN1,M3_IN2},/* M3*/
{M4_IN1,M4_IN2} /* M4*/
};
MOTOR_Pin_type MotorPinsArr2[4]={{M1_IN1,M1_IN2},/* M1*/
{M2_IN1,M2_IN2},/* M2*/
{M3_IN1,M3_IN2},/* M3*/
{M4_IN1,M4_IN2} /* M4*/
};



#endif /* MOTOR_CFG_H_ */