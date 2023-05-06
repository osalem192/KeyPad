/*
 * KeyPad.c
 *
 * Created: 3/18/2023 11:51:32 AM
 *  Author: osale
 */ 

#include "GPIO_DRIVER.h"
#include "STD_TYPE.h"

void KeyPad_Init(uint8 port)
{
	Dio_Low_Nibble_Dir(port,1);
	Dio_High_Nibble_Dir(port,0);
	Dio_High_Nibble_Write(port, 0xff);
}

uint8 KeyPad_Read(uint8 port)
{	uint8 row, coloumn , z, value;
	
	uint8 arr[4][4] = {{'7','8','9','/'}, {'4','5','6','*'}, {'1','2','3','-'}, {'a','0','=','+'} };
	value = 0xff;
	
	for (row = 0; row < 4; row ++)
	{
		Dio_Low_Nibble_Write(port, 0xff);
		Dio_Pin_Write(port, row, 0);
		for (coloumn = 0; coloumn < 4; coloumn ++)
		{
			z = Dio_Pin_Read(port, coloumn + 4);
			if (z == 0)
			{
				value = arr[row][coloumn];
				break;
			}
		if (z == 0) break;	
		}
	}
	return value;
}
