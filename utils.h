/*
 * utils.h
 *
 * Created: 6/28/2023 6:11:25 PM
 *  Author: mohamed hatem
 */ 


#ifndef UTILS_H_
#define UTILS_H_
#define set_bit(reg,bit)    (reg=reg|(1<<bit))
#define SET_BIT(reg,bit)    (reg=reg|(1<<bit))
#define clear_bit(reg,bit)  (reg=reg&~(1<<bit))
#define CLR_BIT(reg,bit)    (reg=reg&~(1<<bit))
#define read_bit(reg,bit)    ((reg>>bit)&1)
#define  READ_BIT(reg,bit)  ((reg>>bit)&1)
#define  toogle_bit(reg,bit)   (reg=reg^(1<<bit))
#define  F_CPU   8000000
#include <util/delay.h>






#endif /* UTILS_H_ */