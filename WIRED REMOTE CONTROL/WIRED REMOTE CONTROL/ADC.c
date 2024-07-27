/*
 * ADC.c
 *
 * Created: 2/14/2024 9:55:21 PM
 *  Author: Zyad Ayman
 */ 
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "DIO.h"
/*#include "EXTI.h"*/
#include "Utils.h"
#include "Registers.h"
#include "ADC_CONFIGURATIONS.h"
#include <util/delay.h>



/*
void ADC_vInit_(u8 copy_u8ADC_Mode , u8 copy_u8Vref_Mode , u8 copy_u8Prescaler , u8 copy_u8Auto_Triggered_Src)
{
	switch (copy_u8Vref_Mode)
	{
		case 0 :
		// Vref ==> AREF , Internal Vref off
			CLR_PIN(ADMUX,PIN_NO_6);
			CLR_PIN(ADMUX,PIN_NO_7);
		break;
		case 1 :
		// Vref ==> AVCC with external capacitor at AREF pin
			SET_PIN(ADMUX,PIN_NO_6);
			CLR_PIN(ADMUX,PIN_NO_7);
		break;
		case 2 :
		// Vref ==> Internal 2.56V Voltage Reference with external capacitor at AREF pin
			SET_PIN(ADMUX,PIN_NO_6);
			SET_PIN(ADMUX,PIN_NO_7);
		break;		
	}

	
	//ADLAR ==> Adjust RIGHT
	CLR_PIN(ADMUX,PIN_NO_5);
	//IF YOU WANT TO MAKE IT Adjust LEFT
	//UNCOMMENT THE TWO LINES BELOW
	//ADLAR ==> Adjust RIGHT
	//SET_PIN(ADMUX,PIN_NO_5);	
	
	switch(copy_u8Prescaler)
	{
		case 0 :
			//PreScaler == 2
			CLR_PIN(ADCSRA,PIN_NO_0);
			CLR_PIN(ADCSRA,PIN_NO_1);
			CLR_PIN(ADCSRA,PIN_NO_2);
		break;
		case 1 :
			//PreScaler == 2
			SET_PIN(ADCSRA,PIN_NO_0);
			CLR_PIN(ADCSRA,PIN_NO_1);
			CLR_PIN(ADCSRA,PIN_NO_2);
		break;
		case 2 :
			//PreScaler == 4
			CLR_PIN(ADCSRA,PIN_NO_0);
			SET_PIN(ADCSRA,PIN_NO_1);
			CLR_PIN(ADCSRA,PIN_NO_2);
		break;
		case 3 :
			//PreScaler == 8
			SET_PIN(ADCSRA,PIN_NO_0);
			SET_PIN(ADCSRA,PIN_NO_1);
			CLR_PIN(ADCSRA,PIN_NO_2);
		break;	
		case 4 :
			//PreScaler == 16
			CLR_PIN(ADCSRA,PIN_NO_0);
			CLR_PIN(ADCSRA,PIN_NO_1);
			SET_PIN(ADCSRA,PIN_NO_2);
		break;
		case 5 :
			//PreScaler == 32
			SET_PIN(ADCSRA,PIN_NO_0);
			CLR_PIN(ADCSRA,PIN_NO_1);
			SET_PIN(ADCSRA,PIN_NO_2);
		break;
		case 6 :
			//PreScaler == 64
			CLR_PIN(ADCSRA,PIN_NO_0);
			SET_PIN(ADCSRA,PIN_NO_1);
			SET_PIN(ADCSRA,PIN_NO_2);
		break;
		case 7 :
			//PreScaler == 128
			SET_PIN(ADCSRA,PIN_NO_0);
			SET_PIN(ADCSRA,PIN_NO_1);
			SET_PIN(ADCSRA,PIN_NO_2);
		break;	
	}
	

	
	if (copy_u8ADC_Mode == ADC_Single_Conv)
	{
			//Single Conversion NOT AUTO TRIGGER
			CLR_PIN(ADCSRA,PIN_NO_5);
	}
	else if (copy_u8ADC_Mode == ADC_Auto_Triggerd_Conv)
	{
		//AUTO TRIGGERED IS ENABLED 
		SET_PIN(ADCSRA,PIN_NO_5);
	
		
		switch (copy_u8Auto_Triggered_Src)
		{
			//Free Running mode
			case 0 :
			CLR_PIN(SFIOR,PIN_NO_5);
			CLR_PIN(SFIOR,PIN_NO_6);
			CLR_PIN(SFIOR,PIN_NO_7);
			break;
			// Analog Comparator
			case 1 :
			SET_PIN(SFIOR,PIN_NO_5);
			CLR_PIN(SFIOR,PIN_NO_6);
			CLR_PIN(SFIOR,PIN_NO_7);
			break;
			// External Interrupt Request 0
			case 2 :
			CLR_PIN(SFIOR,PIN_NO_5);
			SET_PIN(SFIOR,PIN_NO_6);
			CLR_PIN(SFIOR,PIN_NO_7);
			break;
			// Timer/Counter0 Compare Match
			case 3 :
			SET_PIN(SFIOR,PIN_NO_5);
			SET_PIN(SFIOR,PIN_NO_6);
			CLR_PIN(SFIOR,PIN_NO_7);
			break;
			// Timer/Counter0 Overflow
			case 4 :
			CLR_PIN(SFIOR,PIN_NO_5);
			CLR_PIN(SFIOR,PIN_NO_6);
			SET_PIN(SFIOR,PIN_NO_7);
			break;
			//Timer/Counter Compare Match B
			case 5 :
			SET_PIN(SFIOR,PIN_NO_5);
			CLR_PIN(SFIOR,PIN_NO_6);
			SET_PIN(SFIOR,PIN_NO_7);
			break;
			// Timer/Counter1 Overflow
			case 6 :
			CLR_PIN(SFIOR,PIN_NO_5);
			SET_PIN(SFIOR,PIN_NO_6);
			SET_PIN(SFIOR,PIN_NO_7);
			break;
			// Timer/Counter1 Capture Event
			case 7 :
			SET_PIN(SFIOR,PIN_NO_5);
			SET_PIN(SFIOR,PIN_NO_6);
			SET_PIN(SFIOR,PIN_NO_7);
			break;
			
		}
		

	}

	//ADC ENABLE
	SET_PIN(ADCSRA,PIN_NO_7);
	
	
}
*/



void ADC_vStart_Conv(void)
{
		//NOTE IF IT IS SINGLE CONV
		//write this bit to one to start each conversion
		//IF IT IS AUTO TRIGGERED MODE
		//write this bit to one to start the first conversion
		//		 ||
		//		  v	
		//STARTING CONVERSION
	SET_PIN(ADCSRA,PIN_NO_6);
	
}


/*
u16 ADC_u16Read_Value(u8 copy_u8Channel , u8 copy_u8Interrupt_Mode , u8 copy_u8Pos_Channel_No_ , u8 copy_u8Neg_Channel_No_)
{
	//CHOOSING ADC CHANNEL   NNNNNNN
	ADMUX &= 0b11100000 ;
	ADMUX |= copy_u8Channel ;
	//Making channel DIRECTION IS INPUT 
	if(copy_u8Channel <= SEVEN )
	{
		DIO_vSet_Pin_Direction('A' ,copy_u8Channel , INPUT);
	}
	else if (copy_u8Channel > SEVEN && copy_u8Channel <= 29 )
	{
		DIO_vSet_Pin_Direction('A' ,copy_u8Pos_Channel_No_ , INPUT);//Positive channel
		DIO_vSet_Pin_Direction('A' ,copy_u8Neg_Channel_No_ , INPUT);//Negative channel
	}

	ADC_vStart_Conv();
	
	//WAITING UNTIL FINISHING
	while(READ_PIN(ADCSRA,PIN_NO_4) == ZERO){}
	if(copy_u8Interrupt_Mode == ADC_ENABLE_INTERRUPT)
	{
		//Setting I-th Bit in SREG 
		//That enables the global interrupt
		EXTI_vSet_Global_Interrupt();
		//ADIE: ADC Interrupt Enable	
		SET_PIN(ADCSRA,PIN_NO_3);
	}
	//CLEARING THE FLAG BY SETTING THE BIT 4  – ADIF: ADC Interrupt Flag
	SET_PIN(ADCSRA,PIN_NO_4);
	
	return ADC ;
	
}
*/
u16 ADC_u16Read_Value()
{
	//starting conversion
	ADCSRA |= (1<<PIN_NO_6) ;
	//WAITING UNTIL FINISHING
	while(READ_PIN(ADCSRA,PIN_NO_4) == ZERO);
	//CLEARING THE FLAG BY SETTING THE BIT 4  – ADIF: ADC Interrupt Flag
	SET_PIN(ADCSRA,PIN_NO_4);	
	_delay_us(10);
	//returning the value of adc
	return ADC ;
}

void ADC_vInit_()
{
   	
	//making port a pin0 is input which is ADC0
   	DIO_vSet_Pin_Direction('a',PIN_NO_0,INPUT);	
	#if ADC_MODE == ADC_Auto_Triggerd_Conv
		ADCSRA = (1<<PIN_NO_7) | (1<<PIN_NO_5) | (1<<PIN_NO_2) | (1<<PIN_NO_1) | (1<<PIN_NO_0) ; /* Enable ADC, MODE ,  FCPU/128 = 62.5KHZ  */
		ADMUX = (1<<PIN_NO_6);			/* Vref: AVCC , ADLAR = 0 ,   */
		//choosing channel zero
		CLR_PIN(ADMUX,PIN_NO_0);
		CLR_PIN(ADMUX,PIN_NO_1);
		CLR_PIN(ADMUX,PIN_NO_2);
		CLR_PIN(ADMUX,PIN_NO_3);
		CLR_PIN(ADMUX,PIN_NO_4);
		#if ADC_AUTOTRIGGER_MODE == ADC_FREE_RUNING_MODE
			CLR_PIN(SFIOR,PIN_NO_5);
			CLR_PIN(SFIOR,PIN_NO_6);
			CLR_PIN(SFIOR,PIN_NO_7);
		#endif
	#elif ADC_MODE == ADC_Single_Conv
		ADCSRA = (1<<PIN_NO_7)  | (1<<PIN_NO_2) | (1<<PIN_NO_1) | (1<<PIN_NO_0) ; /* Enable ADC, MODE ,  FCPU/128 = 62.5KHZ  */
		ADMUX = (1<<PIN_NO_6);			/* Vref: AVCC , ADLAR = 0 ,   */
		//choosing channel zero
		CLR_PIN(ADMUX,PIN_NO_0);
		CLR_PIN(ADMUX,PIN_NO_1);
		CLR_PIN(ADMUX,PIN_NO_2);
		CLR_PIN(ADMUX,PIN_NO_3);
		CLR_PIN(ADMUX,PIN_NO_4);	
	#endif
			
	

	
}
