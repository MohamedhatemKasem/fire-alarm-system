/*
 * NVM.h
 *
 * Created: 7/9/2023 11:47:54 PM
 *  Author: mohamed hatem
 */ 

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#ifndef NVM_H_
#define NVM_H_

u32	nvm_read_bit(u16 adress);
void nvm_read_block(u16 adress,u8 size,u8 *data);
void NVM_write_bit(u16 adress,u8 data);
void NVM_write_block(u16 adress,u8 *arr_data,u8 size);
#endif /* NVM_H_ */