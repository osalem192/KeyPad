/*
 * GPIO_DRIVER.h
 *
 *  Author: omar salem
 */ 

#include "STD_TYPE.h"
#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_


void  Dio_Set_Pin_Dir(uint8 port, uint8 pinnum, uint8 dir);
void  Dio_Pin_Write(uint8 port, uint8 pinnum, uint8 dir);
void  Dio_Pin_Toggle(uint8 port, uint8 pinnum);
uint8 Dio_Pin_Read(uint8 port, uint8 pinnum);
void  Dio_Set_Port_Dir(uint8 port, uint8 dir);
void  Dio_Port_Write(uint8 port, uint8 dir);
void  Dio_Low_Nibble_Dir(uint8 port,uint8 dir);
void  Dio_High_Nibble_Dir(uint8 port, uint8 dir);
void  Dio_Low_Nibble_Write(uint8 port, uint8 val);
void  Dio_High_Nibble_Write(uint8 port, uint8 val);
void  Dio_Internal_PullUp_en(uint8 port, uint8 pinnum);
void  Dio_Internal_Port_PullUp_en(uint8 port);
void  Dio_Internal_PullUP_Disable(void);


#endif /* GPIO_DRIVER_H_ */