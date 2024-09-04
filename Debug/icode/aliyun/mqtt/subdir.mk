################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../icode/aliyun/mqtt/MQTTConnectClient.c \
../icode/aliyun/mqtt/MQTTConnectServer.c \
../icode/aliyun/mqtt/MQTTDeserializePublish.c \
../icode/aliyun/mqtt/MQTTFormat.c \
../icode/aliyun/mqtt/MQTTPacket.c \
../icode/aliyun/mqtt/MQTTSerializePublish.c \
../icode/aliyun/mqtt/MQTTSubscribeClient.c \
../icode/aliyun/mqtt/MQTTSubscribeServer.c \
../icode/aliyun/mqtt/MQTTUnsubscribeClient.c \
../icode/aliyun/mqtt/MQTTUnsubscribeServer.c \
../icode/aliyun/mqtt/transport.c 

OBJS += \
./icode/aliyun/mqtt/MQTTConnectClient.o \
./icode/aliyun/mqtt/MQTTConnectServer.o \
./icode/aliyun/mqtt/MQTTDeserializePublish.o \
./icode/aliyun/mqtt/MQTTFormat.o \
./icode/aliyun/mqtt/MQTTPacket.o \
./icode/aliyun/mqtt/MQTTSerializePublish.o \
./icode/aliyun/mqtt/MQTTSubscribeClient.o \
./icode/aliyun/mqtt/MQTTSubscribeServer.o \
./icode/aliyun/mqtt/MQTTUnsubscribeClient.o \
./icode/aliyun/mqtt/MQTTUnsubscribeServer.o \
./icode/aliyun/mqtt/transport.o 

C_DEPS += \
./icode/aliyun/mqtt/MQTTConnectClient.d \
./icode/aliyun/mqtt/MQTTConnectServer.d \
./icode/aliyun/mqtt/MQTTDeserializePublish.d \
./icode/aliyun/mqtt/MQTTFormat.d \
./icode/aliyun/mqtt/MQTTPacket.d \
./icode/aliyun/mqtt/MQTTSerializePublish.d \
./icode/aliyun/mqtt/MQTTSubscribeClient.d \
./icode/aliyun/mqtt/MQTTSubscribeServer.d \
./icode/aliyun/mqtt/MQTTUnsubscribeClient.d \
./icode/aliyun/mqtt/MQTTUnsubscribeServer.d \
./icode/aliyun/mqtt/transport.d 


# Each subdirectory must supply rules for building sources it contributes
icode/aliyun/mqtt/%.o: ../icode/aliyun/mqtt/%.c icode/aliyun/mqtt/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-icode-2f-aliyun-2f-mqtt

clean-icode-2f-aliyun-2f-mqtt:
	-$(RM) ./icode/aliyun/mqtt/MQTTConnectClient.d ./icode/aliyun/mqtt/MQTTConnectClient.o ./icode/aliyun/mqtt/MQTTConnectServer.d ./icode/aliyun/mqtt/MQTTConnectServer.o ./icode/aliyun/mqtt/MQTTDeserializePublish.d ./icode/aliyun/mqtt/MQTTDeserializePublish.o ./icode/aliyun/mqtt/MQTTFormat.d ./icode/aliyun/mqtt/MQTTFormat.o ./icode/aliyun/mqtt/MQTTPacket.d ./icode/aliyun/mqtt/MQTTPacket.o ./icode/aliyun/mqtt/MQTTSerializePublish.d ./icode/aliyun/mqtt/MQTTSerializePublish.o ./icode/aliyun/mqtt/MQTTSubscribeClient.d ./icode/aliyun/mqtt/MQTTSubscribeClient.o ./icode/aliyun/mqtt/MQTTSubscribeServer.d ./icode/aliyun/mqtt/MQTTSubscribeServer.o ./icode/aliyun/mqtt/MQTTUnsubscribeClient.d ./icode/aliyun/mqtt/MQTTUnsubscribeClient.o ./icode/aliyun/mqtt/MQTTUnsubscribeServer.d ./icode/aliyun/mqtt/MQTTUnsubscribeServer.o ./icode/aliyun/mqtt/transport.d ./icode/aliyun/mqtt/transport.o

.PHONY: clean-icode-2f-aliyun-2f-mqtt

