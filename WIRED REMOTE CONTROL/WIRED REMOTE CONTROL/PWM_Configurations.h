/*
 * PWM_Configurations.h
 *
 * Created: 3/5/2024 1:33:56 PM
 *  Author: Zyad Ayman
 */ 


#ifndef PWM_CONFIGURATIONS_H_
#define PWM_CONFIGURATIONS_H_

#define PHASE_PWM 1
#define FAST_PWM 3

//PWM T0

//Compare Output Mode, Fast PWM Mode
#define OC0_DIS 0
#define OC0_CLR_ON_COMP 2
#define OC0_SET_ON_COMP 3

//Compare Output Mode, Phase Correct PWM Mode
#define OC0_DIS 0
#define OC0_CLR_ON_COMP_UP_COUNT 2
#define OC0_SET_ON_COMP_UP_COUNT 3


//duty cycles
#define PWM_Duty_25 25
#define PWM_Duty_50	50
#define PWM_Duty_75	75
#define PWM_Duty_100 100

//MACROS FOR PRESCALER 
#define NO_CLK				0
#define NO_PRESCALER		1
#define PRESCALE_8			2
#define PRESCALE_64			3
#define PRESCALE_256		4
#define PRESCALE_1024		5
#define EXTERNAL_CLK_FALL	6
#define EXTERNAL_CLK_RISING	7



//PWM T1
//PHASE PWM OPTIONS
// FAST PWM OPTIONS
#define PHASE_EIGHT_BITS 9
#define PHASE_NINE_BITS 10
#define PHASE_TEN_BITS 11
#define PHASE_TOP_OCR1A 12
#define PHASE_TOP_ICR1 13
#define PHASE_FREQ_TOP_OCR1A 14
#define PHASE_FREQ_TOP_ICR1 15

// FAST PWM OPTIONS 
#define FAST_EIGHT_BITS 0 
#define FAST_NINE_BITS 1
#define FAST_TEN_BITS 2 
#define FAST_TOP_OCR1A 3
#define FAST_TOP_ICR1 4

//Compare Output Mode, PWM Mode
#define OC1A_DIS 0
#define OC1A_TOGGLE_ON_COMP 1 //BUT OC1B DISCONNECTED 
#define OC1A_CLR_ON_COMP_UP_COUNT 2
#define OC1A_SET_ON_COMP_UP_COUNT 3


#endif /* PWM_CONFIGURATIONS_H_ */