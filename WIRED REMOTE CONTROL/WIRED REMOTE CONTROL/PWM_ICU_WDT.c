/*
 * PWM_ICU_WDT.c
 *
 * Created: 2/11/2024 9:56:03 PM
 *  Author: Zyad Ayman
 */ 
/*
	HOW TO USE THIS DRIVER FOR PWM 
	FIRST THING ==> SETTING PRESCALER FOR T0 OR T1 OR T2 
	SECOND THING ==> CHOOSING THE MODE IF IT IS 1-(FAST PWM) 2-(PHASE CORRECT PWM ) 
	THIRD THING ==>  
	***FOR FAST PWM***
	TAKE CARE OF THE FREQUENCY EQN 
	YOU HAVE 5 MODES 8BIT OR 9BIT OR 10BIT OR FAST OR FAST
	BUT TAKE CARE FROM WHERE THE TOP WILL BE LOADED 
	YOU HAVE 3 OPTIONS FOR THE TOP 1==> FIXED VALUES 2==>YOU LOAD IT MANUALLY IN ICR1 3==>YOU LOAD IT MANUALLY IN OCR1A
	*NOTE* == > YOU DETERMINE THE VALUE OF THE TOP IF YOU WANT TO CHANGE THE FREQUENCY OF THE SIGNAL (IN SAME WORDS YOU CHANGE THE PERIOD TIME OF THE SIGNAL)
	***FOR PHASE CORRECT PWM***
	TAKE CARE OF THE FREQUENCY EQN 
	
	FOURTH THING==> YOU LOAD THE OCR1A VALUE TO DETERMINE THE DUTY CYCLE 
*/
#include "DIO.h"
#include "PWM_Configurations.h"
//valid for phase correct
//waiting for validating fast pwm
void PWM_vSetMode_T0(u8 copy_u8PwmMode ,u8 copy_u8PwmCompareOUTMode)
{
				if(copy_u8PwmMode == PHASE_PWM)
				{
					//PHASE PWM Mode Selection
					CLR_PIN(TCCR0, PIN_NO_3);
					SET_PIN(TCCR0, PIN_NO_6);
					// Output Compare Match Interrupt Enable
					//TIMSK
					CLR_PIN(TIMSK , PIN_NO_0);
					CLR_PIN(TIMSK , PIN_NO_1);
					//TIFR
					CLR_PIN(TIFR , PIN_NO_0);
					CLR_PIN(TIFR , PIN_NO_1);
					switch(copy_u8PwmCompareOUTMode)
					{
						case 0 :
								// OC0 disconnected.
								CLR_PIN(TCCR0,PIN_NO_4);
								CLR_PIN(TCCR0,PIN_NO_5);
						break;
						case 2 :
								//Clear OC0 on compare match when up-counting
								CLR_PIN(TCCR0,PIN_NO_4);
								SET_PIN(TCCR0,PIN_NO_5);
						break;
						case 3 :
								//Set OC0 on compare match when up-counting
								SET_PIN(TCCR0,PIN_NO_4);
								SET_PIN(TCCR0,PIN_NO_5);
						break;
			
					}
				}
				if (copy_u8PwmMode == FAST_PWM)
				{
							//FAST PWM Mode Selection
							SET_PIN(TCCR0, PIN_NO_3);
							SET_PIN(TCCR0, PIN_NO_6);
							// Output Compare Match Interrupt Enable
							//TIMSK
// 							CLR_PIN(TIMSK , PIN_NO_0);
// 							SET_PIN(TIMSK , PIN_NO_1);
// 							//TIFR
// 							CLR_PIN(TIFR , PIN_NO_0);
// 							SET_PIN(TIFR , PIN_NO_1);
					switch(copy_u8PwmCompareOUTMode)
					{
						case 0 :
						// OC0 disconnected.
						CLR_PIN(TCCR0,PIN_NO_4);
						CLR_PIN(TCCR0,PIN_NO_5);
						break;
						case 2 :
						//Clear OC0 on compare match
						CLR_PIN(TCCR0,PIN_NO_4);
						SET_PIN(TCCR0,PIN_NO_5);
						break;
						case 3 :
						//Set OC0 on compare match
						SET_PIN(TCCR0,PIN_NO_4);
						SET_PIN(TCCR0,PIN_NO_5);
						break;
					}
				}
	DIO_vSet_Pin_Direction('b',PIN_NO_3,OUTPUT);
}
//valid
void PWM_vSetPreScaler_T0(u8 copy_u8prescaler_val)
{
		switch(copy_u8prescaler_val)
		{
		case 0: 
		//No clock source
		
		CLR_PIN(TCCR0, PIN_NO_0);
		CLR_PIN(TCCR0,PIN_NO_1);
		CLR_PIN(TCCR0, PIN_NO_2);
		break;
		
		case 1:
		//No Prescaler
		
		SET_PIN(TCCR0, PIN_NO_0);
		CLR_PIN(TCCR0,PIN_NO_1);
		CLR_PIN(TCCR0, PIN_NO_2);
		break;
		case 2:
		// Prescaler = 8
		
		CLR_PIN(TCCR0, PIN_NO_0);
		SET_PIN(TCCR0,PIN_NO_1);
		CLR_PIN(TCCR0, PIN_NO_2);
		break;
		case 3:
		// Prescaler = 64
		
		SET_PIN(TCCR0, PIN_NO_0);
		SET_PIN(TCCR0,PIN_NO_1);
		CLR_PIN(TCCR0, PIN_NO_2);
		break;
		case 4:
		// Prescaler = 256
		
		CLR_PIN(TCCR0, PIN_NO_0);
		CLR_PIN(TCCR0,PIN_NO_1);
		SET_PIN(TCCR0, PIN_NO_2);
		break;
		case 5:
		// Prescaler = 1024
		
		SET_PIN(TCCR0, PIN_NO_0);
		CLR_PIN(TCCR0,PIN_NO_1);
		SET_PIN(TCCR0, PIN_NO_2);
		break;
		case 6 : 
		// External clk src on T0 on Falling edge
		
		CLR_PIN(TCCR0, PIN_NO_0);
		SET_PIN(TCCR0,PIN_NO_1);
		SET_PIN(TCCR0, PIN_NO_2);
		break;
		case 7:
		// External clk src on T0 on Rising edge
		
		SET_PIN(TCCR0, PIN_NO_0);
		SET_PIN(TCCR0,PIN_NO_1);
		SET_PIN(TCCR0, PIN_NO_2);
		break;

		}


}
/*
//to be 
void PWM_vFast_SetValue_T0(u8 copy_u8DutyCycle ,u8 copy_u8clk)
{
	switch (copy_u8DutyCycle)
	{
		case 1:
				
				WRITE_REG(OCR0,)
		break;
		case 2:
		
		break;
		case 3:
		
		break;
		case 4:
		
		break;
	}
}
//to be 
void PWM_vPhase_SetValue_T0(u8 copy_u8DutyCycle ,u8 copy_u8clk)
{
	u8 value = 0 , Ontime = 0 ;
	switch (copy_u8DutyCycle)
	{
		case 25:
		Ontime = 0.25 * 
		value = (TIMER0_RESOLUTION - 1 ) - Ontime ;
		WRITE_REG(OCR0,value);
		break;
		case 50:
		
		break;
		case 75:
		
		break;
		case 100:
		
		break;
	}	
}
*/
//finished
//valid
void PWM_v_SetValue_T0_Manual(u8 copy_u8Value)
{
	//on time = duty cylce * 510
	//if duty cycle is 90% so ==> put it 0.9
	//OCR0 = (timer res. - 1) - (on time / 2)
	WRITE_REG(OCR0,copy_u8Value);
}
/*
//to be corrected
void PWM_vFast_SetValue_T0_Manual(u8 copy_u8Value)
{
	//OCR0 = (timer res. - 1) - (on time / 2)
	WRITE_REG(OCR0,copy_u8Value);
}
*/

/******************************************/

//PWM TIMER1 

void PWM_vInit_T1_FastMode()
{
	//we made it CLR on compare to get the desired correct signal for servo 
	DIO_vSet_Pin_Direction('d',PIN_NO_5,OUTPUT); //have been checked // Make OC1A pin as output
	TCNT1 = 0 ;			//checked  //Set timer1 count zero
	ICR1 = 2499 ; //for frequency 50Hz  // Set TOP count for timer1 in ICR1 register 
	//Set Fast PWM, TOP in ICR1, Clr OC1A on compare match, clk/64
	TCCR1A = (1<<PIN_NO_7) |  (1<<PIN_NO_1) ;
	TCCR1B = (1<<PIN_NO_3) | (1<<PIN_NO_4) | (1<<PIN_NO_0) | (1<<PIN_NO_1) ;

}

void PWM_vSetValue_OCR1A_T1_Manual(u16 copy_u16Value)
{
	//WRITE_REG(OCR1A,copy_u16Value);
	OCR1A = copy_u16Value ;
}

void PWM_vSetValue_OCR1B_T1_Manual(u16 copy_u16Value)
{
	//WRITE_REG(OCR1B,copy_u16Value);
	OCR1B = copy_u16Value ;
}
void PWM_vSetValue_ICR1_T1_Manual(u16 copy_u16Value)
{
	//WRITE_REG(ICR1,copy_u16Value);
	ICR1 = copy_u16Value ;
}

