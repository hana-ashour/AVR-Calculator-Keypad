/*
 * LCD_interface.h
 *
 *  Created on: Jan 4, 2022
 *      Author: hanaashour
 */

#ifndef INCLUDE_HAL_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_INTERFACE_H_

void HLCD_voidInit(void);
void HLCD_voidSendData(u8 copy_u8char);
void HLCD_voidSendString(u8*copy_Pu8String);
void HLCD_voidClearDisplay(void);
void HLCD_voidGoToPos(u8 copy_u8row,u8 copy_u8col);
void HLCD_voidSendSpecialCharacter(u8*copy_p8CharArr,u8 copy_u8PatternNum,
								   u8 copy_u8LineNum,u8 copy_ColNum);
void HLCD_displayNumber(s32 copy_s32Number);


#define LCD_u8_LINE1		1
#define LCD_u8_LINE2		2




#endif /* INCLUDE_HAL_LCD_INTERFACE_H_ */
