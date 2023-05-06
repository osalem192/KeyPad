/*
 * GPIO_DRIVER.c
 *
 *  Author: omar salem
 */ 
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "ATmega32_Regs.h"


void Dio_Set_Pin_Dir(uint8 port, uint8 pinnum, uint8 dir)
{
	switch (port)
	{
		case 'a':
		case 'A': if (dir == 1) SetBit(MYDDRA, pinnum);
				  else ClrBit(MYDDRA,pinnum); 
			break;
		case 'b':
		case 'B': if (dir == 1) SetBit(MYDDRB, pinnum);
				  else ClrBit(MYDDRB,pinnum);
			break;
		case 'c':
		case 'C': if (dir == 1) SetBit(MYDDRC, pinnum);
				  else ClrBit(MYDDRC,pinnum);
			break;
		case 'd':
		case 'D': if (dir == 1) SetBit(MYDDRD, pinnum);
				  else ClrBit(MYDDRD,pinnum);
			break;
	}
}

void Dio_Pin_Write(uint8 port, uint8 pinnum, uint8 dir)
{
		switch (port)
		{
			{case 'a':
			case 'A':  if (dir == 1) SetBit(MYPORTA, pinnum);
			else if (dir == 0) ClrBit(MYPORTA,pinnum);
			break;}
			case 'b':
			case 'B': if (dir == 1) SetBit(MYPORTB, pinnum);
			else ClrBit(MYPORTB,pinnum);
			break;
			case 'c':
			case 'C': if (dir == 1) SetBit(MYPORTC, pinnum);
			else ClrBit(MYPORTC,pinnum);
			break;
			case 'd':
			case 'D': if (dir == 1) SetBit(MYPORTD, pinnum);
			else ClrBit(MYPORTD,pinnum);
			break;
		}
}

void Dio_Pin_Toggle(uint8 port, uint8 pinnum)
{
	switch (port)
	{
		case 'a':
		case 'A': ToggleBit(MYPORTA, pinnum);
		break;
		case 'b':
		case 'B': ToggleBit(MYPORTB, pinnum);
		break;
		case 'c':
		case 'C': ToggleBit(MYPORTC, pinnum);
		break;
		case 'd':
		case 'D':ToggleBit(MYPORTD, pinnum);
		break;
	}
}

uint8 Dio_Pin_Read(uint8 port, uint8 pinnum)
{	uint8 z;
	switch (port)
	{
		case 'a':
		case 'A': z = ReadBit(MYPINA, pinnum);
		break;
		case 'b':
		case 'B': z = ReadBit(MYPINB, pinnum);
		break;
		case 'c':
		case 'C': z = ReadBit(MYPINC, pinnum);
		break;
		case 'd':
		case 'D': z = ReadBit(MYPIND, pinnum);
		break;
	}
		return z;
} 

void Dio_Set_Port_Dir(uint8 port, uint8 dir)
{
	switch (port)
	{
		case 'a':
		case 'A': if (dir == 1) MYDDRA = 0xff;
		else MYDDRA = 0;
		break;
		case 'b':
		case 'B': if (dir == 1) MYDDRB = 0xff;
		else MYDDRB = 0;
		break;
		case 'c':
		case 'C': if (dir == 1) MYDDRC = 0xff;
		else MYDDRC = 0;
		break;
		case 'd':
		case 'D': if (dir == 1) MYDDRD = 0xff;
		else MYDDRD = 0;
		break;
	}
}

void Dio_Port_Write(uint8 port, uint8 dir)
{
	switch (port)
	{
		case 'a':
		case 'A': MYPORTA = dir;
		break;
		case 'b':
		case 'B': MYPORTB = dir;
		break;
		case 'c':
		case 'C': MYPORTC = dir;
		break;
		case 'd':
		case 'D': MYPORTD = dir;
		break;
	} 
}

void Dio_Low_Nibble_Dir(uint8 port,uint8 dir)
{
	switch (port)
	{
	case 'a':
	case 'A': AND(MYDDRA,0xF0); 
			  if (dir == 1) OR(MYDDRA,0X0F);   else OR(MYDDRA,0x0);
	case 'b':
	case 'B': AND(MYDDRB,0xF0);
			  if (dir == 1) OR(MYDDRB,0X0F);   else OR(MYDDRB,0x0);
	break;
	case 'c':
	case 'C': AND(MYDDRC,0xF0);
			  if (dir == 1) OR(MYDDRC,0X0F);   else OR(MYDDRC,0x0);
	break;
	case 'd':
	case 'D': AND(MYDDRD,0xF0);
			  if (dir == 1) OR(MYDDRD,0X0F);   else OR(MYDDRD,0x0);
	break;	
	}
}

void Dio_High_Nibble_Dir(uint8 port, uint8 dir)
{
	switch (port)
	{
	case 'a':
	case 'A': AND(MYDDRA,0x0F);
			  if (dir == 1) OR(MYDDRA,0XF0);   else OR(MYDDRA,0x0);
	break;
	case 'b':
	case 'B': AND(MYDDRB,0x0F);
			  if (dir == 1) OR(MYDDRB,0XF0);   else OR(MYDDRB,0x0);
	break;
	case 'c':
	case 'C': AND(MYDDRC,0x0F);
			  if (dir == 1) OR(MYDDRC,0XF0);   else OR(MYDDRC,0x0);
	break;
	case 'd':
	case 'D': AND(MYDDRD,0x0F);
			  if (dir == 1) OR(MYDDRD,0XF0);   else OR(MYDDRD,0x0);
	break;
			
	}
}

void Dio_Low_Nibble_Write(uint8 port, uint8 val)
{	AND(val,0x0F);
	switch (port)
	{
		case 'a':
		case 'A': AND(MYPORTA,0xf0);
				  OR(MYPORTA,val);
		break;
		case 'b':
		case 'B': AND(MYPORTB,0xF0);
				  OR(MYPORTB,val);
		break;
		case 'c':
		case 'C': AND(MYPORTC,0xF0);
				  OR(MYPORTC,val);
		break;
		case 'd':
		case 'D': AND(MYPORTD,0xF0);
				  OR(MYPORTD,val);
		break;
	}
}

void Dio_High_Nibble_Write(uint8 port, uint8 val)
{	AND(val,0xF0);
	val<<4;
	switch (port)
	{
		case 'a':
		case 'A': AND(MYPORTA,0x0F);
				  OR(MYPORTA,val);
		break;
		case 'b':
		case 'B': AND(MYPORTB,0x0F);
				  OR(MYPORTB,val);
		break;
		case 'c':
		case 'C': AND(MYPORTC,0x0F);
				  OR(MYPORTC,val);
		break;
		case 'd':
		case 'D': AND(MYPORTD,0x0F);
				  OR(MYPORTD,val);
		break;
	}
}

void Dio_Internal_PullUp_en(uint8 port, uint8 pinnum)
{
	Dio_Pin_Write(port,pinnum,1);
}

void Dio_Internal_Port_PullUp_en(uint8 port)
{
	Dio_Port_Write(port,0xff);
}

void Dio_Internal_PullUP_Disable(void)
{
	ClrBit(SFIOR,2);
}
