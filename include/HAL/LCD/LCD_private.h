/*
 * LCD_private.h
 *
 *  Created on: Jan 4, 2022
 *      Author: hanaashour
 */

#ifndef INCLUDE_HAL_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_PRIVATE_H_

void Private_voidSendCommand(u8 cmd);

#define LCD_u8_FUNCTION_SET		0b00111100
#define LCD_u8_DISPLAY_CONTROL	0b00001100
#define LCD_u8_CLEAR			0b00000001
#define LCD_u8_ENTRY			0b00000110

#define LCD_u8_ROW1_ADDRESS		127
#define LCD_u8_ROW2_ADDRESS		191



#endif /* INCLUDE_HAL_LCD_PRIVATE_H_ */
