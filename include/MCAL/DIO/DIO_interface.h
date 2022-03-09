/*
 * DIO_interface.h
 *
 *  Created on: Jan 3, 2022
 *      Author: hanaashour
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

#define DIO_u8_PORTA	0
#define DIO_u8_PORTB	1
#define DIO_u8_PORTC	2
#define DIO_u8_PORTD	3

#define DIO_u8_PIN0		0
#define DIO_u8_PIN1		1
#define DIO_u8_PIN2		2
#define DIO_u8_PIN3		3
#define DIO_u8_PIN4		4
#define DIO_u8_PIN5		5
#define DIO_u8_PIN6		6
#define DIO_u8_PIN7		7

#define DIO_u8_OUTPUT	1
#define DIO_u8_INPUT	0

#define DIO_u8_HIGH		1
#define DIO_u8_LOW		0

void MDIO_voidINIT(void);
//M---> for MCAl,INIT---->initialize
//takes porta or portb or portc or portd

void MDIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDirection);
//direction(output or input)
//takes port id, pin id, pin direction.

void MDIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinValue);
//input: port id, pin id
//output: copy port id, copy pin id

u8 MDIO_u8GetPinValue(u8 copy_u8PortID,u8 copy_u8PinID);
//return: copy port id,pin value

void MDIO_voidSetPortDirection(u8 copy_u8PortID, u8 copy_u8PortDirection);


void MDIO_voidSetPortValue (u8 copy_u8PortID, u8 copy_u8PortValue);




#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
