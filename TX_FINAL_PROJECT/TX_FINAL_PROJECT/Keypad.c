/*
 * Keypad.c
 *
 * Created: 11/29/2023 11:39:34 PM
 *  Author: Zyad Ayman
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Keypad.h"
											 /*C0   C1  C2  C3*/
											 u8 KeyPad_Buttons[KEYPAD_ROWS][KEYPAD_COL] = {{'7','8','9','/'},/*row0*/
											 {'4','5','6','*'},/*row1*/
											 {'1','2','3','-'},/*row2*/
											 {'?','0','=','+'} /*row3*/};
void KEYPAD_vInit(u8 copy_u8PortName)
{
		DIO_vSet_Port_Direction(copy_u8PortName,0xf0);// R0 >> R3 -> INPUT , C0 >> C3 -> OUTPUT
		DIO_vSet_Port_Value(copy_u8PortName,0xff); // PullUp For R0 >> R3 , HIGH for C0 >> C3	
}
u8 KEYPAD_u8_GetButton(u8 copy_u8PortName)
{
	
	u8 LOC_u8Return_Data = KEYPAD_NOT_PRESSED  , LOC_u8Get_Pressed ;
	u8 LOC_u8Row , LOC_u8Col ;
	
	// R 's from port 0 >> 3
	//C 's from port 4 >> 7

			for (LOC_u8Col = 0 ; LOC_u8Col < KEYPAD_COL ; LOC_u8Col++)
			{
				
				DIO_vSet_Pin_Value(copy_u8PortName , LOC_u8Col + 4, ZERO);

				for (LOC_u8Row = 0 ; LOC_u8Row < KEYPAD_ROWS ; LOC_u8Row++)
				{
					
					LOC_u8Get_Pressed = DIO_u8GET_Pin_value(copy_u8PortName , LOC_u8Row) ;  
					
					if( LOC_u8Get_Pressed == 0 )
					{
						
						_delay_ms(50);
			
						LOC_u8Get_Pressed = DIO_u8GET_Pin_value(copy_u8PortName , LOC_u8Row) ;			
			
						if (LOC_u8Get_Pressed == ZERO)	
						{	LOC_u8Return_Data = KeyPad_Buttons[LOC_u8Row][LOC_u8Col] ;	}
			
						_delay_ms(200);	
			
						break;
					
					}
			
				}
			
				DIO_vSet_Pin_Value(copy_u8PortName , LOC_u8Col + 4, ONE);
			
			}
			
			
			return  LOC_u8Return_Data ;
}