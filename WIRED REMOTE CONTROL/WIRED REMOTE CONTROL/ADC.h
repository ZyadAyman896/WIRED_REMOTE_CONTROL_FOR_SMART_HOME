/*
 * ADC.h
 *
 * Created: 2/14/2024 9:55:08 PM
 *  Author: Zyad Ayman
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
//void ADC_vInit_(u8 copy_u8ADC_Mode , u8 copy_u8Vref_Mode , u8 copy_u8Prescaler , u8 copy_u8Auto_Triggered_Src);
void ADC_vStart_Conv(void);
//u16 ADC_u16Read_Value(u8 copy_u8Channel , u8 copy_u8Interrupt_Mode);
u16 ADC_u16Read_Value(void);
void ADC_vInit_(void);

#endif /* ADC_H_ */