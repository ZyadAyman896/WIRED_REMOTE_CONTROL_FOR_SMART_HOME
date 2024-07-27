/*
 * LCD.c
 *
 * Created: 12/1/2023 11:16:57 AM
 *  Author: Zyad Ayman
 */ 
//*****************************************
/*
1- to clear display 
LCD_vSendCommand(0x01);
2-Return home
returns display to its original position if it was shifted
LCD_vSendCommand(0x02);


*/
//RS ==> Register select

#include "DIO.h"
#include "LCD.h"
#include <util/delay.h>
//CONFIG.H WHERE YOU CAN DEFINE AND UNDEF MACROS FOR USING 4-BIT MODE OR 8-BIT MODE
#include "LCD_Configuration.h"
//you can control which port is for data and which is for control from "LCD_Configuration.h"
//valid
void LCD_vSendCommand(u8 copy_u8Char)
{
	/*
		...take care that if it is in FOUR bit mode	
		you must send the high nibble of instructions first 
		and then you take the low nibble and shift them left by four bits 
		as we send data or instructions on the 4 most significant pins of the port
	
	*/
	//Rs == 0
	DIO_vSet_Pin_Value(CTRL_PORT,RS,ZERO); 
	//sending  instructions 
	DIO_vSet_Port_Value(DATA_PORT,copy_u8Char);
	//Enable
	LCD_vEnable_Falling_Edge();
	
}
//valid
void LCD_vInit()
{
	#ifdef LCD_8BitMode
	//MAKES PORTX OUTPUT
	DIO_vSet_Port_Direction(DATA_PORT,0xff);
	//MAKES PORTY OUTPUT FOR E and Rs 
	DIO_vSet_Port_Direction(CTRL_PORT,0x03);
	_delay_ms(40);
	LCD_vSendCommand(0b00111000);//0x38
	_delay_ms(1);
	LCD_vSendCommand(0b00001111);//0x0f
	_delay_ms(1);
	LCD_vSendCommand(0b00000001);
	_delay_ms(2);
	#endif
	#ifdef LCD_4BitMode
	/* we can use one function instead those four lines for writing on half of the port and use inside it the write on most or least nibble */
	/*on default you always use from 4th pin of any port to the 7th port in 4-bit  init*/
	//I HAVE USED THOSE FOUR LINES TO NOT CORRUPT THE DIRECTION OF THE FIRST FOUR PINS OF THE PORT 
	//WE MAKE THE 2ND FOUR PINS OF THE PORTA IS OUTPUT
	DIO_vSet_Pin_Direction(DATA_PORT , PIN_NO_4 , OUTPUT);
	DIO_vSet_Pin_Direction(DATA_PORT , PIN_NO_5 , OUTPUT);
	DIO_vSet_Pin_Direction(DATA_PORT , PIN_NO_6 , OUTPUT);
	DIO_vSet_Pin_Direction(DATA_PORT , PIN_NO_7 , OUTPUT);
	//MAKING (PIN0 ==> RS) AND (PIN1 ==> E) IN PORTB OUTPUT
	DIO_vSet_Pin_Direction(CTRL_PORT , RS , OUTPUT); // RS
	DIO_vSet_Pin_Direction(CTRL_PORT , E , OUTPUT); // E
	//BEGIN INIT
	_delay_ms(40);
	//Function Set
	//1st and 2nd command no configurable options
	LCD_vSendCommand(0b00100000);
	LCD_vSendCommand(0b00100000);
	//bit 6 ==> Font of char(F) & bit 7 ==> line display (N)
	//F==> 5*7 ==> 0 or 5*10 ==> 1
	//N ==> 1 line ==> 0 or 2lines ==> 1
	LCD_vSendCommand(0x80); //now i have edited i want two lines
	_delay_us(40);	
	//Display ON / OFF
	//D 4th bit, C 5th bit, B 6th bit
	//D ==> display on off .... if == 0 => off ...else ON
	//C ==> cursor display .... if == 0 => off ...else ON
	//B ==> cursor Blink .... if == 0 => off ...else ON
	LCD_vSendCommand(0x00);
	LCD_vSendCommand(0xf0);
	_delay_us(40);	
	//Display clear 
	LCD_vSendCommand(0x00);
	LCD_vSendCommand(0x10);
	_delay_ms(2);
	//Entry mode set 
	//I/D 5th bit , SH 4th bit 
	//I/D ==> for 
	//SH ==> shift entire display left or right 
	LCD_vSendCommand(0x00);
	LCD_vSendCommand(0b01000000);
	#endif
}
//valid
void LCD_vSendChar(u8 copy_u8char)
{
	#ifdef LCD_8BitMode
	//Rs = 1
	DIO_vSet_Pin_Value(CTRL_PORT,RS,ONE); 
	
	DIO_vSet_Port_Value(DATA_PORT,copy_u8char);
	//Enable 
	LCD_vEnable_Falling_Edge();
	#endif
	#ifdef LCD_4BitMode 
	 //Rs = 1
	DIO_vSet_Pin_Value(CTRL_PORT,RS,ONE);
	//Sending HIGH NIBBLE OF DATA
	DIO_vSet_Port_Value(DATA_PORT,copy_u8char & 0xf0); 
	//Enable
	LCD_vEnable_Falling_Edge();
	_delay_ms(1);
	//Sending LOW NIBBLE OF DATA
	DIO_vSet_Port_Value(DATA_PORT, copy_u8char << FOUR); 
	//Enable
	LCD_vEnable_Falling_Edge();
	_delay_ms(2);
	#endif
}
//valid
void LCD_vSendString(Pu8 Address_u8char)
{
	while(*Address_u8char !='\0')
	{
		LCD_vSendChar(*Address_u8char);
		Address_u8char++;
	}
}
//MAKES ENABLE PIN IS IN PORTB & ITS ORDER IS SECOND PIN AND RS IS THE FIRST ONE 
//valid
void LCD_vEnable_Falling_Edge()
{
	#ifdef LCD_8BitMode 
	//Enable
	DIO_vSet_Pin_Value(CTRL_PORT,PIN_NO_1,ONE);
	_delay_ms(1);
	DIO_vSet_Pin_Value(CTRL_PORT,PIN_NO_1,ZERO);

	#endif
	#ifdef LCD_4BitMode
	//Enable
	DIO_vSet_Pin_Value(CTRL_PORT,PIN_NO_1,ONE);
	_delay_ms(1);
	DIO_vSet_Pin_Value(CTRL_PORT,PIN_NO_1,ZERO);	
	#endif
}
//valid
void LCD_vMoveCursor(u8 copy_row , u8 copy_col)
{
	#ifdef LCD_8BitMode
	
	//ROWS AND COLUMNS START FROM ZERO
	//AC is Address counter
	u8 copy_AC = 0 , copy_value = 0 ;
	if (copy_row == ZERO) //IF FIRST ROW 
		copy_AC = copy_col ;
	else //IF SECOND ROW 
	{
		copy_AC = 0x40 + copy_col ;	//MAKES AC BEGIN FROM 2ND ROW 	
	}
	copy_value = copy_AC  + 0x80 ;//0x80 to set ddram address 
		LCD_vSendCommand(copy_value);
	#endif
	#ifdef LCD_4BitMode
	
		u8 copy_AC = 0 , copy_value = 0 ;
		if (copy_row == ZERO  ) //IF FIRST ROW
		copy_AC = copy_col ;
		else //IF SECOND ROW
		{
			copy_AC = 0x40 + copy_col ;	//MAKES AC BEGIN FROM 2ND ROW
		}
		//0x80 to set ddram address 
		copy_value = copy_AC  + 0x80 ;
		//Sending High nibble of instructions first
		LCD_vSendCommand(copy_value & 0xf0);
		//Sending low nibble of instructions second
		LCD_vSendCommand( ( (copy_value & 0x0f) << FOUR ) );      
	#endif
}
//valid
void LCD_vCreateCustomChar(u8* Array , u8 copy_Location)
{
	u8 copy_AC = copy_Location * EIGHT , copy_value ;
	copy_value = copy_AC + 0x40 ;
	LCD_vSendCommand(copy_value);
	for (u8 i = 0 ; i < EIGHT ; i++)
	{
		LCD_vSendChar( Array[i] );
	}
}
//valid
u16 LCD_u16Get_Lengh_Of_Number(u16 Copy_u16Number)
{
	u16 Length = (Copy_u16Number == 0? 1 :0);
	while(Copy_u16Number>0)
	{
		Length++;
		Copy_u16Number/=10;
	}
	return Length;
}
//valid
void LCD_vSendNumber(u16 Copy_u8Number)
{
	u8 str[16];
	u16 i=0;
	u16 length = LCD_u16Get_Lengh_Of_Number(Copy_u8Number);

	while(length > 0)
	{
		u8 digit = Copy_u8Number%10;
		str[i] = digit + '0';
		Copy_u8Number /= 10;
		length--;
		i++;
	}

	str[i] = '\0';

	u16 start = 0;
	u16 end = i - 1;
	while (start < end)
	{
		u8 temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	u16 j=0;
	while(str[j] != '\0')
	{
		if (str[j]==0)
		LCD_vSendChar('0');
		else
		LCD_vSendChar(str[j]);
		j++;
		
	}
}
void LCD_vClear_Display()
{
	//clearing display
	#ifdef LCD_8BitMode
	LCD_vSendCommand(0x01);
	#endif
	#ifdef LCD_4BitMode
	LCD_vSendCommand(0x00);
	LCD_vSendCommand(0x10);
	#endif	
	
}