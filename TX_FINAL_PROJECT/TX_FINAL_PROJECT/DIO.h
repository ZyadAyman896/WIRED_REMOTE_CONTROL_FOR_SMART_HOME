/*
 * DIO.h
 *
 * Created: 11/3/2023 11:49:36 AM
 *  Author: Zyad Ayman
 */ 

#ifndef DIO_H_
#define DIO_H_
#include "std_types.h"
#include "Registers.h"
#include "Utils.h"

void DIO_vSet_Port_Direction(u8 copy_u8PortName ,u8 copy_u8PortDirection);
void DIO_vSet_Pin_Value(u8 copy_u8PortName , u8 copy_u8PinNumber ,u8 copy_u8PinValue);
void DIO_vSet_Pin_Direction(u8 copy_u8PortName , u8 copy_u8PinNumber ,u8 copy_u8PinDirection);
void DIO_vSet_Port_Value(u8 copy_u8PortName ,u8 copy_u8PortValue);
u8 DIO_u8GET_Pin_value(u8 copy_u8PinName,u8 copy_u8PinNumber);
u8 DIO_u8GET_Port_value(u8 copy_u8PinName );
void DIO_vToggle_Port_Value(u8 copy_u8PortName);
void DIO_vToggle_Pin_Value(u8 copy_u8PortName, u8 copy_u8PinNumber);
#endif /* DIO_H_ */