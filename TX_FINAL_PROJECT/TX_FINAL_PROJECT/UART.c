/*
 * UART.c
 *
 * Created: 3/6/2024 9:38:53 PM
 *  Author: Zyad Ayman
 */ 
#include "DIO.h"
#include "UART.h"
#include "Utils.h"
#include "UART_Private.h"
void UART_vInit(void)
{
	//enable tx & rx
	UCSRB = 0x18 ;
	//even parity ,8 bit , async , 1 stop bit
	USCRC = 0xA6 ;
	//baud rate = 9600 ,fcpu 8mhz
	UBRRL = 51 ;
	
}
void UART_vSendData(u8 copy_u8Data)
{
	while(READ_PIN(UCSRA,PIN_NO_5) == 0 );
	UDR = copy_u8Data ;
	
}
u8 UART_u8GetData(void)
{
	while(READ_PIN(UCSRA,PIN_NO_7) == 0);
	return READ_WHOLE_REG(UDR);
}
void UART_vSendString(Pu8 Ptr)
{
	while(*Ptr != '\0')
	{
		UART_vSendData(*Ptr);
		Ptr++;
	}
}
//Those Functions to make handshaking algorithm
// Function to enable UART flow control
void UART_vEnable_Flow_Control() {
	// Configure RTS and CTS pins as outputs/inputs
	// CTS pin as input
	DIO_vSet_Pin_Direction('d',PIN_NO_2,INPUT);
	// RTS pin as output
	DIO_vSet_Pin_Direction('d',PIN_NO_3,OUTPUT);
}

// Function to disable UART flow control
void UART_vDisable_Flow_Control() {
	// Restore RTS pin as input (disable flow control)
	DIO_vSet_Pin_Direction('d',PIN_NO_3,INPUT);
}