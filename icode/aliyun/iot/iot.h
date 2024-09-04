#ifndef IOT_IOT_H
#define IOT_IOT_H

#include "stm32f1xx_hal.h"
#include "string.h"
#include "stdlib.h"

#include "../../aliyun/mqtt/MQTTPacket.h"
#include "../../aliyun/mqtt/transport.h"
#include "../../usart/usart.h"

#define  PRODUCTKEY           "ha7r5ObMTao"
#define  PRODUCTKEY_LEN       strlen(PRODUCTKEY)
#define  DEVICENAME			 "ESP8266"
#define  DEVICENAME_LEN       strlen(DEVICENAME)
#define  DEVICESECRE          "9ef9a1fc8f8f3cc1ec377375adf95a85"
#define  DEVICESECRE_LEN      strlen(DEVICESECRE)

#define  TOPIC_SUBSCRIBE		"/ha7r5ObMTao/ESP8266/user/get"
#define  TOPIC_QOS				0
#define  MSGID					1
 
#define  TOPIC_PUBLISH			"/ha7r5ObMTao/ESP8266/user/update/error"

#define  MQTTVERSION			4
#define  KEEPALIVEINTERVAL		120

extern uint16_t buflen;
extern unsigned char buf[200];

uint8_t IOT_connect(void);
void IOT_ping(void);
uint8_t IOT_subscribe(void);
uint8_t IOT_publish(char* payload);

#endif


