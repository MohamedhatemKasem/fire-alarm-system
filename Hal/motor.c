#include "stdtypes.h"
#include "motor_interface.h"
#include "motor_cfg.h"
#include "DIO_INTERFACE.h"
void MOTOR_Stop(MOTOR_type m)
{
	//DIO_WritePin(MotorPinsArr[m][IN1],LOW);
	//DIO_WritePin(MotorPinsArr[m][IN2],LOW);
	//DIO_WritePin(MotorPinsArr2[m].in1,LOW);
	//DIO_WritePin(MotorPinsArr2[m].in2,LOW);
	switch(m)
	{
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		DIO_WritePin(M1_IN2,LOW);
		break;
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,LOW);
		break;
		case M3:
		DIO_WritePin(M3_IN1,LOW);
		DIO_WritePin(M3_IN2,LOW);
		break;
		case M4:
		DIO_WritePin(M4_IN1,LOW);
		DIO_WritePin(M4_IN2,LOW);
		break;
	}
}
void MOTOR_CW(MOTOR_type m)
{
	
	switch(m)
	{
	case M1:
	DIO_WritePin(M1_IN1,HIGH);
	DIO_WritePin(M1_IN2,LOW);
	break;
	case M2:
	DIO_WritePin(M2_IN1,HIGH);
	DIO_WritePin(M2_IN2,LOW);
	break;
	case M3:
	DIO_WritePin(M3_IN1,HIGH);
	DIO_WritePin(M3_IN2,LOW);
	break;
	case M4:
	DIO_WritePin(M4_IN1,HIGH);
	DIO_WritePin(M4_IN2,LOW);
	break;
}
}
void MOTOR_CCW(MOTOR_type m)
{
		//DIO_WritePin(MotorPinsArr[m][IN1],OW);
		//DIO_WritePin(MotorPinsArr[m][IN2],HIGH);
	switch(m)
	{
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		DIO_WritePin(M1_IN2,HIGH);
		break;
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,HIGH);
		break;
		case M3:
		DIO_WritePin(M3_IN1,LOW);
		DIO_WritePin(M3_IN2,HIGH);
		break;
		case M4:
		DIO_WritePin(M4_IN1,LOW);
		DIO_WritePin(M4_IN2,HIGH);
		break;
	}
}
