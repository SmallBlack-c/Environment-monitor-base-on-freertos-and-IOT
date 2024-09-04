#include "iot.h"
#include "../hmac/utils_hmac.h"

uint16_t buflen=200;
unsigned char buf[200];

char ClientID[128];
uint8_t ClientID_len;

char Username[128];
uint8_t Username_len;

char Password[128];
uint8_t Password_len;

uint8_t IOT_connect()
{
	uint16_t a;
	uint32_t len;
	char temp[128];
	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
	buflen = sizeof(buf);
	memset(buf,0,buflen);
	memset(ClientID,0,128);
	sprintf(ClientID,"%s|securemode=3,signmethod=hmacsha1|",DEVICENAME);
	memset(Username,0,128);
	sprintf(Username,"%s&%s",DEVICENAME,PRODUCTKEY);

	Username_len = strlen(Username);

	memset(temp,0,128);
	sprintf(temp,"clientId%sdeviceName%sproductKey%s",DEVICENAME,DEVICENAME,PRODUCTKEY);
	utils_hmac_sha1(temp,strlen(temp),Password,DEVICESECRE,DEVICESECRE_LEN);
	Password_len = strlen(Password);

	usart_printf(&huart1,"ClientId:%s\r\n",ClientID);
	usart_printf(&huart1,"Username:%s\r\n",Username);
	usart_printf(&huart1,"Password:%s\r\n",Password);

	
	data.MQTTVersion = MQTTVERSION;
	data.clientID.cstring = ClientID;
	data.keepAliveInterval = KEEPALIVEINTERVAL;
	data.cleansession = 1;
	data.username.cstring = Username;
	data.password.cstring = Password;

	len = MQTTSerialize_connect(buf, buflen, &data);
	transport_sendPacketBuffer(0,buf, len);

	unsigned char sessionPresent, connack_rc;
	a=0;
	while(MQTTPacket_read(buf, buflen, transport_getdata) != CONNACK || a>1000)
	{
		HAL_Delay(10);
		a++;
	}
	if(a>1000)NVIC_SystemReset();

	while(MQTTDeserialize_connack(&sessionPresent, &connack_rc, buf, buflen) != 1 || connack_rc != 0);
	usart_printf(&huart1,"connected successfully! \r\n");
	return 0;
}

void IOT_ping(void)
{
	uint32_t len;
	len = MQTTSerialize_pingreq(buf, buflen);
	transport_sendPacketBuffer(0, buf, len);
	HAL_Delay(200);
}

uint8_t IOT_subscribe(void)
{
	uint32_t len;
	int req_qos = TOPIC_QOS;
	MQTTString topicString = MQTTString_initializer;
	topicString.cstring = TOPIC_SUBSCRIBE;
	len = MQTTSerialize_subscribe(buf, buflen, 0, MSGID, 1, &topicString, &req_qos);
	transport_sendPacketBuffer(0, buf, len);
	HAL_Delay(100);
	if(MQTTPacket_read(buf, buflen, transport_getdata) == SUBACK)
	{
		unsigned short submsgid;
		int subcount;
		int granted_qos;
		MQTTDeserialize_suback(&submsgid, 1, &subcount, &granted_qos, buf, buflen);
		if(granted_qos != 0)
		{
			return 0;
		}
	};
	return 1;
}

uint8_t IOT_publish(char* payload)
{
	uint32_t len;
	MQTTString topicString = MQTTString_initializer;
	topicString.cstring = TOPIC_PUBLISH;
	int payloadlen = strlen(payload);
	len = MQTTSerialize_publish(buf, buflen, 0, 0, 0, 0, topicString,
								(unsigned char*)payload, payloadlen);
	transport_sendPacketBuffer(0, buf, len);
	HAL_Delay(100);
	return 1;
}

