/*
 * password.h
 *
 * Created: 8/8/2023 7:00:45 AM
 *  Author: mohamed hatem
 */ 


#ifndef PASSWORD_H_
#define PASSWORD_H_
#define pass_store_status 0X50 
#define PASS_ADDRESS 0X00
#define pass_size 10
#define PASS_NOT_SET    0xFF
#define PASS_SET        0x01
#define PASSWORD_SYMBOL  '*'
#define default_pass "12345678"
u8 Pass_len(u8*x);
extern u8 pass[pass_size];
extern u8 check_arr[pass_size];
void write_pass(void);
u8 Pass_compare (u8*x,u8*y);
void pass_change(void);
void set_pass_(void);
u8 reset_system(void);

#endif /* PASSWORD_H_ */