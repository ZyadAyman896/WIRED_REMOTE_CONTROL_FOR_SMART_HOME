/*
 * KEYPAD_CONFIG.h
 *
 * Created: 2/24/2024 2:50:03 PM
 *  Author: Zyad Ayman
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_
//YOU CAN CONFIGURE WHICH PORT YOU WANT FOR KEYPAD
#include "Utils.h"
//#define KEYPAD_PORT PORTA
#define KEYPAD_NOT_PRESSED 255
#define KEYPAD_ROWS_START PIN_NO_0
#define KEYPAD_ROWS_END	  PIN_NO_3
#define KEYPAD_COL_START  PIN_NO_4
#define KEYPAD_COL_END	  PIN_NO_7
#define KEYPAD_R0 PIN_NO_0
#define KEYPAD_R1 PIN_NO_1
#define KEYPAD_R2 PIN_NO_2
#define KEYPAD_R3 PIN_NO_3
				  
#define KEYPAD_C0 PIN_NO_4
#define KEYPAD_C1 PIN_NO_5
#define KEYPAD_C2 PIN_NO_6
#define KEYPAD_C3 PIN_NO_7
#define KEYPAD_ROWS 4
#define KEYPAD_COL 4

#endif /* KEYPAD_CONFIG_H_ */