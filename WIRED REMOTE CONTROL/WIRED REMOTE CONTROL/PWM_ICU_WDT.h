/*
 * PWM_ICU_WDT.h
 *
 * Created: 2/11/2024 9:56:17 PM
 *  Author: Zyad Ayman
 */ 


#ifndef PWM_ICU_WDT_H_
#define PWM_ICU_WDT_H_
#include "DIO.h"
void PWM_vSetMode_T0(u8 copy_u8PwmMode ,u8 copy_u8PwmCompareOUTMode);
void PWM_vSetPreScaler_T0(u8 copy_u8prescaler_val);
void PWM_v_SetValue_T0_Manual(u8 copy_u8Value);
void PWM_vSetValue_OCR1A_T1_Manual(u16 copy_u16Value);
void PWM_vSetValue_OCR1B_T1_Manual(u16 copy_u16Value);
void PWM_vSetValue_ICR1_T1_Manual(u16 copy_u16Value);
void PWM_vInit_T1_FastMode();
#endif /* PWM_ICU_WDT._H_ */