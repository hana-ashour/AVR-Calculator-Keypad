/*
 * KEYPAD_program.c
 *
 *  Created on: Jan 9, 2022
 *      Author: hanaa
 */

#include <util/delay.h>

#include "../include/LIB/bit.h"
#include "../include/LIB/types.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/DIO/DIO_private.h"
#include "../include/MCAL/DIO/DIO_configuration.h"

#include "../include/HAL/KEYPAD/KEYPAD_interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_private.h"
#include "../include/HAL/KEYPAD/KEYPAD_configuration.h"
#include <stdlib.h>
#include <math.h>

u8 KEYPAD_Au8KEYS [KEYPAD_u8ROW_NUM][KEYPAD_u8COL_NUM] = KEYPAD_Au8_KEYS;
u8 KEYPAD_Au8RowsPins [KEYPAD_u8ROW_NUM] = KEYPAD_Au8Rows;
u8 KEYPAD_Au8ColsPins [KEYPAD_u8COL_NUM] =  KEYPAD_Au8Cols;

u8 KEYPAD_u8_GetKey(void)
{
	u8 local_u8_Row_Counter,local_u8_Col_Counter,local_PIN_VALUE,local_KEY_VALUE =KEYPAD_u8_KEY_NOT_PRESSED,
			local_u8Flag = KEYPAD_u8_FLAG_DOWN;

	for(local_u8_Row_Counter=0;local_u8_Row_Counter<KEYPAD_u8ROW_NUM;local_u8_Row_Counter++)
	{
		MDIO_voidSetPinValue(KEYPAD_u8_PORT, KEYPAD_Au8RowsPins[local_u8_Row_Counter], DIO_u8_LOW);

		for(local_u8_Col_Counter=0;local_u8_Col_Counter<KEYPAD_u8COL_NUM;local_u8_Col_Counter++)
		{
			local_PIN_VALUE = MDIO_u8GetPinValue(KEYPAD_u8_PORT, KEYPAD_Au8ColsPins[local_u8_Col_Counter]);
			if(local_PIN_VALUE == DIO_u8_LOW)
			{
				_delay_ms(KEYPAD_u8_DEBOUNCING_MS);
				local_PIN_VALUE = MDIO_u8GetPinValue(KEYPAD_u8_PORT, KEYPAD_Au8ColsPins[local_u8_Col_Counter]);
				while(local_PIN_VALUE == DIO_u8_LOW)
				{
					local_PIN_VALUE = MDIO_u8GetPinValue(KEYPAD_u8_PORT, KEYPAD_Au8ColsPins[local_u8_Col_Counter]);
				}
				local_KEY_VALUE = KEYPAD_Au8KEYS[local_u8_Row_Counter][local_u8_Col_Counter];
				local_u8Flag = KEYPAD_u8_FLAG_UP;
				break;
			}
		}
			MDIO_voidSetPinValue(KEYPAD_u8_PORT, KEYPAD_Au8RowsPins[local_u8_Row_Counter], DIO_u8_HIGH);
			if(local_u8Flag == KEYPAD_u8_FLAG_UP)
			{
				break;
			}
		}
		return local_KEY_VALUE;

}
s32 calculate(s32 x, u8 op, s32 y)
{
	u32 r=0;
    switch (op) {
    case '+':
        return (x-48) + (y-48);
    case '-':
        return (x-48) - (y-48);
    case '*':
        return (x-48) * (y-48);
    case '/':
        return (x-48) / (y-48);
    }
    //return r = x;
}

void main(void)
{
 MDIO_voidINIT();
 HLCD_voidInit();
 u8 value = 255;
 u8 value1 = 255;
 u8 value2 =255;
 u8 op;
 u8 flag=0;
 s32 result = 0 ;
 HLCD_voidSendString(" Enter operation!");
 _delay_ms(10000);
	HLCD_voidClearDisplay();
 while(1)
 {
	 value = KEYPAD_u8_GetKey();


	 if(value!= KEYPAD_u8_KEY_NOT_PRESSED)
	 {
		 if(value =='c')
			 {
				 HLCD_voidClearDisplay();
				 _delay_ms(1000);
				 HLCD_voidSendString(" Enter operation!");
				 _delay_ms(10000);
				 HLCD_voidClearDisplay();
				 flag =0;
			 }
		 else{
		HLCD_voidSendData(value);
		if(flag ==0)
		{
			value1 =(int) value;
		}
		if (flag ==1)
		{
			op = value;
		}
		if(flag ==2)
		{
			value2 = (int)value;
		}
		if(flag == 3)
		{
			result = calculate(value1, op, value2);
			HLCD_displayNumber(result);
		}

		flag++;
		 }
	 }
 }
}

