/*
 * LCD_program.c
 *
 *  Created on: Jan 4, 2022
 *      Author: hanaashour
 */
#include <util/delay.h>

#include "../include/LIB/bit.h"
#include "../include/LIB/types.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/DIO/DIO_private.h"
#include "../include/MCAL/DIO/DIO_configuration.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../include/HAL/LCD/LCD_configuration.h"
#include <stdlib.h>



void Private_voidSendCommand(u8 cmd)
{
//rs=0, register select, 0 will select command selector
//r/w=0, read/write, 0 will read message
//e=0, enable, 0 will reads data, enable is high
// write instructions on pins.
//read and display the data.
MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8_LOW);
MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8_LOW);
MDIO_voidSetPortValue(LCD_DATA_PORT, cmd);
MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH);
_delay_ms(2);
MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_LOW);
}

void HLCD_voidInit(void){
	_delay_ms(30);
	Private_voidSendCommand(LCD_u8_FUNCTION_SET);
	_delay_ms(2);
	Private_voidSendCommand(LCD_u8_DISPLAY_CONTROL);
	_delay_ms(1);
	Private_voidSendCommand(LCD_u8_CLEAR);
	_delay_ms(2);
	Private_voidSendCommand(LCD_u8_ENTRY);

}

void HLCD_voidSendData(u8 copy_u8char)
{
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8_HIGH);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8_LOW);
	MDIO_voidSetPortValue(LCD_DATA_PORT, copy_u8char);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_LOW);
}
void HLCD_voidSendString(u8*copy_Pu8String)
{
while(*copy_Pu8String>0)
{
	HLCD_voidSendData(*copy_Pu8String++);
}
}

void HLCD_voidClearDisplay(void)
{
	Private_voidSendCommand(LCD_u8_CLEAR);
_delay_ms(2);
}

void HLCD_voidGoToPos(u8 copy_u8row,u8 copy_u8col)
{
	switch (copy_u8row)
		{
		 case LCD_u8_LINE1: Private_voidSendCommand(LCD_u8_ROW1_ADDRESS + copy_u8col); break;
		 case LCD_u8_LINE2: Private_voidSendCommand(LCD_u8_ROW2_ADDRESS + copy_u8col); break;
		}
		/* wait for more 39 usec */
		_delay_ms(1);
}

void HLCD_voidSendSpecialCharacter(u8*copy_p8CharArr,u8 copy_u8PatternNum, u8 copy_u8LineNum,u8 copy_ColNum)
{
	u8 local_u8CGRAMAddress, local_u8Counter;
		/* Calculate CGRAM Address = Pattern Number * 8 */
		local_u8CGRAMAddress = copy_u8PatternNum * 8;
		SET(local_u8CGRAMAddress,6);
		/* Send Command to set CGRAM Address */
		Private_voidSendCommand(local_u8CGRAMAddress);

		for (local_u8Counter=0; local_u8Counter < 8; local_u8Counter++)
		{
			/* Send byte from character array */
			HLCD_voidSendData(copy_p8CharArr[local_u8Counter]);
		}

		/* Send Command to set DDRAM Address */
		HLCD_voidGoToPos(copy_u8LineNum,copy_ColNum);
		/* Display pattern from CGRAM */
		HLCD_voidSendData(copy_u8PatternNum);
}

void HLCD_displayNumber(s32 copy_s32Number)
{
	s32 temp=1;
	if(copy_s32Number==0)
	{
		HLCD_voidSendData('0');
	}
	if(copy_s32Number<0)
	{
		HLCD_voidSendData('-');
		copy_s32Number*=-1;
	}
	while(copy_s32Number!=0)
	{
	temp = ((temp*10)+(copy_s32Number%10));
	copy_s32Number/=10;
	}
while(temp!=1)
{
	HLCD_voidSendData((temp%10)+48);
	temp = temp/10;
}
}

