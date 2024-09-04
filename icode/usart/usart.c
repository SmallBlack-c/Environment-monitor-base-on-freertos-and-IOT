/*
 * usart1.c
 *
 *  Created on: Oct 20, 2021
 *      Author: Administrator
 */

#include "usart.h"

uint8_t USART_RX_BUF[USART_REC_LEN];
uint16_t USART_RX_STA=0;
uint8_t USART_NewData;

void  HAL_UART_RxCpltCallback(UART_HandleTypeDef  *huart)
{
	if(huart ==&huart3)
	{
		if(USART_RX_STA<USART_REC_LEN)
		{
			__HAL_TIM_SET_COUNTER(&htim2,0);
			if(USART_RX_STA==0)
			{
				__HAL_TIM_ENABLE(&htim2);
			}
			USART_RX_BUF[USART_RX_STA++] = USART_NewData;
		}else
		{
			USART_RX_STA|=0x8000;
		}

		HAL_UART_Receive_IT(&huart3,(uint8_t *)&USART_NewData,1);
	}
}

void  usart_printf(UART_HandleTypeDef  *huart, char *fmt, ...)
{
	char buff[USART_REC_LEN+1];
	uint16_t i=0;
	va_list arg_ptr;
	va_start(arg_ptr, fmt);
	vsnprintf(buff, USART_REC_LEN+1, fmt, arg_ptr);
	i=strlen(buff);
	if(strlen(buff)>USART_REC_LEN)i=USART_REC_LEN;
	HAL_UART_Transmit(huart,(uint8_t *)buff,i,0xffff);
	va_end(arg_ptr);
}
