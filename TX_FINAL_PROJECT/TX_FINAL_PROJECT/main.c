/*
 * TX_FINAL_PROJECT.c
 *
 * Created: 4/24/2024 10:01:15 PM
 * Author : Zyad Ayman
 */ 

#define F_CPU 8000000UL
#include "DIO.h"
#include "Keypad.h"
#include "KEYPAD_CONFIG.h"
#include "UART.h"
#include "UART_Private.h"
#include <util/delay.h>


int main(void)
{
	//Initiallizing UART with Baud rate = 9600 , even parity ,8 bit , async , 1 stop bit
    UART_vInit();
	
	//Intiallizing Keypad
	KEYPAD_vInit('a');

    while (1) 
    {
		 
		switch (KEYPAD_u8_GetButton('a'))
		{
			case '0':
				        // Send "ready to receive" signal				
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
						
						//sending Actual Data
						UART_vSendData('0');
			break;
			case '1':
				        // Send "ready to receive" signal
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
				        
				        //sending Actual Data
				        UART_vSendData('1');			
			break;
			case '2':
				        // Send "ready to receive" signal
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
				        
				        //sending Actual Data
				        UART_vSendData('2');
			break;
			case '3':
				        // Send "ready to receive" signal
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
				        
				        //sending Actual Data
				        UART_vSendData('3');			
			break;
			case '4':
				        // Send "ready to receive" signal
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
				        
				        //sending Actual Data
				        UART_vSendData('4');			
			break;
			case '5':
				        // Send "ready to receive" signal
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
				        
				        //sending Actual Data
				        UART_vSendData('5');			
			break;
			case '6':
				        // Send "ready to receive" signal
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
				        
				        //sending Actual Data
				        UART_vSendData('6');			
			break;
			case '7':
				        // Send "ready to receive" signal
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
				        
				        //sending Actual Data
				        UART_vSendData('7');			
			break;
			case '8':
				        // Send "ready to receive" signal
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
				        
				        //sending Actual Data
				        UART_vSendData('8');			
			break;
			case '9':
				        // Send "ready to receive" signal
				        UART_vSendData('R');
				        
				        // Wait for acknowledgment from the receiver
				        while (UART_u8GetData() != 'A');
				        
				        //sending Actual Data
				        UART_vSendData('9');		
			break;		
		
		}
    }
}

