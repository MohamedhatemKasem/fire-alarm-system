/*
 * lcd_cfg.h
 *
 * Created: 6/30/2023 1:17:19 AM
 *  Author: mohamed hatem
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#define  _8_BIT  0
#define  _4_BIT  1

/***********_8_BIT or _4_BIT *********************/
#define  LCD_MODE  _4_BIT

#define  RS    PINA4
#define  EN    PINA5
#define D4  PINA0
#define D5  PINA1
#define D6  PINA2
#define D7  PINA3
#define  LCD_PORT  PA


#endif /* LCD_CFG_H_ */