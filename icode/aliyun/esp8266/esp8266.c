#include "esp8266.h"

uint8_t esp8266_send_cmd(char *cmd, char *ack, uint16_t waittime) //ESP8266发送指令（底层函数）
{
	uint8_t res = 0;
	USART_RX_STA = 0;
	memset(USART_RX_BUF,0,USART_REC_LEN); //将串口3的缓存空间清0
	usart_printf(&huart3, "%s\r\n", cmd);
	if(waittime) //需要等待应答
	{
		while(--waittime) //等待倒计时
		{
			HAL_Delay(10);//HAL库延时函数
			if(USART_RX_STA&0x8000) //接收到期待的应答结果
			{
				if(esp8266_check_cmd((uint8_t *)ack))
				{
					break; //得到有效数据
				}
				USART_RX_STA=0; //串口3标志位清0
			}
		}
		if(waittime==0)res=1;
	}
	return res;
}

uint8_t* esp8266_check_cmd(uint8_t *str) //ESP8266检查指令（底层函数）
{
	char *strx=0;
	if(USART_RX_STA&0X8000) //接收到一次数据了
	{
		USART_RX_BUF[USART_RX_STA&0X7FFF] = 0; //添加结束符
		printf("%s\r\n",(char*)USART_RX_BUF);
		strx=strstr((const char*)USART_RX_BUF,(const char*)str);
	}
	return (uint8_t*)strx;
}

uint8_t esp8266_quit_trans(void)
{
	while((USART3->SR&0X40)==0);
	USART3->DR='+';      
	HAL_Delay(15);
	while((USART3->SR&0X40)==0);
	USART3->DR='+';      
	HAL_Delay(15);
	while((USART3->SR&0X40)==0);
	USART3->DR='+';      
	HAL_Delay(500);
	return esp8266_send_cmd("AT","OK",200);
}

uint8_t esp8266_Connect_IOTServer(void)
{
	HAL_Delay(100);

	esp8266_send_cmd("AT","OK",50);
	if(esp8266_quit_trans())
	{
		usart_printf(&huart1,"quit_trans error\r\n");
		return 6;
	}

	if(esp8266_send_cmd("ATE0","OK",50))
	{
		usart_printf(&huart1,"send ATE0 error\r\n");
		return 1;
	}
	
	if(esp8266_send_cmd("AT","OK",50))
	{
		usart_printf(&huart1,"send AT error\r\n");
		return 1;
	}
	
	if(esp8266_send_cmd("AT+CWMODE=1","OK",50))
	{
		usart_printf(&huart1,"send AT+CWMODE=1 error\r\n");
		return 1;
	}
	
	if(esp8266_send_cmd("AT+RST","OK",50))
	{
		usart_printf(&huart1,"send AT+RST error\r\n");
		return 2;
	}
	
	HAL_Delay(3000);

	if(esp8266_send_cmd("AT+CWAUTOCONN=0","OK",50))
	{
		usart_printf(&huart1,"send AT+CWAUTOCONN=0 error\r\n");
		return 3;
	}
	
	if(esp8266_Connect_AP())
	{
		usart_printf(&huart1,"Connect_AP error\r\n");
		return 4;
	}
	
	HAL_Delay(4000);


	if(esp8266_send_cmd("AT+CWDHCP=1,1","OK",100))
	{
		usart_printf(&huart1,"AT+CWDHCP=1,1 error\r\n");
		return 7;
	}


	if(esp8266_send_cmd("AT+CIPMUX=0","OK",100))
	{
		usart_printf(&huart1,"AT+CIPMUX=0 error\r\n");
		return 7;
	}

	if(esp8266_Connect_Server())
	{
		usart_printf(&huart1,"connect server error\r\n");
		return 8;
	}
	

	if(esp8266_quit_trans())
	{
		usart_printf(&huart1,"quit_trans error\r\n");
		return 6;
	}
	
	if(esp8266_send_cmd("AT+CIPMODE=1","OK",50))
	{
		usart_printf(&huart1,"AT+CIPMODE=1 error\r\n");
		return 6;
	}

	if(esp8266_send_cmd("AT+CIPSEND","OK",1000))
	{
		usart_printf(&huart1,"AT+CIPSEND error\r\n");
		return 9;
	}
	
	USART_RX_STA = 0;
	memset(USART_RX_BUF,0,USART_REC_LEN);
	return 0;
}

uint8_t esp8266_Connect_AP()
{
	uint8_t i=10;
	char *p = (char*)malloc(50);
	sprintf((char*)p,"AT+CWJAP=\"%s\",\"%s\"",SSID,PASS);
	while(esp8266_send_cmd(p,"WIFI GOT IP",1000) && i)
	{
		i--;
	}
	free(p);
	if(i) return 0;
	else return 1;
}
uint8_t esp8266_Connect_Server() //ESP8266连接到服务器
{
	uint8_t i=10;
	char *p = (char*)malloc(50);//分配存储空间的指针
	sprintf((char*)p,"AT+CIPSTART=\"TCP\",\"%s\",\%s",IOT_DOMAIN_NAME,IOT_PORTNUM);
	while(esp8266_send_cmd(p,"CONNECT",1000) && i)
	{
//		printf("链接服务器失败，尝试重新连接\r\n");
		i--;
	}
	free(p);//释放分配的空间和指针
	if(i)return 0;//执行成功返回0
	else return 1;//执行失败返回1
}
