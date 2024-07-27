
/*
 * PWM_Private.h
 *
 * Created: 4/13/2024 3:21:43 PM
 *  Author: Zyad Ayman
 */ 
#ifndef PWM_PRIVATE
#define PWM_PRIVATE


//TIMERS
#define  TIMSK *((volatile u8*)0x59)
#define  TIFR *((volatile u8*)0x58)
// TIMER0

#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define OCR0 *((volatile u8*)0x5C)

//TIMER1

//Timer/Counter1 Control Register A ? TCCR1A
#define	TCCR1A	*((volatile u8*)0x4F)
//Timer/Counter1 Control Register B ? TCCR1B
#define	TCCR1B	*((volatile u8*)0x4E)
//Timer/Counter1 ? TCNT1H and TCNT1L

#define	TCNT1L	*((volatile u8*)0x4C)

#define	TCNT1H *((volatile u8*)0x4D)

#define	TCNT1 *((volatile u16*)0x4C)

//Output Compare Register 1 A ? OCR1AH and OCR1AL
#define	OCR1AL *((volatile u8*)0x4A)
#define	OCR1AH *((volatile u8*)0x4B)
#define	OCR1A *((volatile u16*)0x4A)

//Output Compare Register 1 B ? OCR1BH and OCR1BL
#define	OCR1BL *((volatile u8*)0x48)
#define	OCR1BH *((volatile u8*)0x49)
#define	OCR1B *((volatile u16*)0x48)

//Input Capture Register 1 ? ICR1H and ICR1L
#define	ICR1L *((volatile u8*)0x46)
#define	ICR1H *((volatile u8*)0x47)
#define	ICR1 *((volatile u16*)0x46)

//



#endif //PWM_PRIVATE