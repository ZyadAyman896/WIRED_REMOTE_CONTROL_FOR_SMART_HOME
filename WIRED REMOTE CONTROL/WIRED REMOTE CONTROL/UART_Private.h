/*
 * UART_Private.h
 *
 * Created: 4/13/2024 3:10:07 PM
 *  Author: Zyad Ayman
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


//UART
#define UDR *((volatile u8 *)0x2C)
#define UCSRB *((volatile u8 *)0x2A)
#define UCSRA *((volatile u8 *)0x2B)
#define UBRRL *((volatile u8 *)0x29)
#define UBRRH *((volatile u8 *)0x40)
#define USCRC *((volatile u8 *)0x40)


#endif /* UART_PRIVATE_H_ */