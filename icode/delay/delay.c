/*
 * delay.c
 *
 *  Created on: Oct 21, 2021
 *      Author: Administrator
 */

#include "delay.h"

void delay_us(uint32_t us)
{
    uint32_t delay = (HAL_RCC_GetHCLKFreq() / 8000000 * us);
    while (delay--);
}
