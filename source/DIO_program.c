/*
 * DIO_program.c
 *
 *  Created on: Jan 3, 2022
 *      Author: hanaashour
 */
#include "../include/LIB/bit.h"
#include "../include/LIB/types.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/DIO/DIO_private.h"
#include "../include/MCAL/DIO/DIO_configuration.h"

void MDIO_voidINIT(void)
{
DIO_u8_DDRA_REG = CONC_BIT(DIO_u8_PA7_INITIAL_DIRECTION,DIO_u8_PA6_INITIAL_DIRECTION,DIO_u8_PA5_INITIAL_DIRECTION,
						   DIO_u8_PA4_INITIAL_DIRECTION,DIO_u8_PA3_INITIAL_DIRECTION,DIO_u8_PA2_INITIAL_DIRECTION,
						   DIO_u8_PA1_INITIAL_DIRECTION,DIO_u8_PA0_INITIAL_DIRECTION);

DIO_u8_DDRB_REG = CONC_BIT(DIO_u8_PB7_INITIAL_DIRECTION,DIO_u8_PB6_INITIAL_DIRECTION,DIO_u8_PB5_INITIAL_DIRECTION,
						   DIO_u8_PB4_INITIAL_DIRECTION,DIO_u8_PB3_INITIAL_DIRECTION,DIO_u8_PB2_INITIAL_DIRECTION,
						   DIO_u8_PB1_INITIAL_DIRECTION,DIO_u8_PB0_INITIAL_DIRECTION);

DIO_u8_DDRC_REG = CONC_BIT(DIO_u8_PC7_INITIAL_DIRECTION,DIO_u8_PC6_INITIAL_DIRECTION,DIO_u8_PC5_INITIAL_DIRECTION,
						   DIO_u8_PC4_INITIAL_DIRECTION,DIO_u8_PC3_INITIAL_DIRECTION,DIO_u8_PC2_INITIAL_DIRECTION,
						   DIO_u8_PC1_INITIAL_DIRECTION,DIO_u8_PC0_INITIAL_DIRECTION);

DIO_u8_DDRD_REG = CONC_BIT(DIO_u8_PD7_INITIAL_DIRECTION,DIO_u8_PD6_INITIAL_DIRECTION,DIO_u8_PD5_INITIAL_DIRECTION,
						   DIO_u8_PD4_INITIAL_DIRECTION,DIO_u8_PD3_INITIAL_DIRECTION,DIO_u8_PD2_INITIAL_DIRECTION,
						   DIO_u8_PD1_INITIAL_DIRECTION,DIO_u8_PD0_INITIAL_DIRECTION);



DIO_u8_PORTA_REG = CONC_BIT(DIO_u8_PA7_INITIAL_VALUE,DIO_u8_PA6_INITIAL_VALUE,DIO_u8_PA5_INITIAL_VALUE,
						    DIO_u8_PA4_INITIAL_VALUE,DIO_u8_PA3_INITIAL_VALUE,DIO_u8_PA2_INITIAL_VALUE,
						    DIO_u8_PA1_INITIAL_VALUE,DIO_u8_PA0_INITIAL_VALUE);

DIO_u8_PORTB_REG = CONC_BIT(DIO_u8_PB7_INITIAL_VALUE,DIO_u8_PB6_INITIAL_VALUE,DIO_u8_PB5_INITIAL_VALUE,
						    DIO_u8_PB4_INITIAL_VALUE,DIO_u8_PB3_INITIAL_VALUE,DIO_u8_PB2_INITIAL_VALUE,
						    DIO_u8_PB1_INITIAL_VALUE,DIO_u8_PB0_INITIAL_VALUE);

DIO_u8_PORTC_REG = CONC_BIT(DIO_u8_PC7_INITIAL_VALUE,DIO_u8_PC6_INITIAL_VALUE,DIO_u8_PC5_INITIAL_VALUE,
						      DIO_u8_PC4_INITIAL_VALUE,DIO_u8_PC3_INITIAL_VALUE,DIO_u8_PC2_INITIAL_VALUE,
						      DIO_u8_PC1_INITIAL_VALUE,DIO_u8_PC0_INITIAL_VALUE);

DIO_u8_PORTD_REG = CONC_BIT(DIO_u8_PD7_INITIAL_VALUE,DIO_u8_PD6_INITIAL_VALUE,DIO_u8_PD5_INITIAL_VALUE,
						      DIO_u8_PD4_INITIAL_VALUE,DIO_u8_PD3_INITIAL_VALUE,DIO_u8_PD2_INITIAL_VALUE,
						      DIO_u8_PD1_INITIAL_VALUE,DIO_u8_PD0_INITIAL_VALUE);
}

void MDIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDirection)
{
	if((copy_u8PortID>DIO_u8_PORTD)||(copy_u8PortID<DIO_u8_PORTA)||
	 (copy_u8PinID>DIO_u8_PIN7)||(copy_u8PinID<DIO_u8_PIN0))
	 {

	 }
	else
	{
		switch(copy_u8PortID)
		{
		case DIO_u8_PORTA:
			switch(copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT: SET(DIO_u8_DDRA_REG,copy_u8PinID);
				break;
			case DIO_u8_INPUT: CLR(DIO_u8_DDRA_REG,copy_u8PinID);
				break;
			}break;

		case DIO_u8_PORTB:
			switch(copy_u8PinDirection)
			 {
				case DIO_u8_OUTPUT: SET(DIO_u8_DDRB_REG,copy_u8PinID);
					break;
				case DIO_u8_INPUT: CLR(DIO_u8_DDRB_REG,copy_u8PinID);
					break;
			 }break;

		case DIO_u8_PORTC:
			switch(copy_u8PinDirection)
			 {
				case DIO_u8_OUTPUT: SET(DIO_u8_DDRC_REG,copy_u8PinID);
					break;
				case DIO_u8_INPUT: CLR(DIO_u8_DDRC_REG,copy_u8PinID);
					break;
			 }break;

		case DIO_u8_PORTD:
			switch(copy_u8PinDirection)
			 {
				case DIO_u8_OUTPUT: SET(DIO_u8_DDRD_REG,copy_u8PinID);
					break;
				case DIO_u8_INPUT: CLR(DIO_u8_DDRD_REG,copy_u8PinID);
					break;
	   		 }break;

		}
	}
}

void MDIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinValue)
{
	if((copy_u8PortID>DIO_u8_PORTD)||(copy_u8PortID<DIO_u8_PORTA)||
		 (copy_u8PinID>DIO_u8_PIN7)||(copy_u8PinID<DIO_u8_PIN0))
		 {

		 }
		else
		{
			switch(copy_u8PortID)
			{
			case DIO_u8_PORTA:
				switch(copy_u8PinValue)
				{
				case DIO_u8_HIGH: SET(DIO_u8_PORTA_REG,copy_u8PinID);
					break;
				case DIO_u8_LOW: CLR(DIO_u8_PORTA_REG,copy_u8PinID);
					break;
				}break;

			case DIO_u8_PORTB:
				switch(copy_u8PinValue)
				 {
					case DIO_u8_HIGH: SET(DIO_u8_PORTB_REG,copy_u8PinID);
						break;
					case DIO_u8_LOW: CLR(DIO_u8_PORTB_REG,copy_u8PinID);
						break;
				 }break;

			case DIO_u8_PORTC:
				switch(copy_u8PinValue)
				 {
					case DIO_u8_HIGH: SET(DIO_u8_PORTC_REG,copy_u8PinID);
						break;
					case DIO_u8_LOW: CLR(DIO_u8_PORTC_REG,copy_u8PinID);
						break;
				 }break;

			case DIO_u8_PORTD:
				switch(copy_u8PinValue)
				 {
					case DIO_u8_HIGH: SET(DIO_u8_PORTD_REG,copy_u8PinID);
						break;
					case DIO_u8_LOW: CLR(DIO_u8_PORTD_REG,copy_u8PinID);
						break;
		   		 }break;

			}
		}
}

u8 MDIO_u8GetPinValue(u8 copy_u8PortID,u8 copy_u8PinID)
{
	u8 local_u8PinValue = 2;
	if((copy_u8PortID>DIO_u8_PORTD)||(copy_u8PortID<DIO_u8_PORTA)||
		(copy_u8PinID>DIO_u8_PIN7)||(copy_u8PinID<DIO_u8_PIN0))
		 {

		}
	else
	{
		switch(copy_u8PortID)
		{
		case DIO_u8_PORTA: local_u8PinValue = GET(DIO_u8_PINA_REG,copy_u8PinID);
		break;
		case DIO_u8_PORTB: local_u8PinValue = GET(DIO_u8_PINB_REG,copy_u8PinID);
		break;
		case DIO_u8_PORTC: local_u8PinValue = GET(DIO_u8_PINC_REG,copy_u8PinID);
		break;
		case DIO_u8_PORTD: local_u8PinValue = GET(DIO_u8_PIND_REG,copy_u8PinID);
		break;
		}
	}
	return local_u8PinValue;
}

void MDIO_voidSetPortDirection(u8 copy_u8PortID, u8 copy_u8PortDirection)
{
	if((copy_u8PortID>DIO_u8_PORTD)||(copy_u8PortID<DIO_u8_PORTA))
		 {

		 }
		else
		{
			switch(copy_u8PortID)
			{
			case DIO_u8_PORTA: DIO_u8_DDRA_REG = copy_u8PortDirection;
					break;
			case DIO_u8_PORTB: DIO_u8_DDRB_REG = copy_u8PortDirection;
					break;
			case DIO_u8_PORTC: DIO_u8_DDRC_REG = copy_u8PortDirection;
					break;
			case DIO_u8_PORTD: DIO_u8_DDRD_REG = copy_u8PortDirection;
					break;
			}
		}
}
void MDIO_voidSetPortValue (u8 copy_u8PortID, u8 copy_u8PortValue)
{
		if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA))
		{

		}
		else
		{
			switch (copy_u8PortID)
			{
				case DIO_u8_PORTA: DIO_u8_PORTA_REG = copy_u8PortValue ; break;
				case DIO_u8_PORTB: DIO_u8_PORTB_REG = copy_u8PortValue  ; break;
				case DIO_u8_PORTC: DIO_u8_PORTC_REG = copy_u8PortValue  ; break;
				case DIO_u8_PORTD: DIO_u8_PORTD_REG = copy_u8PortValue  ; break;
			}

		}
}

/*void main (void)
{
	MDIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_INPUT);
	MDIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0,DIO_u8_HIGH);
	MDIO_voidSetPortDirection(DIO_u8_PORTA,0xFF);
	while (1)
	{
		if (MDIO_u8GetPinValue(DIO_u8_PORTB,DIO_u8_PIN0)==0)
		{
			MDIO_voidSetPortValue(DIO_u8_PORTA,0xFF);
		}
		else
		{
			MDIO_voidSetPortValue(DIO_u8_PORTA,0x00);
		}
	}
}*/
