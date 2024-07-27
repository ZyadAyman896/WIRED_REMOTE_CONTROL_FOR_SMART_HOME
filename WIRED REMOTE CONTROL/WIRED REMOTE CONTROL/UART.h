/*
 * UART.h
 *
 * Created: 3/6/2024 9:39:09 PM
 *  Author: Zyad Ayman
 */ 


#ifndef UART_H_
#define UART_H_

void UART_vInit(void);
void UART_vSendData(u8 copy_u8Data);
void UART_vSendString(Pu8 Ptr);
u8 UART_u8GetData(void);
void UART_vDisable_Flow_Control();
void UART_vEnable_Flow_Control();

#endif /* UART_H_ */