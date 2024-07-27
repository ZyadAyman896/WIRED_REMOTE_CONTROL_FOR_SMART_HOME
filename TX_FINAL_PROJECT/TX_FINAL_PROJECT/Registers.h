/*
 * Registers.h
 *
 * Created: 11/3/2023 1:03:58 PM
 *  Author: Zyad Ayman
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

//DIO

#define PORTA *((volatile char *)0x3B)
#define PINA *((volatile char *)0x39)
#define DDRA *((volatile char *)0x3A)
#define PORTB *((volatile char *)0x38)
#define PINB *((volatile char *)0x36)
#define DDRB *((volatile char *)0x37)
#define PORTC *((volatile char *)0x35)
#define PINC *((volatile char *)0x33)
#define DDRC *((volatile char *)0x34)
#define PORTD *((volatile char *)0x32)
#define PIND *((volatile char *)0x30)
#define DDRD *((volatile char *)0x31)

//**********************************************


//INTERRUPTS

//MCUCR  MCU Control Register
#define MCUCR *((volatile u8*)0x55)
//MCUCSR MCU Control and Status Register
#define MCUCSR *((volatile u8*)0x54)
//General Interrupt Control Register � GICR
#define GICR *((volatile u8*)0x5B)
//General Interrupt Flag Register � GIFR
#define GIFR *((volatile u8*)0x5A)
// Global Interrupt Register SREG
//we deal with I-Bit to enable or disable global interrupt enable
#define SREG *((volatile u8*)0x5F)

//*******************************

//TIMERS
#define  TIMSK *((volatile u8*)0x59)
#define  TIFR *((volatile u8*)0x58)
// TIMER0

#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define OCR0 *((volatile u8*)0x5C)


//TIMER1

//Timer/Counter1 Control Register A � TCCR1A
#define	TCCR1A	*((volatile u8*)0x4F)
//Timer/Counter1 Control Register B � TCCR1B
#define	TCCR1B	*((volatile u8*)0x4E)
//Timer/Counter1 � TCNT1H and TCNT1L

#define	TCNT1L	*((volatile u8*)0x4C)

#define	TCNT1H *((volatile u8*)0x4D)

#define	TCNT1 *((volatile u16*)0x4C)

//Output Compare Register 1 A � OCR1AH and OCR1AL
#define	OCR1AL *((volatile u8*)0x4A)
#define	OCR1AH *((volatile u8*)0x4B)
#define	OCR1A *((volatile u16*)0x4A)

//Output Compare Register 1 B � OCR1BH and OCR1BL
#define	OCR1BL *((volatile u8*)0x48)
#define	OCR1BH *((volatile u8*)0x49)
#define	OCR1B *((volatile u16*)0x48)

//Input Capture Register 1 � ICR1H and ICR1L
#define	ICR1L *((volatile u8*)0x46)
#define	ICR1H *((volatile u8*)0x47)
#define	ICR1 *((volatile u16*)0x46)

//



//TIMER2

//Timer/Counter Control Register � TCCR2
#define	TCCR2 *((volatile u8*)0x45)
//Timer/Counter Register � TCNT2
#define	TCNT2 *((volatile u8*)0x44)
//Output Compare Register � OCR2
#define	OCR2 *((volatile u8*)0x43)
//Asynchronous Status Register � ASSR
#define	ASSR *((volatile u8*)0x42)

//*********************************

//ADC REGISTERS
//ADC Multiplexer Selection Register - ADMUX

//REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0

#define ADMUX *((volatile u8*)0x27)

//ADC Control and Status Register A � ADCSRA

#define ADCSRA *((volatile u8*)0x26)

//The ADC Data Register � ADCL and ADCH

#define ADCL *((volatile u8*)0x24)

#define ADCH *((volatile u8*)0x25)

#define ADC  *((volatile u16*)0x24)

//Special FunctionIO Register � SFIOR

#define SFIOR *((volatile u8*)0x50)


//UART
#define UDR *((volatile u8 *)0x2C)
#define UCSRB *((volatile u8 *)0x2A)
#define UCSRA *((volatile u8 *)0x2B)
#define UBRRL *((volatile u8 *)0x29)
#define UBRRH *((volatile u8 *)0x40)
#define USCRC *((volatile u8 *)0x40)




#endif /* REGISTERS_H_ */