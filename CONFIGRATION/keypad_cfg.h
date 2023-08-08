/*
 * keypad_cfg.h
 *
 * Created: 7/2/2023 4:14:43 PM
 *  Author: mohamed hatem
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
#define  ROWS   4
#define  COLS   4
#define FIRST_OUTPUT   PINB0
#define FIRST_INPUT    PINB4
#define NO_KEY  'T'

const u8 KeysArr[ROWS][COLS]={ {'7','8','9','/'}
,{'4','5','6','*'}
,{'1','2','3','-'}
,{'C','0','=','+'}};
#endif