/*
 * bit.h
 *
 *  Created on: Jan 3, 2022
 *      Author: hanaashour
 */

#ifndef INCLUDE_LIB_BIT_H_
#define INCLUDE_LIB_BIT_H_

#define SET(reg,num) (reg |=1<<num)
#define CLR(reg,num) (reg&=~(1<<num))
#define TOGGLE(reg,num) (reg^=(1<<num))
#define GET(reg,num) ((reg>>num)&0x01)
#define SET_BYTE(reg,value) (reg=value)

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) 	conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 	0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /* INCLUDE_LIB_BIT_H_ */
