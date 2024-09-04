################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../icode/aliyun/iot/iot.c 

OBJS += \
./icode/aliyun/iot/iot.o 

C_DEPS += \
./icode/aliyun/iot/iot.d 


# Each subdirectory must supply rules for building sources it contributes
icode/aliyun/iot/%.o: ../icode/aliyun/iot/%.c icode/aliyun/iot/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-icode-2f-aliyun-2f-iot

clean-icode-2f-aliyun-2f-iot:
	-$(RM) ./icode/aliyun/iot/iot.d ./icode/aliyun/iot/iot.o

.PHONY: clean-icode-2f-aliyun-2f-iot

