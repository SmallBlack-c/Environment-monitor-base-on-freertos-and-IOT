/*
 * usart1.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Administrator
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdarg.h>


extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim2;

#define USART_REC_LEN  200

extern uint8_t  USART_RX_BUF[USART_REC_LEN];
extern uint16_t USART_RX_STA;
extern uint8_t USART_NewData;

void  HAL_UART_RxCpltCallback(UART_HandleTypeDef  *huart);
void  usart_printf(UART_HandleTypeDef  *huart, char *fmt, ...);

#endif /* INC_USART_H_ */
