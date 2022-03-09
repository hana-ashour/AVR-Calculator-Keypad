/*
 * LCD_configuration.h
 *
 *  Created on: Jan 4, 2022
 *      Author: hanaashour
 */

#ifndef INCLUDE_HAL_LCD_CONFIGURATION_H_
#define INCLUDE_HAL_LCD_CONFIGURATION_H_

#define LCD_DATA_PORT			DIO_u8_PORTA
#define LCD_CONTROL_PORT		DIO_u8_PORTB
//options DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD

#define LCD_RS_PIN				DIO_u8_PIN2
#define LCD_RW_PIN				DIO_u8_PIN1
#define LCD_E_PIN				DIO_u8_PIN0
//options DIO_u8_PIN0---->DIO_u8_PIN7




#endif /* INCLUDE_HAL_LCD_CONFIGURATION_H_ */
