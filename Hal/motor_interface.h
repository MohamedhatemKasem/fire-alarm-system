/*
 * motor_interface.h
 *
 * Created: 6/29/2023 1:58:51 PM
 *  Author: mohamed hatem
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_


typedef enum{
	M1,
	M2,
	M3,
	M4
}MOTOR_type;

void MOTOR_Stop(MOTOR_type m);
void MOTOR_CW(MOTOR_type m);
void MOTOR_CCW(MOTOR_type m);

#endif /* MOTOR_INTERFACE_H_ */