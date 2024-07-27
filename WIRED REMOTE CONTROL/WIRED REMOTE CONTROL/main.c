/*
 * WIRED REMOTE CONTROL.c
 *
 * Created: 4/24/2024 9:54:48 PM
 * Author : Zyad Ayman
 */ 
#define F_CPU 8000000UL

#include "DIO.h"
#include "ADC.h"
#include "ADC_CONFIGURATIONS.h"
#include "LCD.h"
#include "LCD_Configuration.h"
#include "PWM_Configurations.h"
#include "PWM_ICU_WDT.h"
#include "LED.h"
#include "UART.h"
#include <util/delay.h>


int main(void)
{
	
	//setting dirn of ports
	DIO_vSet_Pin_Direction('c',PIN_NO_4,OUTPUT);//IN1
	DIO_vSet_Pin_Direction('c',PIN_NO_5,OUTPUT);//IN2
	
	//OUTPutting high or low on the two pins
	//ANTI_clockwise
	DIO_vSet_Pin_Value('c',PIN_NO_4,ONE);//IN1 == HIGH
	DIO_vSet_Pin_Value('c',PIN_NO_5,ZERO);//IN2 == LOW
	
	//Intitialization of Fast mode PWM Timer1 for Servo Motor 
	PWM_vInit_T1_FastMode();

	//ICR1 value assignment for PWM1 for Servo Motor
	PWM_vSetValue_ICR1_T1_Manual(2499);
	
	//Prescaler for Timer0
	PWM_vSetPreScaler_T0(PRESCALE_64);
	
	//Intitialization for Fast PWM Timer0 for DC Motor
	PWM_vSetMode_T0(FAST_PWM,OC1A_CLR_ON_COMP_UP_COUNT);

	//ADC Initialization
	ADC_vInit_();
	
	//LCD Initialization
	LCD_vInit();
	
	//Initializing the UART 
	UART_vInit();
	
	//LCD Strings to print
	u8 str1[] = "Hello!room Temp" ;
	u8 str2[] = " = ";
	
	//Variable for storing ADC Conversion
	u16 copy_u16Conversion ;
	//Variable for storing ADC Conversion in Celsius
	u16 copy_u16celsius ;
	
	
	//printing "Hello!room Temp = "
	_delay_ms(100);
	LCD_vSendString(str1);
	LCD_vMoveCursor(1,3);
	LCD_vSendString(str2);
	
    while (1) 
    {
		_delay_ms(500);
		copy_u16Conversion = ADC_u16Read_Value();
		
		//Calibrating the sensor by multiplying it by 4.88 then divide it by 10 celsius
		copy_u16celsius = ( (copy_u16Conversion * 4.88) / 10.00 ) ;
		
		//Moving Cursor to Display the Conversion in the 2nd row and 8th column
		LCD_vMoveCursor(1,7);
		LCD_vSendNumber(copy_u16celsius);
		
		//If the temperature is more than the normal room temperature the led will blink
		if(copy_u16celsius >= 25)
			LED_vBlink_Led('d',PIN_NO_7);
		
		//timer for temp conversion
		//isr for uart communication
		//wifi module ==> and servers 
		//usb ttl
		//Putty
		
		//Receive Handshake Signal
		while (UART_u8GetData() != 'R');
		// Send Acknowledgment
		UART_vSendData('A');
		
		//Switch On Actual Data Received
		switch (UART_u8GetData())
		{
 			case '0' :
				//Open the Lights
				LED_vTurnOnLED('c',PIN_NO_2);
 			break;
 			case '1' :
 				//Open the door "Rotate 90 Degrees" ==> 5% duty cycle
				PWM_vSetValue_OCR1A_T1_Manual(187);
 			break;
 			case '2' :
 				//Close the door "Rotate 0 Degrees" ==> 7.5% duty cycle
 				PWM_vSetValue_OCR1A_T1_Manual(125);
			break;
			case '3' :
				//Close the Lights 
				LED_vTurnOffLED('c',PIN_NO_2);
			break;
 			case '4' :
 				//Open the fan 25% duty cycle
 				PWM_v_SetValue_T0_Manual(64);
 			break;
 			case '5' :
 				//Open the fan 50% duty cycle
 				PWM_v_SetValue_T0_Manual(128);
			 break;
 			case '6' :
 				//Open the fan 75% duty cycle
				PWM_v_SetValue_T0_Manual(192);
 			break;
		}
		
		_delay_ms(50);
		
		
				
    }
}

