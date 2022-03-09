/*
 * KEYPAD_configuration.h
 *
 *  Created on: Jan 9, 2022
 *      Author: hanaa
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_

#define KEYPAD_u8_PORT		 DIO_u8_PORTC

#define KEYPAD_u8_R1_PIN	 DIO_u8_PIN0
#define KEYPAD_u8_R2_PIN	 DIO_u8_PIN1
#define KEYPAD_u8_R3_PIN	 DIO_u8_PIN2
#define KEYPAD_u8_R4_PIN	 DIO_u8_PIN3

#define KEYPAD_u8_C1_PIN	 DIO_u8_PIN4
#define KEYPAD_u8_C2_PIN	 DIO_u8_PIN5
#define KEYPAD_u8_C3_PIN	 DIO_u8_PIN6
#define KEYPAD_u8_C4_PIN	 DIO_u8_PIN7

#define KEYPAD_u8ROW_NUM	 4
#define KEYPAD_u8COL_NUM	 4

#define KEYPAD_Au8_KEYS		 {{'7','8','9','/'},\
							  {'4','5','6','*'},\
							  {'1','2','3','-'},\
							  {'c','0','=','+'}}

#define KEYPAD_Au8Rows		 {KEYPAD_u8_R1_PIN, KEYPAD_u8_R2_PIN, KEYPAD_u8_R3_PIN, KEYPAD_u8_R4_PIN}
#define KEYPAD_Au8Cols		 {KEYPAD_u8_C1_PIN, KEYPAD_u8_C2_PIN, KEYPAD_u8_C3_PIN, KEYPAD_u8_C4_PIN}

#define KEYPAD_u8_KEY_NOT_PRESSED	0xFF

#define KEYPAD_u8_DEBOUNCING_MS		20

#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_ */



