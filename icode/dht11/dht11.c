/*
 * dht11.c
 *
 *  Created on: Oct 21, 2021
 *      Author: Administrator
 */

/*
*/

/*
*/



#include "dht11.h"
#include "main.h"

void DHT11_IO_OUT (void){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DHT11_DA_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void DHT11_IO_IN (void){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DHT11_DA_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void DHT11_RST (void){
	DHT11_IO_OUT();
	HAL_GPIO_WritePin(GPIOB,DHT11_DA_Pin, GPIO_PIN_RESET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(GPIOB,DHT11_DA_Pin, GPIO_PIN_SET);
	delay_us(30);
}

uint8_t Dht11_Check(void){
	uint8_t retry=0;
    DHT11_IO_IN();
    while (HAL_GPIO_ReadPin(GPIOB,DHT11_DA_Pin)&&retry<100){
        retry++;
        delay_us(1);
    }
    if(retry>=100)return 1; else retry=0;
    while (!HAL_GPIO_ReadPin(GPIOB,DHT11_DA_Pin)&&retry<100){
        retry++;
        delay_us(1);
    }
    if(retry>=100)return 1;
    return 0;
}

uint8_t Dht11_ReadBit(void){
	uint8_t retry=0;
    while(HAL_GPIO_ReadPin(GPIOB,DHT11_DA_Pin)&&retry<100){
        retry++;
        delay_us(1);
    }
    retry=0;
    while(!HAL_GPIO_ReadPin(GPIOB,DHT11_DA_Pin)&&retry<100){
        retry++;
        delay_us(1);
    }
    delay_us(40);
    if(HAL_GPIO_ReadPin(GPIOB,DHT11_DA_Pin))return 1; else return 0;
}

uint8_t Dht11_ReadByte(void){
	uint8_t i,dat;
    dat=0;
    for (i=0;i<8;i++){
        dat<<=1;
        dat|=Dht11_ReadBit();
    }
    return dat;
}

uint8_t DHT11_Init (void){
	DHT11_RST();
	return Dht11_Check();
}

uint8_t DHT11_ReadData(uint8_t *h){
	uint8_t buf[5];
	uint8_t i;
    DHT11_RST();
    if(Dht11_Check()==0){
        for(i=0;i<5;i++){
            buf[i]=Dht11_ReadByte();
        }
        if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4]){
            *h=buf[0];
			h++;
            *h=buf[2];
        }
    }else return 1;
    return 0;
}
