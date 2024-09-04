# 项目介绍
项目：基于freertos和IOT的环境云监控  
云平台：阿里云物联网平台  
芯片：STM32F103C8  
外设模块：光敏电阻，DHT11温湿度传感器，ESP8266WiFi无线模块  
开发平台：STM32CubeIDE  
三方库：HAL  
通信协议：MQTT，ADC，UART  
# freertos
任务：  
| 任务 | 函数 | 栈 | 优先级 | 内容 |
| --- | --- | --- | --- | --- |
| defaultTask | StartDefaultTask | 128 | osPriorityNormal | 默认任务，反转LED1，用于监测系统是否在运行 |
| light | StartTask02 | 128 | osPriorityNormal | 使用ADC读取光敏电阻的值 |
| dht11 | StartTask03 | 128 | osPriorityNormal | 读取DHT11传感器的值 |
| wifi | StartTask04 | 128 | osPriorityNormal | 将环境数据发送到云端 |
