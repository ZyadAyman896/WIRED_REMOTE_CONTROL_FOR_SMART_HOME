/*
 * LCD.h
 *
 * Created: 12/1/2023 11:17:13 AM
 *  Author: Zyad Ayman
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
void LCD_vInit();
void LCD_vSendChar(u8 copy_u8char);
void LCD_vSendString(u8* copy_u8char);
void LCD_vSendCommand(u8 copy_u8char);
void LCD_vEnable_Falling_Edge();
void LCD_vMoveCursor(u8 copy_row , u8 copy_col);
void LCD_vCreateCustomChar(u8* Array , u8 copy_Location);
void LCD_vSendNumber(u16 Copy_u8Number);
u16 LCD_u16Get_Lengh_Of_Number(u16 Copy_u16Number);
void LCD_vClear_Display();
#endif /* LCD_H_ */