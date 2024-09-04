#ifndef ESP8266_ESP8266_H
#define ESP8266_ESP8266_H

#include "stm32f1xx_hal.h"
#include "string.h"
#include "stdlib.h"
#include "../../usart/usart.h"

#define SSID "TP-LINK_6266"
#define PASS "asdfghjkl"

#define IOT_DOMAIN_NAME "iot-06z00bp3e5sb25e.mqtt.iothub.aliyuncs.com"
#define IOT_PORTNUM 	"1883"

uint8_t esp8266_send_cmd(char *cmd, char *ack, uint16_t waittime);
uint8_t esp8266_Connect_IOTServer(void);
uint8_t esp8266_Connect_AP(void);
uint8_t esp8266_quit_trans(void);
uint8_t esp8266_Connect_Server();
uint8_t* esp8266_check_cmd(uint8_t *str);

#endif
