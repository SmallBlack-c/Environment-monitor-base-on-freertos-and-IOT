################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../icode/dht11/dht11.c 

OBJS += \
./icode/dht11/dht11.o 

C_DEPS += \
./icode/dht11/dht11.d 


# Each subdirectory must supply rules for building sources it contributes
icode/dht11/%.o: ../icode/dht11/%.c icode/dht11/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-icode-2f-dht11

clean-icode-2f-dht11:
	-$(RM) ./icode/dht11/dht11.d ./icode/dht11/dht11.o

.PHONY: clean-icode-2f-dht11

