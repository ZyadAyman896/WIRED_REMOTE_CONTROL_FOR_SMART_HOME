/*
 * Keypad.h
 *
 * Created: 11/29/2023 11:39:19 PM
 *  Author: Zyad Ayman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO.h"
#include "KEYPAD_CONFIG.h"
void KEYPAD_vInit(u8 copy_u8PortName);
u8 KEYPAD_u8_GetButton(u8 copy_u8PortName);


#endif /* KEYPAD_H_ */