################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/bma400.c 

OBJS += \
./Core/Inc/bma400.o 

C_DEPS += \
./Core/Inc/bma400.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/bma400.o: ../Core/Inc/bma400.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L071xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../examples -I../bma_400_files -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Inc/bma400.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

